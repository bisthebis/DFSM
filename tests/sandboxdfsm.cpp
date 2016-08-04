#include "catch.hpp"
#include "sandboxdfsm.h"

#include <cctype>

TEST_CASE("SandboxDFSM work for trivial models", "[Sandbox]")
{
    //Machine 1 : accepts alphanum, but must end with letter
    //State 0 -> if input is digit, goto 1, if it is letter, goto 2, else -1
    //State 1 -> if input is digit, goto 1, if it is letter, goto 2, else -1
    //State 2 -> if input is digit, goto 1, if it is letter, goto 2, else -1 ==> ACCEPTING STATE
    auto machine1Lambda = [](int x) {if(isdigit(x)) return 1; else if (isalpha(x)) return 2; else return -1;};

    SandboxDFSM machine1({
                             SandboxedState(machine1Lambda, false),
                             SandboxedState(machine1Lambda, false),
                             SandboxedState(machine1Lambda, true)
                         });
    CHECK(machine1.parse("ikfhsdfhjZJHKF23545fdzA"));
    CHECK_FALSE(machine1.parse("ikfhsdfhj$ZJHKF23545fdzA"));
    CHECK_FALSE(machine1.parse("ikfhsdfhjZJHKF23545fdzA5"));

    //Machine 2 : Starts with Uppercase, ends with a number, can only have lowercases in between.
    //State 0 -> First letter must be uppercase -> goto 1 or -1
    //State 1 -> if lowercase, loop itself. If digit, goto 2. If neither lower or digit, -1
    //State 2 -> Final state, always return -1

    SandboxDFSM machine2({
                             SandboxedState([](int x) {return isupper(x) ? 1 : -1;}, false),
                             SandboxedState([](int x) {if (islower(x)) return 1; else return isdigit(x) ? 2 : -1;}, false),
                             SandboxedState([](int x) {return -1;}, true)
                         });
    CHECK(machine2.parse("Azerrtyuy5"));
    CHECK_FALSE(machine2.parse("Azerrtyuy"));
    CHECK_FALSE(machine2.parse("Azerrtyuy57"));

    //Machine 3 : Parsing a nomber. Most complex form : "-538.3879".
    //Starts with +, - or a digit, can contain arbitrary large number of digits, and can have at most one floating separator (dot or comma)
    //State 0 -> Goto 2 if digit, 1 if '+' or '-', else -1
    //State 1 : Just after +|-. Requires a digit to go to 2, else -1
    //State 2 : integer part, loop itself for all digits, goto 3 for '.' or ',', else -1. ACCEPTING
    //State 3 : Just after dot or comma. Requires a digit to go to 4, else -1
    //State 4 : Loop is digit, else -1


    SandboxDFSM machine3({
                             SandboxedState([](int x) {if (isdigit(x)) return 2; if (x == '+' || x == '-') return 1; else return -1;}, false),
                             SandboxedState([](int x) {return isdigit(x) ? 2 : -1;}, false),
                             SandboxedState([](int x) {if (isdigit(x)) return 2; else if (x == '.' || x == ',') return 3; else return -1;}, true),
                             SandboxedState([](int x) {return isdigit(x) ? 4 : -1;}, false),
                             SandboxedState([](int x) {return isdigit(x) ? 4 : -1;}, true)
                         }

                );

    CHECK(machine3.parse("+53564.25464"));
    CHECK(machine3.parse("19999,0"));
    CHECK(machine3.parse("-5"));
    CHECK_FALSE(machine3.parse("-.50"));
    CHECK_FALSE(machine3.parse("+0747."));

}
