#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;

int SearchIdx(const vector<int>& cards, int val)
{
  int l = 0;
  int r = cards.size() - 1;
  while (l <= r)
  {
    int m = (l + r) / 2;
    if (cards[m] == val)
    {
      return m;
    }
    else if (cards[m] > val)
    {
      r = m - 1;
    }
    else
    {
      l = m + 1;
    }
  }
  return -1;
}

bool EqualProcess(vector<int>& cards)
{
	if (cards.empty())
	{
		return true;
	}
	//统计第一个数字的数量
	int curNum = 0;
	for (int j = 0; j < cards.size() && cards[j] == cards[0]; ++j)
	{
		++curNum;
	}
	//没出现过雀头，且第一个数字出现的次数 >= 2,去掉雀头剩下的能不能和牌
	//去掉的意思就是 让第一个数字作为雀头 看余下的数字能不能搞定
	//其实就是每次尝试让第一个数字为雀头的 尝试方法
	if (cards.size() % 3 != 0 &&  curNum >= 2)
	{
		vector<int> tmp(cards.begin() + 2, cards.end()); //会core 可能是不够三个数字了
		if (EqualProcess(tmp))
		{
			return true;
		}
	}
	//如果第一个数字出现次数 >= 3，去掉这个刻子后看剩下的能和牌
	//到这里要么雀头已经确定了 要么第一个数字能作为雀头 
	//不能是雀头那么只可能是核子或者顺子 具体依据curNum数量来判断
	if (curNum >= 3)
	{
		vector<int> tmp(cards.begin() + 3, cards.end());
		if (EqualProcess(tmp))
		{
			return true;
		}
	}
    // 如果存在顺子，移除顺子后剩下的能和牌
	//到这里要么雀头已经确定 要么第一个数字只能是顺子 因为curNum <= 1
	//找到和他能组成的顺子位置
	int idx1 = SearchIdx(cards, cards[0] + 1);
	int idx2 = SearchIdx(cards, cards[0] + 2);
	if (idx1 != -1 && idx2 != -1)
	{
		cards.erase(cards.begin());
		cards.erase(cards.begin() + idx1);
		cards.erase(cards.begin() + idx2);
		if (EqualProcess(cards))
		{
		return true;
		}
	}
	return false;
}

//启示:对于尝试想法的题目 最简单的编码形式就是 递归 搞定前面一段 然后递归重复后面一段
void EqualGame(const vector<int>& cards)
{
	//从1~9尝试加入每种数字是否可以和牌
	for (int i = 0; i < 9; ++i)
	{
		vector<int> tmp = cards;
		tmp.back() = i + 1;
		sort(tmp.begin(), tmp.end());
		if (EqualProcess(tmp))
		{
			printf("%d ", i + 1);
		}
	}
	printf("\n");
}

int main(void)
{
    vector<int> cards(14, 0);
    for (int i = 0; i < 13; ++i)
    {
      scanf("%d", &cards[i]);
    } 
	EqualGame(cards);
    
    return 0;
}


小包最近迷上了一款叫做雀魂的麻将游戏，但是这个游戏规则太复杂，小包玩了几个月了还是输多赢少。
于是生气的小包根据游戏简化了一下规则发明了一种新的麻将，只留下一种花色，
并且去除了一些特殊和牌方式（例如七对子等），具体的规则如下：

总共有36张牌，每张牌是1~9。每个数字4张牌。
你手里有其中的14张牌，如果这14张牌满足如下条件，即算作和牌
14张牌中有2张相同数字的牌，称为雀头。
除去上述2张牌，剩下12张牌可以组成4个顺子或刻子。
顺子的意思是递增的连续3个数字牌（例如234,567等），刻子的意思是相同数字的3个数字牌（例如111,777）

例如：
1 1 1 2 2 2 6 6 6 7 7 7 9 9 可以组成1,2,6,7的4个刻子和9的雀头，可以和牌
1 1 1 1 2 2 3 3 5 6 7 7 8 9 用1做雀头，组123,123,567,789的四个顺子，可以和牌
1 1 1 2 2 2 3 3 3 5 6 7 7 9 无论用1 2 3 7哪个做雀头，都无法组成和牌的条件。

现在，小包从36张牌中抽取了13张牌，他想知道在剩下的23张牌中，再取一张牌，取到哪几种数字牌可以和牌。

输入描述:
输入只有一行，包含13个数字，用空格分隔，每个数字在1~9之间，数据保证同种数字最多出现4次。

输出描述:
输出同样是一行，包含1个或以上的数字。代表他再取到哪些牌可以和牌。
若满足条件的有多种牌，请按从小到大的顺序输出。若没有满足条件的牌，请输出一个数字0

输入例子1:
1 1 1 2 2 2 5 5 5 6 6 6 9

输出例子1:
9

例子说明1:
可以组成1,2,6,7的4个刻子和9的雀头

输入例子2:
1 1 1 1 2 2 3 3 5 6 7 8 9

输出例子2:
4 7

例子说明2:
用1做雀头，组123,123,567或456,789的四个顺子

输入例子3:
1 1 1 2 2 2 3 3 3 5 7 7 9

输出例子3:
0

例子说明3:
来任何牌都无法和牌