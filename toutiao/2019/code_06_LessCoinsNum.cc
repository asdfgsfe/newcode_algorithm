#include <stdio.h>
#include <vector>

using std::vector;

int LessCoinNum(int n)
{
    if (n <= 0 || n >= 1024)
    {
        return 0;
    }
    int aim = 1024 - n;
    int cnt = 0;
    cnt += aim / 64;
    aim %= 64;
    cnt += aim / 16;
    aim %= 16;
    cnt += aim / 4;
    aim %= 4;
    cnt += aim / 1;
    
    return cnt;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", LessCoinNum(n));
    
    return 0;
}

Z���Ļ���ϵͳ������ֵ1Ԫ��4Ԫ��16Ԫ��64Ԫ����4��Ӳ�ң��Լ���ֵ1024Ԫ��ֽ�ҡ�
����СYʹ��1024Ԫ��ֽ�ҹ�����һ����ֵΪ����Ʒ���������������յ�����Ӳ�ң�

��������:
һ�У�����һ����N��

�������:
һ�У�����һ��������ʾ�����յ���Ӳ������

��������1:
200

�������1:
17

����˵��1:
��200����Ҫ����824�飬��12��64ԪӲ�ң�3��16ԪӲ�ң�2��4ԪӲ�Ҽ��ɡ�