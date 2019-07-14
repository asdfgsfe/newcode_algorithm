#include <stdio.h>
#include <iostream>
#include <vector>

using std::vector;

//o(n*n) 掌握这种遍历子数组的方法 以i结尾的子数组
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

//单调栈 左边比他小的右边比他小的
//暴力解法是 以每个位置为最小
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
