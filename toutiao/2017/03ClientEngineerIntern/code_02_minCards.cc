#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using std::string;
using std::vector;
����Ϊһ�������ĸ�������Ҫ���Լ��ĵ�һ��ר���ˣ�
��ƻ���¼ n �׸����ÿ�׸�ĳ��ȶ��� s �룬
ÿ�׸������������¼��һ�� CD ���С�
ÿ�� CD ���������ȶ��� L �룬���������ٵñ�֤ͬһ�� CD ���������׸��м�����Ҫ�� 1 �롣
Ϊ�˱�а�����������һ�� CD �ڵĸ������ܱ� 13 �������������
��ô�����������ר��������Ҫ������ CD ��


��������:
ÿ���������������һ�����ݣ�ÿ�����ݵ�һ��Ϊ���������� n, s, L�� 
��֤ n �� 100 , s �� L �� 10000 


�������:
���һ������������������Ҫ�� CD ������


��������1:
7 2 6

�������1:
4

int MinCards(int n, int s, int l)
{
	int num = l / s;
    int rest = l % s;
	int rN = s * num + num - 1 - rest; //�һ���Ҫ��ô��ʱ��洢
	while (rN >= l || num % 13 == 0) //rN >= lҲû�д� ���൱���ڵ�һ��Ƭ���ٴ���
	{
		--num;
        rN = s * num + num - 1 - rest;
	}
    if (num < 0)
    {
        return 1;
    }
    if (n < num && n % 13 == 0)
    {
        return 2;
    }
	return n / num + (n % num == 0 ? 0 : 1);
}

//�ߵ���ĿӦ���������� Ҫ��n/num���µ�ֵ�ܲ��ܱ�13���� �����Ҫ����2����Ƭ��
int main(void)
{	
	int n;
	int s;
	int l;
	std::cin >> n >> s >> l;
	std::cout << MinCards(n, s, l) << std::endl;

	return 0;
}