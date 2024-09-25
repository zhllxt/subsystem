#include "module_mgr.hpp"

int main()
{
    // 构造模块管理类的对象
    module_mgr mmgr;

    // 启动时要对各个模块进行正向排序
    mmgr.sort(true);

    // 然后依次调用初始化，启动等函数：
    mmgr.init();

    mmgr.start();

    // 如果按下回车键，程序退出
    while (std::getchar() != '\n');

    // 停止时要对各个模块进行逆向排序
    mmgr.sort(false);

    // 程序准备退出了，开始停止和卸载所有的模块
    mmgr.stop();

    mmgr.uninit();

	return 0;
}
