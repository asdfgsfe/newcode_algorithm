#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using std::string;
using std::vector;

给出 n 个字符串，对于每个 n 个排列 p，
按排列给出的顺序(p[0] , p[1] … p[n-1])
依次连接这 n 个字符串都能得到一个长度为这些字符串长度之和的字符串。
所以按照这个方法一共可以生成 n! 个字符串。

一个字符串的权值等于把这个字符串循环左移 i 次后得到的字符串仍和原字符串全等的数量，
i 的取值为 [1 , 字符串长度]。求这些字符串最后生成的 n! 个字符串中权值为 K 的有多少个。

注：定义把一个串循环左移 1 次等价于把这个串的第一个字符移动到最后一个字符的后面。


输入描述:
每组测试用例仅包含一组数据，
每组数据第一行为两个正整数 n, K ， n 的大小不超过 8 ， K 不超过 200。接下来有 n 行，
每行一个长度不超过 20 且仅包含大写字母的字符串。


输出描述:
输出一个整数代表权值为 K 的字符串数量。


输入例子1:
3 2
AB
RAAB
RA

输出例子1:
3

int ComputeWeight(const vector<string>& strs, int k)
{
    int weight = 1;
    string base;
	for (const auto& str : strs)
	{
        base.append(str);
	}
    string tmp = base + base;
    for (int i = 1; i < base.size(); ++i)
    {
		//貌似有优化的一句话 因为移完后 旧串从base[0]开始 新串从base[i]开始 
		//判断第一个相等 感觉没啥必要 因为字符串比较就是一个U一个比 可能有strsub的优化
        if (base[0] == base[i]) 
        {
            //substr的时间复杂度是线性的 掌握这种循环去判断字符串移位的方法
			weight += (base == tmp.substr(i, base.size())) ? 1 : 0;
        }
    }
  return weight == k ? 1 : 0;
}


//在生成数组全排列的过程 计算全中等于k的
//可以用域处理数组的思想把 算全排列与计算权重分开
int KWeightCnt(vector<string>& strs, int i, int k)
{
	if (i == strs.size())
	{
		return ComputeWeight(strs, k);
	}
	int cnt = 0;
	for (int s = i; s < strs.size(); ++s)
	{
		std::swap(strs[s], strs[i]);
		cnt += KWeightCnt(strs, i + 1, k);
		std::swap(strs[s], strs[i]);
	}
	return cnt;
}

int main(void)
{	
	int n;
	int k;
	std::cin >> n >> k;
	vector<string> strs(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> strs[i];
	}
	std::cout << KWeightCnt(strs, 0, k) << std::endl;

	return 0;
}