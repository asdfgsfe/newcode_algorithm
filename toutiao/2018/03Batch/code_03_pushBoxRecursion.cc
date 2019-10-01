#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::vector;
//其实是dfs的思想 暴力遍历
const vector<std::pair<int, int>> direc = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
int PushProcess(const vector<string>& mapping, 
				vector<vector<vector<vector<bool>>>>& visited, 
				int sX, int sY,
				int bX, int bY)
{
	if (sX < 0 
		|| sX >= mapping.size() 
		|| sY < 0 
		|| sY >= mapping[0].size() 
		|| mapping[sX][sY] == '#' 
		|| visited[sX][sY][bX][bY]
		|| (sX == bX && sY == bY && mapping[bX][bY] == 'E'))
	{
		return 0;
	}
	visited[sX][sY][bX][bY] = true;
	int steps = 0x7fffffff;
	for (int i = 0; i < 4; ++i)
	{
		sX = sX + direc[i].first;
		sY = sY + direc[i].second;
		if (sX == bX && sY == bY)
		{
			bX = bX + direc[i].first;
			bY = bY + direc[i].second;
		}
		steps = std::min(steps, PushProcess(mapping, visited, sX,sY, bX, bY));
	}
	return steps + 1;
}

int ToTargetMinSteps(const vector<string>& mapping, int n, int m)
{
	if (mapping.empty() || mapping[0].empty())
	{
		return -1;
	}
	int sX = -1;
	int sY = -1;
	int bX = -1;
	int bY = -1;
	int eX = -1;
	int eY = -1;
	for (int i = 0; i < mapping.size(); ++i)
	{
		for (int j = 0; j < mapping.size(); ++j)
		{
			if (mapping[i][j] == 'S')
			{
				sX = i;
				sY = j;
			}
			else if (mapping[i][j] == '0')
			{
				bX = i;
				bY = j;
			}
			else if (mapping[i][j] == 'E')
			{
				eX = i;
				eY = j;
			}
		}
	}
	if (sX == -1 || sY == -1 || bX == -1 || bY == -1 || eX == -1 || eY == -1)
	{
		return -1;
	}
	vector<vector<vector<vector<bool>>>> visited(n, 
		vector<vector<vector<bool>>>(m, 
		vector<vector<bool>>(n, vector<bool>(m, false))));
	return PushProcess(mapping, visited, sX, sY, bX, bY);
}

//只是通过了编译 没有测试 递归函数找不到返回-1的问题没有解决
int main(void)
{
	int n;
	int m;
    scanf("%d%d", &n, &m);
	vector<string> mapping(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> mapping[i];
	}
    printf("%d\n", ToTargetMinSteps(mapping, n, m));

	return 0;
}
