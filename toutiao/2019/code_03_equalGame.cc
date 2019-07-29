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
	//ͳ����ͬ���ֵ�����
	int curNum = 0;
	for (int j = 0; j < cards.size() && cards[j] == cards[0]; ++j)
	{
		++curNum;
	}
	//û���ֹ�ȸͷ���ҵ�һ�����ֳ��ֵĴ��� >= 2,ȥ��ȸͷʣ�µ��ܲ��ܺ���
	if (cards.size() % 3 != 0 &&  curNum >= 2)
	{
		vector<int> tmp(cards.begin() + 2, cards.end()); //��core �����ǲ�������������
		if (EqualProcess(tmp))
		{
			return true;
		}
	}
	//�����һ�����ֳ��ִ��� >= 3��ȥ��������Ӻ�ʣ�µ��ܺ���
	if (curNum >= 3)
	{
		vector<int> tmp(cards.begin() + 3, cards.end());
		if (EqualProcess(tmp))
		{
			return true;
		}
	}
    // �������˳�ӣ��Ƴ�˳�Ӻ�ʣ�µ��ܺ���
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