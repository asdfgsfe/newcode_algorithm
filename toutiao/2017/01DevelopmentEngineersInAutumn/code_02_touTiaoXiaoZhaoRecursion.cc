#include <assert.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

int AddProcess(const vector<int>& nums, int i)
{
	if (i == nums.size())
	{
		return 0;
	}
    int addNum = 0x7fffffff;
	if (i + 1 < nums.size() && nums[i + 1] - nums[i] <= 10)
	{
		addNum = std::min(addNum, 1 + AddProcess(nums, i + 2));
	}
	if (i + 2 < nums.size() && nums[i + 1] - nums[i] <= 10 && nums[i + 2] - nums[i + 1] <= 10)
	{
		addNum = std::min(addNum, AddProcess(nums, i + 3));
	}
	addNum = std::min(addNum, 2 + AddProcess(nums, i + 1));
	return addNum;
}

int AddMinNum(vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}
    std::sort(nums.begin(), nums.end());
	return AddProcess(nums, 0);
}
	
//过百分之40 超时
int main(void)
{
	int n;
	scanf("%d", &n);
	vector<int> nums(n);
	for (int i = 0; i < nums.size(); ++i)
	{
		scanf("%d", &nums[i]);
	}
	printf("%d\n", AddMinNum(nums));
	return 0;
}