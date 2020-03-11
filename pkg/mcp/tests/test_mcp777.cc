#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <doctest/trompeloeil.hpp>

#include <mcp/mcp777.h>

#include <future>
#include <thread>

namespace
{

class seven_segment_mock
{
public:
    MAKE_MOCK1(set, void(std::array<std::byte, 4>));
};

SCENARIO("Display heading" * doctest::should_fail())
{
    GIVEN("heading is set to 157")
    {
        seven_segment_mock display;

        const auto testee = std::make_unique<mcp::mcp777>();
        testee->start();

        THEN("Heading Select should display HDG 157")
        {
            REQUIRE_CALL(display, set(trompeloeil::_))
                .TIMES(AT_LEAST(1));
        }

        testee->shutdown();
    }
}

} // namespace
