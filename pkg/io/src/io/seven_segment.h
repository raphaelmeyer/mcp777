#pragma once

namespace io
{

class seven_segment
{
public:
    virtual ~seven_segment() = default;

    virtual void set() const = 0;
};

} // namespace io
