#include <stdio.h>

//统计当前branch有多少个数
//这里传入preNum的目的就是判断 计算到当前这个分支不能超过n
long long BranchNodeNum(long long preNum, long long n)
{
	long long cnt = 1;
	for (long long i = 10; preNum * i < n + 1; i *= 10)
	{
		if (preNum * i + i < n + 1) //1 + 1 * 10 + 1 * 10 * 10 ...... 
		{
			cnt += i;
		}
		else//如果当前的数量已经等于n 则需要减去n+1到(1 * 10 * 10....)的数preNum * i
		{
			cnt += n + 1 - preNum * i;
		}
	}
	return cnt;
}

long long MthNum(long n, long long m)
{
	if (n < 1 || m < 1)
	{
		return 0;
	}
	long long mthNum = 1;
	while (m > 0)
	{
		long long cnt = BranchNodeNum(mthNum, n);
		if (cnt < m)
		{
			m -= cnt; //传入具体的那个分支 是为了这里方便减去 比如传入2 会将1分支的数字全部减去
			++mthNum;
		}
		else
		{
			--m;
            mthNum = m == 0 ? mthNum : mthNum * 10;
		}
	}
	return mthNum;
}

int main(void)
{
	long long n;
	long long m;
	scanf("%ld%ld", &n, &m);
	printf("%ld\n", MthNum(n, m));
	return 0;
}


//注释
//既然是字典序，那么很自然，我们可以考虑使用字典树来实现，
//但是，这里并不需要真的生成这个字典树，而只需要计算对应分支的节点数就行了。
//计算分支节点数，那么很简单，节点数就是上级节点*10，
//总的节点数 = 1 + （1 * 10） + （1 * 10 * 10） + （1 * 10  * 10 * 10） +……，
//这里需要注意最后的边界，n以内的节点数，那么，最后相加的时候必须要把n+1 ~ (1 * 10 * 10 *……)这几个数去掉。
//既然知道了如何计算字典树分支的节点数，要想知道第m个数是什么，那么也就是找第m个节点，
//首先从1开始，如果1分支的节点数>m，那么第m个数肯定是以1开头，进一步搜索其子节点，
//搜索子节点时不用再搜索1了，所以是搜索1分支的第m-1个节点。
//如果1分支的节点数<m， 那么所查找的数肯定不是1开头，那么开始搜索2分支，在2分支中，
//所要找的数应该是第（m-（1分支节点数））个数。
//重复这个过程，要么搜索子节点，要么搜索兄弟节点，知道最终m==0，
//也就是当前节点就是所要搜索的节点

//题目
[编程题] 字典序
时间限制：1秒

空间限制：32768K

给定整数n和m, 将1到n的这n个整数按字典序排列之后, 求其中的第m个数。
对于n=11, m=4, 按字典序排列依次为1, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 因此第4个数是2. 
对于n=200, m=25, 按字典序排列依次为1 10 100 101 102 103 104 105 106 107 108 109 11 110 111 112 113 114 115 116 117 118 119 12 120 121 122 123 124 125 126 127 128 129 13 130 131 132 133 134 135 136 137 138 139 14 140 141 142 143 144 145 146 147 148 149 15 150 151 152 153 154 155 156 157 158 159 16 160 161 162 163 164 165 166 167 168 169 17 170 171 172 173 174 175 176 177 178 179 18 180 181 182 183 184 185 186 187 188 189 19 190 191 192 193 194 195 196 197 198 199 2 20 200 21 22 23 24 25 26 27 28 29 3 30 31 32 33 34 35 36 37 38 39 4 40 41 42 43 44 45 46 47 48 49 5 50 51 52 53 54 55 56 57 58 59 6 60 61 62 63 64 65 66 67 68 69 7 70 71 72 73 74 75 76 77 78 79 8 80 81 82 83 84 85 86 87 88 89 9 90 91 92 93 94 95 96 97 98 99 因此第25个数是120…

输入描述:
输入仅包含两个整数n和m。

数据范围: 

对于20%的数据, 1 <= m <= n <= 5 ; 

对于80%的数据, 1 <= m <= n <= 10^7 ; 

对于100%的数据, 1 <= m <= n <= 10^18.

输出描述:
输出仅包括一行, 即所求排列中的第m个数字.

输入例子1:
11 4

输出例子1:
2