#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <mcp/mcp777.h>

#include <future>
#include <thread>

namespace
{

TEST_CASE("when shutdown() is called then MCP is stopped within a few seconds")
{
    const auto testee = std::make_unique<mcp::mcp777>();

    testee->start();

    auto exited = std::async(std::launch::async, [&] {
        testee->shutdown();
    });

    auto const result = exited.wait_for(std::chrono::seconds{1});
    CHECK(result == std::future_status::ready);

    exited.get();
}

} // namespace
