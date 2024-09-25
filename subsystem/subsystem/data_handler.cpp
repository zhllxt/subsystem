#include "data_handler.h"
#include "module_dependencies.hpp"

data_handler::data_handler()
{
    module_dependencies::instance().add_dependency(this, "udp_data_recver");
    module_dependencies::instance().add_dependency(this, "tcp_data_recver");
}

bool data_handler::init()
{
    printf("data_handler::init\n");
    return true;
}
bool data_handler::start()
{
    printf("data_handler::start\n");
    return true;
}
void data_handler::stop()
{
    printf("data_handler::stop\n");
}
void data_handler::uninit()
{
    printf("data_handler::uninit\n");
}
