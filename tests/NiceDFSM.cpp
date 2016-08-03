#include "catch.hpp"
#include "NiceDFSM.h"

TEST_CASE("Nice is correctly parsed", "[niceDFSM]")
{
	NiceDFSM machine;

	CHECK(machine.parse("nice"));
	CHECK_FALSE(machine.parse("Nice"));
    CHECK_FALSE(machine.parse("nicee"));
}
