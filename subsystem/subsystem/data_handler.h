#pragma once

#include "imodule.hpp"

struct data_handler : imodule, base_dynamic_creator<imodule, data_handler>
{
    data_handler();

    virtual bool init() override;
    virtual bool start() override;
    virtual void stop() override;
    virtual void uninit() override;
};
