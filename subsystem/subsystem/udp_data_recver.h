#pragma once

#include "imodule.hpp"

struct udp_data_recver : imodule, base_dynamic_creator<imodule, udp_data_recver>
{
    udp_data_recver();

    virtual bool init() override;
    virtual bool start() override;
    virtual void stop() override;
    virtual void uninit() override;
};
