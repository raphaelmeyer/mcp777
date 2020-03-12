#pragma once

#include <thread>

namespace io
{
class seven_segment;
} // namespace io

namespace mcp
{

class mcp777
{
public:
    mcp777(std::shared_ptr<io::seven_segment const> heading_select);

    void start();
    void shutdown();

private:
    std::shared_ptr<io::seven_segment const> _heading_select;
};

} // namespace mcp
