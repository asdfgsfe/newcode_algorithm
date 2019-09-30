#include <stdio.h>
#include <iostream>
#include <vector>

using std::vector;

//o(n*n) 掌握这种遍历子数组的方法 以i结尾的子数组 
//其实就是dp的思想o(n * n) 以每个位置结尾的情况怎么怎么样
//通解 适合任何数据类型 正数 负数的情况
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
//暴力解法是 以每个位置为最小向两边扩
int MaxPartMinMultiSum2(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	vector<int> sums(numbers.size());
	sums[0] = numbers[0];
	for (int i = 1; i < numbers.size(); ++i) //这个地方还可以优化掉
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

//将域处理数组部分 降到计算单调栈里面
//这种边遍历 边求结果的方法很好
//由于数组中的值全是正数 所以累加和一定是正数 而且只要累加就在变大 所以乘积最大的瓶颈在于这个最小值的选取
//把每个位置当做最小值去尝试 找到左边离他最近比他小的 右边离他最近比他小的 这段区间就能利用单调栈
int MaxPartMinMultiSum2(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	vector<int> sums(numbers.size());
	sums[0] = numbers[0];
	stack<int> incrIndexs;
	int maxVal = 0x80000000;
	for (int i = 0; i < numbers.size(); ++i)
	{
		sums[i] = i > 0 ? sums[i - 1] + nums[i] : sums[i];
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
