#include "udp_data_recver.h"
#include "module_dependencies.hpp"

udp_data_recver::udp_data_recver()
{
}

bool udp_data_recver::init()
{
    printf("udp_data_recver::init\n");
    return true;
}
bool udp_data_recver::start()
{
    printf("udp_data_recver::start\n");
    return true;
}
void udp_data_recver::stop()
{
    printf("udp_data_recver::stop\n");
}
void udp_data_recver::uninit()
{
    printf("udp_data_recver::uninit\n");
}
