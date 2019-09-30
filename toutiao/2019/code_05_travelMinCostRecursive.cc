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
  //ֱ������visitedȫ����true�ж� ���ҽ��ʼ��λ�õ��������� �������ȥ���ʼ�ڵ�Ļ���
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

//��������path�жϵݹ�Ľ�������ʡ�Ե� ����visitedȫ��Ϊtrue�жϵݹ�Ľ�������
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


С��Ŀǰ����һ�ݱ�ҵ���еĹ滮��
����ӱ����������ֱ�ȥ���ɸ����У�Ȼ���ٻص�������ÿ������֮���������������ÿ������ֻȥһ�Ρ�
���ھ������ޣ�ϣ���ܹ�ͨ�������·�߰��ž����ܵ�ʡһЩ·�ϵĻ�����
����һ����к�ÿ�Գ���֮��Ļ�Ʊ�ļ�Ǯ���ҵ�ÿ������ֻ����һ�β�����������С���ѻ�����

��������:
���и���n��1<n��20������������

���м�ĳ�Ʊ��Ǯ n��n�еľ��� m[n][n]

�������:
��С���ѻ��� s

��������1:
4
0 2 6 5
2 0 4 4
6 4 0 2
5 4 2 0

�������1:
13

����˵��1:
�� 4 �����У����� 1 �ͳ��� 1 �ĳ���Ϊ0������ 1 �ͳ��� 2 ֮��ĳ���Ϊ 2��
���� 1 �ͳ��� 3 ֮��ĳ���Ϊ 6������ 1 �ͳ��� 4 ֮��ĳ���Ϊ 5���������ơ�
����������������֮����е���Ʊ�ɹ�����Ʊ����1000Ԫ���ڣ����迼�Ǽ��������