#include "catch.hpp"
#include "include/NiceDFSM.h"

TEST_CASE("Nice is correctly parsed", "[niceDFSM]")
{
	NiceDFSM machine;

	REQUIRE(machine.parse("nice"));
	REQUIRE_FALSE(machine.parse("Nice"));

}
