#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int PushProcess(const vector<string>& mapping, int si, int sj, int ei, int ej, 
vector<vector<bool>>& visited, vector<vector<int>>& dp)
{
	int n = mapping.size();
	int m = mapping.front().size();
	if (si < 0 || si >= n || sj < 0 || sj >= m || visited[si][sj] || mapping[si][sj] == '#')
	{
		return 0x7fffffff;
	}
	visited[si][sj] = true;
	if (si == ei && sj == ej)
	{
		visited[si][sj] = false;
		return 0;
	}
	if (dp[si][sj] == 0x7fffffff)
	{
		dp[si][sj] = std::min(dp[si][sj], PushProcess(mapping, si + 1, sj, ei, ej, visited, dp));
		dp[si][sj] = std::min(dp[si][sj], PushProcess(mapping, si - 1, sj, ei, ej, visited, dp));
		dp[si][sj] = std::min(dp[si][sj], PushProcess(mapping, si, sj + 1, ei, ej, visited, dp));
		dp[si][sj] = std::min(dp[si][sj], PushProcess(mapping, si, sj - 1, ei, ej, visited, dp));
	}
	visited[si][sj] = false;
	dp[si][sj] = dp[si][sj] == 0x7fffffff ? dp[si][sj] : dp[si][sj] + 1;
	return dp[si][sj];
}

int PushPackage(vector<string>& mapping)
{
	vector<int> s(2, -1);
	vector<int> o(2, -1);
	vector<int> e(2, -1);
	for (int i = 0; i < mapping.size(); ++i)
	{
		for (int j = 0; j < mapping.front().size(); ++j)
		{
			if (mapping[i][j] == 'S')
			{
				s[0] = i;
				s[1] = j;
			}
			if (mapping[i][j] == '0')
			{
				o[0] = i;
				o[1] = j;
			}
			if (mapping[i][j] == 'E')
			{
				e[0] = i;
				e[1] = j;
			}
		}
	}
	if (s[0] == -1 || s[1] == -1 || o[0] == -1 || o[1] == -1 || e[0] == -1 || e[1] == -1)
	{
		return -1;
	}

	vector<vector<int>> dp(mapping.size() + 1, vector<int>(mapping.front().size() + 1, 0x7fffffff));
	vector<vector<int>> dp2 = dp;
	vector<vector<bool>> visited(mapping.size(), vector<bool>(mapping.front().size(), false));
	int so = PushProcess(mapping, s[0], s[1], o[0], o[1], visited, dp); 
	if (so == 0x7fffffff)
	{
		return -1;
	}
	so += PushProcess(mapping, o[0], o[1], e[0], e[1], visited, dp2);
	return so != 0x7fffffff ? so: -1;
}

int main(void)
{
	int n;
	int m;
	std::cin >> n >> m;
	vector<string> mapping(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> mapping[i];
	}
	std::cout << PushPackage(mapping) << std::endl;

	return 0;
}