#pragma once

#include "imodule.hpp"

struct tcp_data_recver : imodule, base_dynamic_creator<imodule, tcp_data_recver>
{
    tcp_data_recver();

    virtual bool init() override;
    virtual bool start() override;
    virtual void stop() override;
    virtual void uninit() override;
};
