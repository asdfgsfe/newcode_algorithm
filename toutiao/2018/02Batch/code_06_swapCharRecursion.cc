#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int SwapProcess(const vector<int>& idxs, int i, int j)
{
	if (i >= j)
    {
		return 0;
	}
	return SwapProcess(idxs, i + 1, j - 1) + (idxs[j] - idxs[i] - 1) - (j - i - 1);
}

//思路是：由于最终连接的结果是相同字符 所以想到将str中的每个字符在str中的位置记录下来 
//此刻唯一要做的就是针对某一个字符在一个数组中计算出将i~j位置字符移动到同一处的步数 
//然后以同样的方式 计算其他字符的 最终选出移动到i~j位置步数不超过m的最长字符
//在同一个数组中具体如何移动：计算把i~j字符移动到一起的步数
//计算出以数组中每个位置结尾的情况下，设以j结尾，把i~j字符移动一起的步数f(i,j)
//则f(i, j) = f(i + 1, j - 1) + (idxs[j] - idxs[i] - 1) - (j - i - 1)
//idxs[j] - idxs[i] - 1表示单纯的把i位置字符移动到j-1处的步数
//j - i - 1 表示从i~j之间还有这些相同字符 如果连接一起了 这些位置就没有必要在移动 所以减去
//f(i, j)表示以j结尾的情况下 把i~j范围的所有字符移动到一起的步数
int LonggestSameChar(const string& str, int m)
{
	if (str.empty())
	{
		return 0;
	}
	vector<vector<int>> charToIdxs(str.size());
	for (int i = 0; i < str.size(); ++i)
	{
		charToIdxs[str[i] - 'a'].emplace_back(i);
	}
	int longgest = 0;
	for (const auto& idxs : charToIdxs)
	{
        if (idxs.empty())
        {
            continue;
        }
		for (int i = 0; i < idxs.size(); ++i)
		{
			for (int j = i; j < idxs.size(); ++j)
			{
				int len = SwapProcess(idxs, i, j);
				longgest = len < m ? std::max(longgest, j - i + 1) : longgest;
			}
		}
	}
	return longgest;
}

//递归解法 AC
//【编码题】字符串S由小写字母构成，长度为n。
//定义一种操作，每次都可以挑选字符串中任意的两个相邻字母进行交换。
//询问在至多交换m次之后，字符串中最多有多少个连续的位置上的字母相同？

int main(void)
{
	string str;
	int m;
    std::cin >> str >> m;
    printf("%d\n", LonggestSameChar(str, m));

	return 0;
}