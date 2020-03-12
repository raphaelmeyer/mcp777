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
    GIVEN("heading is set to 157")
    {
        auto const display = std::make_shared<seven_segment_mock>();
        auto const testee = std::make_unique<mcp::mcp777>(display);

        THEN("Heading Select should display HDG 157")
        {
            REQUIRE_CALL(*display, set())
                .TIMES(AT_LEAST(1));
        }
    }
}

} // namespace
