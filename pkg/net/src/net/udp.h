#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <variant>

namespace net
{

struct error
{
};

class connection
{
public:
    connection() = default;
    connection(connection &&) = default;
    connection &operator=(connection &&) = default;

    virtual ~connection() = default;

    connection(connection const &) = delete;
    connection &operator=(connection const &) = delete;

    virtual std::variant<std::string, error> receive() const = 0;
    // virtual void send(std::string data) const = 0;
};

std::unique_ptr<connection> udp_server(std::uint16_t port);

} // namespace net
