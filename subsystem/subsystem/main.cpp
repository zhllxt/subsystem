#include "module_mgr.hpp"

int main()
{
    // ����ģ�������Ķ���
    module_mgr mmgr;

    // ����ʱҪ�Ը���ģ�������������
    mmgr.sort(true);

    // Ȼ�����ε��ó�ʼ���������Ⱥ�����
    mmgr.init();

    mmgr.start();

    // ������»س����������˳�
    while (std::getchar() != '\n');

    // ֹͣʱҪ�Ը���ģ�������������
    mmgr.sort(false);

    // ����׼���˳��ˣ���ʼֹͣ��ж�����е�ģ��
    mmgr.stop();

    mmgr.uninit();

	return 0;
}
