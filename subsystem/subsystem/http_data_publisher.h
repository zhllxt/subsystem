#pragma once

#include "imodule.hpp"

struct http_data_publisher : imodule, base_dynamic_creator<imodule, http_data_publisher>
{
    http_data_publisher();

    virtual bool init() override;
    virtual bool start() override;
    virtual void stop() override;
    virtual void uninit() override;
};
