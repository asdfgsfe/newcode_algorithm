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
	//统计相同数字的数量
	int curNum = 0;
	for (int j = 0; j < cards.size() && cards[j] == cards[0]; ++j)
	{
		++curNum;
	}
	//没出现过雀头，且第一个数字出现的次数 >= 2,去掉雀头剩下的能不能和牌
	if (cards.size() % 3 != 0 &&  curNum >= 2)
	{
		vector<int> tmp(cards.begin() + 2, cards.end()); //会core 可能是不够三个数字了
		if (EqualProcess(tmp))
		{
			return true;
		}
	}
	//如果第一个数字出现次数 >= 3，去掉这个刻子后看剩下的能和牌
	if (curNum >= 3)
	{
		vector<int> tmp(cards.begin() + 3, cards.end());
		if (EqualProcess(tmp))
		{
			return true;
		}
	}
    // 如果存在顺子，移除顺子后剩下的能和牌
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

void EqualGame(const vector<int>& cards)
{
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