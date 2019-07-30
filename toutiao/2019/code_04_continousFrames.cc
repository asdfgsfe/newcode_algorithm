#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <iostream>

using std::set;
using std::map;
using std::pair;

void LoggestContinuousFrame(const map<pair<int, int>, set<int>>& frames)
{
    int longgest = 0;
    for (const auto& frame : frames)
	{
        int cnt = 1;
        auto pre = frame.second.cbegin();
        auto level = ++frame.second.cbegin();
		while (level != frame.second.end())
		{
            if (*level - *pre != 1)
            {
			    longgest = std::max(longgest, cnt);
			    cnt = 1;
		    }
            else
          {
            ++cnt;
          }
          ++pre;
          ++level;
		}
        longgest = std::max(longgest, cnt);
	}
	printf("%d\n", longgest);
}


int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int m;
		scanf("%d", &m);
        map<pair<int, int>, set<int>> frames; //key==每个点 独一无二的 val==每个点所在的层
		for (int j = 0; j < m; ++j)
		{
			int k;
			scanf("%d", &k);
			for (int s = 0; s < k; ++s)
			{
                int x;
				int y;
				scanf("%d%d", &x, &y);
                frames[std::make_pair(x, y)].insert(j);
          }
		}
        LoggestContinuousFrame(frames);
	}
    return 0;
}