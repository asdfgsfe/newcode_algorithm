#include <stdio.h>
#include <iostream>
#include <vector>

using std::vector;

int CostProcess(int pre, int& start, vector<bool>& visited, const vector<vector<int>>& costs)
{
	visited[pre] = true;
	int cost = 0x7fffffff;
	for (int next = 0; next < visited.size(); ++next)
	{
		if (!visited[next])
		{
			cost = std::min(cost, CostProcess(next, start, visited, costs) + costs[pre][next]);
		}
	}
	visited[pre] = false;
	return cost == 0x7fffffff ? costs[pre][start] : cost;
}

//通过visited判断是否走完所有路径 传入start记录本次尝试最先开始的位置
//本次最先开始的位置 与本次最后一个到的城市之间构成 回去
//缺点在于没法 完整的记录这次尝试所经过城市的完整路径
//递归转dp一定要用dp能表达递归的所有过程才行
//如果递归的变化参数是一个数组之类的 但是这个数组又不大 想到用位操作记录这个递归的过程来dp
//位操作作为行 相当于visited 然后递归的内容不变
int MinCost(int n, const vector<vector<int>>& costs)
{
	if (n < 1 || costs.empty() || costs[0].empty())
	{
		return 0;
	}
	int cost = 0x7fffffff;
	for (int i = 0; i < n; ++i)
	{
		vector<bool> visited(n, false);
		cost = std::min(cost, CostProcess(i, i, visited, costs));
	}
	return cost;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> costs(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &costs[i][j]);
        }
    }
    printf("%d\n", MinCost(n, costs));
    
    return 0;
}