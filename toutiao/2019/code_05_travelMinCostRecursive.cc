#include <stdio.h>
#include <vector>
using std::vector;

int TravelProcess(const vector<vector<int>>& cities, int s, vector<bool>& visited, vector<int>& path)
{
  if (s < 0 || s >= cities.size() || visited[s])
  {
    return 0x7fffffff;
  }
  visited[s] = true;
  path.emplace_back(s);
  int cost = 0x7fffffff;
  //直接利用visited全部是true判断 并且将最开始的位置当参数传入 来计算回去到最开始节点的花费
  for (int c = 0; c < cities.size() && path.size() != cities.size(); ++c)
  {
    if (!visited[c])
    {
      cost = std::min(cost, TravelProcess(cities, c, visited, path) + cities[s][c]);
    }
  }
  cost = path.size() == cities.size() ? cities[path.front()][path.back()] : cost;
  visited[s] = false;
  path.pop_back();
  return cost;
}

//这里利用path判断递归的结束可以省略掉 利用visited全部为true判断递归的结束就行
int TravelMinCost(const vector<vector<int>>& cities)
{
  if (cities.empty() || cities[0].empty())
  {
    return 0;
  }
  int cost = 0x7fffffff;
  for (int i = 0; i < cities.size(); ++i)
  {
      vector<bool> visited(cities.size(), false);
      vector<int> path;
      cost = std::min(cost, TravelProcess(cities, i, visited, path));
  }
  return cost;
}

int main(void)
{
	int n;
	scanf("%d", &n);
  vector<vector<int>> cities(n, vector<int>(n));
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      scanf("%d", &cities[i][j]);
    }
  }
  printf("%d\n", TravelMinCost(cities));  
  return 0;
}


小明目前在做一份毕业旅行的规划。
打算从北京出发，分别去若干个城市，然后再回到北京，每个城市之间均乘坐高铁，且每个城市只去一次。
由于经费有限，希望能够通过合理的路线安排尽可能的省一些路上的花销。
给定一组城市和每对城市之间的火车票的价钱，找到每个城市只访问一次并返回起点的最小车费花销。

输入描述:
城市个数n（1<n≤20，包括北京）

城市间的车票价钱 n行n列的矩阵 m[n][n]

输出描述:
最小车费花销 s

输入例子1:
4
0 2 6 5
2 0 4 4
6 4 0 2
5 4 2 0

输出例子1:
13

例子说明1:
共 4 个城市，城市 1 和城市 1 的车费为0，城市 1 和城市 2 之间的车费为 2，
城市 1 和城市 3 之间的车费为 6，城市 1 和城市 4 之间的车费为 5，依次类推。
假设任意两个城市之间均有单程票可购买，且票价在1000元以内，无需考虑极端情况。