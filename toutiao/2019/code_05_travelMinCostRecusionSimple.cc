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

//ͨ��visited�ж��Ƿ���������·�� ����start��¼���γ������ȿ�ʼ��λ��
//�������ȿ�ʼ��λ�� �뱾�����һ�����ĳ���֮�乹�� ��ȥ
//ȱ������û�� �����ļ�¼��γ������������е�����·��
//�ݹ�תdpһ��Ҫ��dp�ܱ��ݹ�����й��̲���
//����ݹ�ı仯������һ������֮��� ������������ֲ��� �뵽��λ������¼����ݹ�Ĺ�����dp
//λ������Ϊ�� �൱��visited Ȼ��ݹ�����ݲ���
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