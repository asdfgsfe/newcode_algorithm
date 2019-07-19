#include <assert.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

int NoLegalColorNum(const string& str, int m)
{
	if (str.empty())
	{
		return 0;
	}
	vector<vector<int>> charIdxs(26, vector<int>());
	for (int i = 0; i < str.size(); ++i)
	{
		charIdxs[str[i] - 'a'].emplace_back(i);
	}
	int cnt = 0;
	for (const auto& idx : charIdxs)
	{
		std::sort(idx.begin(), idx.end());
		int lnum = 0;
		int rnum = 0;
		int len = 0;
		int times = m;
		for (int i = 0; i < idx.size(); ++i)
		{
			int lcur = i - 1;
			int rcur = i + 1;
			while (cur >=0 && cur < idx.size() && times > 0)
			{
				int span = std::min(idx[lcur] - idx[cur], idx[rcur] - idx[cur]);
				time -= span;
				++;
				if (idx[cur] - idx[lcur] > idx[rcur] - idx[cur])
				{
					time -= idx[rcur] - idx[cur] - rnum;
					++rcur;
					++rnum;
				}
				else
				{
					time -= idx[cur] - idx[lcur] - lnum;
					--lcur;
					++lnum;
				}
				++len;
			}
		}
		cnt = std::max(cnt, num);
	}
	return cnt;
}

int main(void)
{
	string str;
	int n;
	std::cin >> str >> n;
	NoLegalColorNum(str, n);

	return 0;
}