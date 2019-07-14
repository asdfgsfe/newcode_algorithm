#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <algorithm>
#include <map>

using std::vector;
using std::string;
using std::map;

有一个由很多木棒构成的集合，每个木棒有对应的长度，
请问能否用集合中的这些木棒以某个顺序首尾相连构成一个
面积大于 0 的简单多边形且所有木棒都要用上，简单多边形即不会自交的多边形。

初始集合是空的，有两种操作，要么给集合添加一个长度为 L 的木棒，
要么删去集合中已经有的某个木棒。
每次操作结束后你都需要告知是否能用集合中的这些木棒构成一个简单多边形。


输入描述:
每组测试用例仅包含一组数据，
每组数据第一行为一个正整数 n 表示操作的数量(1 ≤ n ≤ 50000) ， 
接下来有n行，每行第一个整数为操作类型 i (i ∈ {1,2})，
第二个整数为一个长度 L(1 ≤ L ≤ 1,000,000,000)。
如果 i=1 代表在集合内插入一个长度为 L 的木棒，
如果 i=2 代表删去在集合内的一根长度为 L 的木棒。
输入数据保证删除时集合中必定存在长度为 L 的木棒，且任意操作后集合都是非空的。


输出描述:
对于每一次操作结束有一次输出，如果集合内的木棒可以构成简单多边形，输出 "Yes" ，
否则输出 "No"。


输入例子1:
5
1 1
1 1
1 1
2 1
1 2

输出例子1:
No
No
Yes
No
No



//判断一些边组成简易多边形的原则是: 找出最大边maxEdge 其他边之和大于这个最大边
//从三角形来说 两边之和必须大于第三边才能组成三角形
void IsSimpleShape(const vector<vector<long>>& ops)
{
    map<long, long> stickToTimes;
	long edgeSum = 0;
    int cnt = 0;    //stickToTimes会将相同长度叠加 所以用cnt统计集合中现在有多少木棍
	for (const auto& op : ops)
	{
		if (op[0] == 1)
		{
            ++cnt;
            edgeSum += op[1];
			++stickToTimes[op[1]];
		}
		else
		{
            --cnt;
            edgeSum -= op[1];
			auto stick = stickToTimes.find(op[1]);
			assert(stick != stickToTimes.end());
			if (--stick->second == 0)
			{
				stickToTimes.erase(stick);
			}
		}
		long maxEdge = stickToTimes.rbegin()->first;
		bool is = cnt >= 3 && (edgeSum - maxEdge) > maxEdge;
		std::cout << (is ? "Yes" : "No") << std::endl;
	}
}



int main(void)
{
	int n;
	std::cin >> n;
	vector<vector<long>> ops(n, vector<long>(2, 0));
	for (int i = 0; i < n; ++i)
	{
		std::cin >> ops[i][0] >> ops[i][1];
	}
	IsSimpleShape(ops);

	return 0;
}
