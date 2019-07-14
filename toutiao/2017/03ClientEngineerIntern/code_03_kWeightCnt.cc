#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using std::string;
using std::vector;

���� n ���ַ���������ÿ�� n ������ p��
�����и�����˳��(p[0] , p[1] �� p[n-1])
���������� n ���ַ������ܵõ�һ������Ϊ��Щ�ַ�������֮�͵��ַ�����
���԰����������һ���������� n! ���ַ�����

һ���ַ�����Ȩֵ���ڰ�����ַ���ѭ������ i �κ�õ����ַ����Ժ�ԭ�ַ���ȫ�ȵ�������
i ��ȡֵΪ [1 , �ַ�������]������Щ�ַ���������ɵ� n! ���ַ�����ȨֵΪ K ���ж��ٸ���

ע�������һ����ѭ������ 1 �εȼ��ڰ�������ĵ�һ���ַ��ƶ������һ���ַ��ĺ��档


��������:
ÿ���������������һ�����ݣ�
ÿ�����ݵ�һ��Ϊ���������� n, K �� n �Ĵ�С������ 8 �� K ������ 200���������� n �У�
ÿ��һ�����Ȳ����� 20 �ҽ�������д��ĸ���ַ�����


�������:
���һ����������ȨֵΪ K ���ַ���������


��������1:
3 2
AB
RAAB
RA

�������1:
3

int ComputeWeight(const vector<string>& strs, int k)
{
    int kWeightCnt = 1;
    string base;
	for (const auto& str : strs)
	{
        base.append(str);
	}
    string tmp = base + base;
    for (int i = 1; i < base.size(); ++i)
    {
        if (base[0] == base[i])
        {
            //substr��ʱ�临�Ӷ������Ե� ��������ѭ��ȥ�ж��ַ�����λ�ķ���
			kWeightCnt += (base == tmp.substr(i, base.size())) ? 1 : 0;
        }
    }
  return kWeightCnt == k ? 1 : 0;
}


int KWeightCnt(vector<string>& strs, int i, int k)
{
	if (i == strs.size())
	{
		return ComputeWeight(strs, k);
	}
	int cnt = 0;
	for (int s = i; s < strs.size(); ++s)
	{
		std::swap(strs[s], strs[i]);
		cnt += KWeightCnt(strs, i + 1, k);
		std::swap(strs[s], strs[i]);
	}
	return cnt;
}

int main(void)
{	
	int n;
	int k;
	std::cin >> n >> k;
	vector<string> strs(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> strs[i];
	}
	std::cout << KWeightCnt(strs, 0, k) << std::endl;

	return 0;
}