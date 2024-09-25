#include "http_data_publisher.h"
#include "module_dependencies.hpp"

http_data_publisher::http_data_publisher()
{
    module_dependencies::instance().add_dependency(this, "data_handler");
}

bool http_data_publisher::init()
{
    printf("http_data_publisher::init\n");
    return true;
}
bool http_data_publisher::start()
{
    printf("http_data_publisher::start\n");
    return true;
}
void http_data_publisher::stop()
{
    printf("http_data_publisher::stop\n");
}
void http_data_publisher::uninit()
{
    printf("http_data_publisher::uninit\n");
}
