#include "tcp_data_recver.h"
#include "module_dependencies.hpp"

tcp_data_recver::tcp_data_recver()
{
}

bool tcp_data_recver::init()
{
    printf("tcp_data_recver::init\n");
    return true;
}
bool tcp_data_recver::start()
{
    printf("tcp_data_recver::start\n");
    return true;
}
void tcp_data_recver::stop()
{
    printf("tcp_data_recver::stop\n");
}
void tcp_data_recver::uninit()
{
    printf("tcp_data_recver::uninit\n");
}
