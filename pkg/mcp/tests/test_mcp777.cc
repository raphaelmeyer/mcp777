#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <doctest/trompeloeil.hpp>

#include <mcp/mcp777.h>

#include <io/seven_segment.h>

#include <future>
#include <thread>

namespace
{

class seven_segment_mock : public io::seven_segment
{
public:
    MAKE_CONST_MOCK0(set, void(), override);
};

SCENARIO("Display heading" * doctest::should_fail())
{
    GIVEN("a 4 digit 7 segment display for Heading Select")
    {
        // TODO
        // replace seven_segment_mock with spy
        // in order to check state instead of
        // interaction
        auto const display = std::make_shared<seven_segment_mock>();
        auto const testee = std::make_unique<mcp::mcp777>(display);

        WHEN("there is an update event with Heading 157")
        {
            // send event {Mode: HDG, Angle: 157}

            THEN("the top segment of the left most digit should be on to indicate Mode Heading")
            {
                // TODO check left digit -> A on, other off

                AND_THEN("the 3 digits to the right should display 1 5 7")
                {
                    // TODO replace
                    REQUIRE_CALL(*display, set())
                        .TIMES(AT_LEAST(1));

                    // check other digits
                }
            }
        }

        WHEN("there is an update event with Tracking 243")
        {
            // ...
        }
    }
}

} // namespace
