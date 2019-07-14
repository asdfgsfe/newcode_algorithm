#include <stdio.h>
#include <iostream>
#include <vector>

using std::vector;

//o(n*n) �������ֱ���������ķ��� ��i��β��������
int MaxPartMinMultiSum(vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	int maxVal = 0x80000000;
	for (int i = 0; i < numbers.size(); ++i)
	{
		int curMin = numbers[i];
        int curSum = 0;
		for (int j = i; j >= 0; --j)
		{
			curMin = std::min(curMin, numbers[j]);
            curSum += numbers[j];
			maxVal = std::max(maxVal, curMin * curSum);
		}
	}
	return maxVal;
}

//����ջ ��߱���С���ұ߱���С��
//�����ⷨ�� ��ÿ��λ��Ϊ��С
int MaxPartMinMultiSum2(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	vector<int> sums(numbers.size());
	sums[0] = numbers[0];
	for (int i = 1; i < numbers.size(); ++i)
	{
		sums[i] = sums[i - 1] + numbers[i];
	}
	stack<int> incrIndexs;
	int maxVal = 0x80000000;
	for (int i = 0; i < numbers.size(); ++i)
	{
		while (!incrIndexs.empty() && numbers[i] <= numbers[incrIndexs.top()])
		{
			int curNum = numbers[incrIndexs.top()];
			incrIndexs.pop();
			int curSum = incrIndexs.empty() ? sums[i - 1] : sums[i - 1] - sums[incrIndexs.top()];
			maxVal = std::max(maxVal, curSum * curNum);
		}
		incrIndexs.push(i);

	}
	return maxVal;
}


int main(void)
{
	int len;
	scanf("%d", &len);
	vector<int> numbers(len);
	for (int i = 0; i < len; ++i)
	{
		scanf("%d", &numbers[i]);
	}
	//std::cout << MaxPartMinMultiSum(numbers) << std::endl;
	 printf("%d\n", MaxPartMinMultiSum(numbers));
	
	return 0;
}
