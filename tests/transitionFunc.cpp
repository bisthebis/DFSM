#include "catch.hpp"
#include <cctype>

TEST_CASE("isAlpha, isLower, isUpper, isDigit, isAlphaNum work properly", "[stdlib]")
{
    SECTION("isalpha works")
    {
        CHECK(isalpha('e'));
        CHECK(isalpha('W'));
        CHECK(isalpha('p'));
        CHECK_FALSE(isalpha('7'));
        CHECK_FALSE(isalpha('@'));
        CHECK_FALSE(isalpha('-'));
    }

    SECTION("islower works")
    {
        CHECK(islower('e'));
        CHECK_FALSE(islower('W'));
        CHECK(islower('p'));
        CHECK_FALSE(islower('7'));
        CHECK_FALSE(islower('@'));
        CHECK_FALSE(islower('-'));
    }

    SECTION("isupper works")
    {
        CHECK_FALSE(isupper('e'));
        CHECK(isupper('W'));
        CHECK_FALSE(isupper('p'));
        CHECK_FALSE(isupper('7'));
        CHECK_FALSE(isupper('@'));
        CHECK_FALSE(isupper('-'));
    }
    SECTION("isdigit works")
    {
        CHECK_FALSE(isdigit('e'));
        CHECK_FALSE(isdigit('W'));
        CHECK_FALSE(isdigit('p'));
        CHECK(isdigit('7'));
        CHECK_FALSE(isdigit('@'));
        CHECK_FALSE(isdigit('-'));
    }

    SECTION("isalnum works")
    {
        CHECK(isalnum('e'));
        CHECK(isalnum('W'));
        CHECK(isalnum('p'));
        CHECK(isalnum('7'));
        CHECK_FALSE(isalnum('@'));
        CHECK_FALSE(isalnum ('-'));
    }

}

TEST_CASE("Lambda correctly decay to function pointer", "[core]")
{
    auto lambda = [] (int x) -> int {return 2*x;};
    int (*funcPtr)(int) = lambda;
    CHECK(lambda(5) == funcPtr(5));
}
