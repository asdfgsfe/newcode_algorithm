#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using std::vector;
using std::string;


有 n 个字符串，每个字符串都是由 A-J 的大写字符构成。
现在你将每个字符映射为一个 0-9 的数字，不同字符映射为不同的数字。
这样每个字符串就可以看做一个整数，
唯一的要求是这些整数必须是正整数且它们的字符串不能有前导零。
现在问你怎样映射字符才能使得这些字符串表示的整数之和最大？


输入描述:
每组测试用例仅包含一组数据，每组数据第一行为一个正整数 n ， 
接下来有 n 行，每行一个长度不超过 12 且仅包含大写字母 A-J 的字符串。 
n 不大于 50，且至少存在一个字符不是任何字符串的首字母。


输出描述:
输出一个数，表示最大和是多少。

示例1
输入
2
ABC
BCA
输出
1875

//将字符abcdefghij映射为0 ~ 9数字 让字符adcdefghij位置固定不变，变换0~9数字与之去匹配
//在首字母不能是0的情况下 最终选出累加和最大的
//生成0~9的全排列 就是字符映射成数值的所有情况
//在所有全排列中排除首字母为0的 然后去计算每种情况下的累加和 选出最大的
//超时 这种思想只能过百分之30
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
