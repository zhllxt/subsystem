#pragma once

#include "imodule.hpp"

struct json_data_publisher : imodule, base_dynamic_creator<imodule, json_data_publisher>
{
    json_data_publisher();

    virtual bool init() override;
    virtual bool start() override;
    virtual void stop() override;
    virtual void uninit() override;
};
