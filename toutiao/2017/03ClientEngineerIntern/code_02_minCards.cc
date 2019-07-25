#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using std::string;
using std::vector;
你作为一名出道的歌手终于要出自己的第一份专辑了，
你计划收录 n 首歌而且每首歌的长度都是 s 秒，
每首歌必须完整地收录于一张 CD 当中。
每张 CD 的容量长度都是 L 秒，而且你至少得保证同一张 CD 内相邻两首歌中间至少要隔 1 秒。
为了辟邪，你决定任意一张 CD 内的歌数不能被 13 这个数字整除，
那么请问你出这张专辑至少需要多少张 CD ？


输入描述:
每组测试用例仅包含一组数据，每组数据第一行为三个正整数 n, s, L。 
保证 n ≤ 100 , s ≤ L ≤ 10000 


输出描述:
输出一个整数代表你至少需要的 CD 数量。


输入例子1:
7 2 6

输出例子1:
4

int MinCards(int n, int s, int l)
{
	int num = l / s;
    int rest = l % s;
	int rN = s * num + num - 1 - rest; //我还需要这么多时间存储
	while (rN >= l || num % 13 == 0) //rN >= l也没有错 就相当于在第一个片中少存了
	{
		--num;
        rN = s * num + num - 1 - rest;
	}
    if (num < 0)
    {
        return 1;
    }
    if (n < num && n % 13 == 0)
    {
        return 2;
    }
	return n / num + (n % num == 0 ? 0 : 1);
}

//者道题目应该是有问题 要靠n/num余下的值能不能被13正处 如果能要存在2个唱片中
int main(void)
{	
	int n;
	int s;
	int l;
	std::cin >> n >> s >> l;
	std::cout << MinCards(n, s, l) << std::endl;

	return 0;
}