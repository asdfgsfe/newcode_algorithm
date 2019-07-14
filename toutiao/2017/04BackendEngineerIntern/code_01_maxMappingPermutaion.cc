#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using std::vector;
using std::string;


�� n ���ַ�����ÿ���ַ��������� A-J �Ĵ�д�ַ����ɡ�
�����㽫ÿ���ַ�ӳ��Ϊһ�� 0-9 �����֣���ͬ�ַ�ӳ��Ϊ��ͬ�����֡�
����ÿ���ַ����Ϳ��Կ���һ��������
Ψһ��Ҫ������Щ���������������������ǵ��ַ���������ǰ���㡣
������������ӳ���ַ�����ʹ����Щ�ַ�����ʾ������֮�����


��������:
ÿ���������������һ�����ݣ�ÿ�����ݵ�һ��Ϊһ�������� n �� 
�������� n �У�ÿ��һ�����Ȳ����� 12 �ҽ�������д��ĸ A-J ���ַ����� 
n ������ 50�������ٴ���һ���ַ������κ��ַ���������ĸ��


�������:
���һ��������ʾ�����Ƕ��١�

ʾ��1
����
2
ABC
BCA
���
1875

//���ַ�abcdefghijӳ��Ϊ0 ~ 9���� ���ַ�adcdefghijλ�ù̶����䣬�任0~9������֮ȥƥ��
//������ĸ������0������� ����ѡ���ۼӺ�����
//����0~9��ȫ���� �����ַ�ӳ�����ֵ���������
//������ȫ�������ų�����ĸΪ0�� Ȼ��ȥ����ÿ������µ��ۼӺ� ѡ������
//��ʱ ����˼��ֻ�ܹ��ٷ�֮30
long long ComputeMappingSum(const vector<int>& digits, const vector<string>& strs)
{
	//abcdefghij ~ digitsIdx(0 ~ 9)
	assert(digits.size() == 10 && !strs.empty());
	int zeroIdx = -1;
	for (int i = 0; i < digits.size(); ++i)
	{
		zeroIdx = digits[i] == 0 ? i : -1;
	}
	//assert(zeroIdx != -1);
	for (const auto& str : strs)
	{
		if (str[0] - 'A' == zeroIdx)
		{
			return -1;
		}
	}
	long long sum = 0;
	for (const auto& str : strs)
	{
		long long num = 0;
		for (char ch : str)
		{
			num = num * 10 + digits[ch - 'A'];
		}
		sum += num;
	}
	return sum;
}

long long MappingProcess(vector<int>& digits, int i, const vector<string>& strs)
{
	if (i == digits.size())
	{
		return ComputeMappingSum(digits, strs);
	}
	long long maxSum = 0;
	for (int s = i; s < digits.size(); ++s)
	{
		std::swap(digits[s], digits[i]);
		maxSum = std::max(maxSum, MappingProcess(digits, i + 1, strs));
    std::swap(digits[s], digits[i]);
	}
	return maxSum;
}

long long MaxMapping(const vector<string>& strs)
{
	vector<int> digits(10);
	for (int i = 0; i < 10; ++i)
	{
		digits[i] = i;
	}
	return MappingProcess(digits, 0, strs);
}


int main(void)
{
	int n;
	std::cin >> n;
	vector<string> strs(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> strs[i];
	}
	std::cout << MaxMapping(strs) << std::endl;

	return 0;
}
