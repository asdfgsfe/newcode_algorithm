#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <iostream>
#include <vector>

using std::set;
using std::map;
using std::pair;
using std::vector;

void Dump(const map<pair<int, int>, set<int>>& frames)
{
  for (const auto& frame : frames)
  {
    std::cout << "f=[" << frame.first.first << "," << frame.first.second << "] ";
    for (auto f : frame.second)
    {
      std::cout << f << " ";
    }
    std::cout << std::endl;
  }
}

int TravelProcess(const vector<vector<int>>& cities, int r, int c, int sR, int sC, vector<vector<bool>>& visited, set<int>& path)
{
  if (r < 0 || r >= cities.size() || c < 0 || c >= cities[0].size() || r >= c)
  {
    return 0x7fffffff;
  }
  if (visited[r][c])
  {
    return r == sR && c == sC && path.size() == cities.size() ? 0 : 0x7fffffff;
  }
  visited[r][c] = true;
  int cost = TravelProcess(cities, r + 1, c, sR, sC, visited);
  cost = std::min(cost, TravelProcess(cities, r - 1, c, sR, sC, visited));
  cost = std::min(cost, TravelProcess(cities, r, c + 1, sR, sC, visited));
  cost = std::min(cost, TravelProcess(cities, r, c - 1, sR, sC, visited));
  std::cout << "cost=" << cost << " r=" << r << " c=" << c << std::endl;
  return cost != 0x7fffffff ? cost + cities[r][c] : cost;
}

int TravelMinCost(const vector<vector<int>>& cities)
{
  if (cities.empty() || cities[0].empty())
  {
    return 0;
  }
  int cost = 0x7fffffff;
  for (int i = 0; i < cities.size(); ++i)
  {
    for (int j = i; j < cities.size(); ++j)
    {
      vector<vector<bool>> visited(cities.size(), vector<bool>(cities.size(), false));
      set<int> path;
      cost = std::min(cost, TravelProcess(cities, i, j, i, j, visited, path));
    }
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