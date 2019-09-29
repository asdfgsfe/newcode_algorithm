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

//���ڲ��������Ŀ ���������ʱ�临�ӶȽ�����ȥ ��Ҫ����hash�����
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int m;
		scanf("%d", &m);
		//key==ÿ���� ��һ�޶��� val==ÿ�������ڵĲ� 
		//key��ʾһ������ val��ʾ�����������������Щ��
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

С����һ���㷨����ʦ��ͬʱҲ��һ����ʺ�١�
ĳ�죬��ͻ�����룬���è�����Ƶ���ھ�һЩè����˶���Ϣ��
Ϊ����ȡ�˶���Ϣ������Ҫ����Ƶ��ÿһ֡��ȡ��è����������
һ��è��������һ����ά��vector<x, y>�����x_1=x_2 and y_1=y_2����ô������ͬһ��������
��ˣ����������������һ�£�������Ϊ�������˶���
Ҳ����˵���������<a, b>�ڳ���֡����֣���ô�������������˶���
���磬����<a, b>�ڵ�2/3/4/7/8֡���֣���ô���������γ����������˶�2-3-4 ��7-8��
���ڣ�����ÿһ֡���������������������ܲ�һ����С���������ҵ���������˶���

��������:
��һ�а���һ��������N��������������ĸ�����

ÿ�����������ĵ�һ�а���һ��������M��������Ƶ��֡����

��������M�У�ÿ�д���һ֡�����У���һ�������Ǹ�֡����������������������������������ȡֵ��
������������������2�����֡������è��������<1��1>��<2��2>
������������������������<100000

N����1��N��100000��M����1��M��10000��һ֡�������������� �� 10000��
����ȡֵ��Ϊ�Ǹ�������

�������:
��ÿһ��������������������˶��ĳ�����Ϊһ��

��������1:
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

�������1:
3

����˵��1:
����<1,1>��������֡����������3�Σ�������������������ֵĴ������������3