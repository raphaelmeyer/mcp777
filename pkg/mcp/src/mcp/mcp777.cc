#include "mcp777.h"

#include <net/udp.h>

#include <iostream>

namespace mcp
{

mcp777::mcp777(std::shared_ptr<io::seven_segment const> heading_select)
    : _heading_select{heading_select} {}

void mcp777::start()
{
    /* spike
    auto const fg_out = net::udp_server(7770);
    // auto const fg_in = net::udp_client("localhost", 7771);

    auto const result = fg_out->receive();
    if (std::holds_alternative<net::error>(result))
    {
        return;
    }

    std::cout << std::get<std::string>(result) << "\n";

    // fg_in.send("240;157;15000");
    */
}

void mcp777::shutdown()
{
}

} // namespace mcp
