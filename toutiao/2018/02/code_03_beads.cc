#include <stdio.h>
#include <vector>
#include <algorithm>

using std::vector;

int main(void)
{
	int n;
	int m;
	int c;
	scanf("%d%d%d", &n, &m, &c);
	vector<set<int>> colToBeads(c);
	for (int i = 0; i < n; ++i)
	{
		int cols = 0;
		scanf("%d", &cols);
		for (int j = 0; j < cols; ++j)
		{
			int col;
			scanf("%d", &col);
			colToBeads[col - 1].emplace(i);
		}
	}

	int count = 0;
	for (int i = 0; i < c; ++i)
	{
		//std::sort(colToBeads[i].begin(), colToBeads[i].end()); 改为集合自己排序
        //珠子连续 如果m != 1 最后一个珠子下一个是第一个珠子
        if (colToBeads[i].front() == 0 && colToBeads[i].back() == n - 1 && m != 1)
        {
            ++count;
            continue;
        }
		for (int j = 0; j < colToBeads[i].size() - 1; ++j)
		{
			if (colToBeads[i][j + 1] - colToBeads[i][j] < m)
            {
                ++count;
                break;
            }
		}
	}
	printf("%d\n", count);
	return 0;
}