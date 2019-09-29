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

//对于查找类的题目 如果遍历的时间复杂度降不下去 就要考虑hash表查找
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int m;
		scanf("%d", &m);
		//key==每个点 独一无二的 val==每个点所在的层 
		//key表示一个特征 val表示这个特征出现在了那些层
        map<pair<int, int>, set<int>> frames;
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

小明是一名算法工程师，同时也是一名铲屎官。
某天，他突发奇想，想从猫咪的视频里挖掘一些猫咪的运动信息。
为了提取运动信息，他需要从视频的每一帧提取“猫咪特征”。
一个猫咪特征是一个两维的vector<x, y>。如果x_1=x_2 and y_1=y_2，那么这俩是同一个特征。
因此，如果喵咪特征连续一致，可以认为喵咪在运动。
也就是说，如果特征<a, b>在持续帧里出现，那么它将构成特征运动。
比如，特征<a, b>在第2/3/4/7/8帧出现，那么该特征将形成两个特征运动2-3-4 和7-8。
现在，给定每一帧的特征，特征的数量可能不一样。小明期望能找到最长的特征运动。

输入描述:
第一行包含一个正整数N，代表测试用例的个数。

每个测试用例的第一行包含一个正整数M，代表视频的帧数。

接下来的M行，每行代表一帧。其中，第一个数字是该帧的特征个数，接下来的数字是在特征的取值；
比如样例输入第三行里，2代表该帧有两个猫咪特征，<1，1>和<2，2>
所有用例的输入特征总数和<100000

N满足1≤N≤100000，M满足1≤M≤10000，一帧的特征个数满足 ≤ 10000。
特征取值均为非负整数。

输出描述:
对每一个测试用例，输出特征运动的长度作为一行

输入例子1:
1
8
2 1 1 2 2
2 1 1 1 4
2 1 1 2 2
2 2 2 1 4
0
0
1 1 1
1 1 1

输出例子1:
3

例子说明1:
特征<1,1>在连续的帧中连续出现3次，相比其他特征连续出现的次数大，所以输出3