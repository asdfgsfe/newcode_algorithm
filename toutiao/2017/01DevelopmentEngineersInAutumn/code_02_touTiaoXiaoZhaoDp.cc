#include <assert.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

int AddMinNumDp(vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}
    std::sort(nums.begin(), nums.end());
	vector<int> dp(nums.size() + 1, 0x7fffffff);
	dp.back() = 0;
	for (int i = dp.size() - 2; i >= 0; --i)
	{
		if (i + 1 < nums.size() && nums[i + 1] - nums[i] <= 10)
		{
			dp[i] = std::min(dp[i], 1 + dp[i + 2]);
		}
		if (i + 2 < nums.size() && nums[i + 1] - nums[i] <= 10 && nums[i + 2] - nums[i + 1] <= 10)
		{
			dp[i] = std::min(dp[i], dp[i + 3]);
		}
		dp[i] = std::min(dp[i], 2 + dp[i + 1]);
	}
	return dp[0];
}
	
int main(void)
{
	int n;
	scanf("%d", &n);
	vector<int> nums(n);
	for (int i = 0; i < nums.size(); ++i)
	{
		scanf("%d", &nums[i]);
	}
	printf("%d\n", AddMinNumDp(nums));
	return 0;
}