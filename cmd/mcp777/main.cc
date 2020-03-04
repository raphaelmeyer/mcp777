#include <mcp/mcp777.h>

#include <memory>

int main()
{
    auto const mcp = std::make_unique<mcp::mcp777>();

    mcp->start();

    // exit = os::notify_quit();
    // exit.get();

    mcp->shutdown();
}
