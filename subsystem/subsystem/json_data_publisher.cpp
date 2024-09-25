#include "json_data_publisher.h"
#include "module_dependencies.hpp"

json_data_publisher::json_data_publisher()
{
    module_dependencies::instance().add_dependency(this, "data_handler");
}

bool json_data_publisher::init()
{
    printf("json_data_publisher::init\n");
    return true;
}
bool json_data_publisher::start()
{
    printf("json_data_publisher::start\n");
    return true;
}
void json_data_publisher::stop()
{
    printf("json_data_publisher::stop\n");
}
void json_data_publisher::uninit()
{
    printf("json_data_publisher::uninit\n");
}
