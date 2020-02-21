#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int LonggestSameChar(const string& str, int m)
{
	if (str.empty())
	{
		return 0;
	}
	vector<vector<int>> charToIdxs(str.size());
	for (int i = 0; i < str.size(); ++i)
	{
		charToIdxs[str[i] - 'a'].emplace_back(i);
	}
	int longgest = 0;
	for (const auto& idxs : charToIdxs)
	{
        vector<vector<int>> dp(idxs.size(), vector<int>(idxs.size(), 0));
		for (int i = dp.size() - 2; i >= 0; --i)
		{
			for (int j = dp[0].size() - 1; j >= i; --j)
			{
				dp[i][j] = dp[i + 1][j - 1] + (idxs[j] - idxs[i] - 1) - (j - i - 1);
				longgest = dp[i][j] <= m ? std::max(longgest, j - i + 1) : longgest;
			}
		}
	}
	return longgest;
}

//只能ac 95一个例子过不去 感觉是初始化的问题
//zoiumptccefmqdrjhhlgeyljbofwgvwogmvmpzgmoxdrbfdggimzifpfqmrqnrqrlobhluunzhyxrsicdhsrxpsrurqrewvrrcqc 200
//对应输出应该为:
//12
//你的输出为:
//11
int main(void)
{
	string str;
	int m;
    std::cin >> str >> m;
    printf("%d\n", LonggestSameChar(str, m));

	return 0;
}
