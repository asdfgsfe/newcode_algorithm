#include<iostream>
#include<string>
#include <vector>

using std::string;
using std::vector;
 
//检查当前区间长度(step)是否能在 m 个步骤内实现全 a 或 全 b 
bool IsDoneReplace(const vector<int>& aSums, int step, int m, int n)
{
	//从0开始以step的长度在整个n的范围内移动 检查那段(i~j)能被替换 只要有这么一段就返回true
	//不管替换的是a还是b 无所谓 因为step就那么长 下次扩了step长度 还会在判断 所以替换a代价大或者b代价大无所谓
    for(int i = 0; i + step < n; i++)//只检查n-steps步
	{
        //aSums[i + step] - aSums[i - 1])为该区间[i+step, i]内a的数量
		if (m >= step + 1 - (aSums[i + step] - aSums[i - 1]))//替换a  公式 m>=区间内 统计b的个数
        {
			return true;
        }	
		if (m >= aSums[i + step] - aSums[i - 1])//替换 b  公式： m>=区间内 统计a的个数
		{
			return true;
		}	 
    }
    return false;
}
 
 //两种解法
 //1.二分答案的思想nlog(n)
 //2.o(n*n) 暴力的以每个位置去替换 最后选出最大的
 //解法3 统计出a出现的位置 或者b出现的位置 对位置之间的差 位置区间段组成一个结构 按照区间从小到大排序 然后从前往后替换 就可以搞出答案
int main(void)
{
	int n;
	int m;
    cin >> n >> m;
    string str;
    cin >> str;
    //输入并计算出 count 数组 
    int asum=0;
	vector<int> aSums(str.size(), 0);
    for(int i = 0;i < str.size(); i++)
	{
        if (str[i]=='a')
        {
			aSums[i] = ++asum;
        }
        else 
		{
			aSums[i] = asum;
		}
    }
 
    //二分搜索最大区间值 类似于贪心 采用二分答案的方法
	//对于答案最大值固定的这种题目 可以考虑二分答案的思路 如果最大一般去上界即l
	//如果最小一般取下解r 依据某种唯一的限制去二分
	//最大值固定 能操作的次数有限制 可以考虑采用二分答案的方法 二分最大的答案 这里最大答案为n
	int l = 0;
	int r = n-1;
    while (l <= r)
	{
        int mid = l + (r - l) / 2; //等价于(l + r) / 2防止越界的写法
        //o(n)的操作
		//不管那一步去判断 m都是固定的m大小不变 
		//是因为刚开始判断step长度的区间 用m比 
		//假设m>=step 那么接着判断(原来的steps + 新的steps)=steps 这个区间 
		//旧的那段被重新加进来了 就相当于step一直在变长 所以m不变
		if (IsDoneReplace(aSums, mid, m, n))
		{
            l = mid + 1;
        }
		else 
		{
			r = mid - 1;
		}
		std::cout << "l=" << l << " r=" << r << std::endl;
    }
   std::cout << l << std::endl; //去上界
    return 0;
     
}

题目：
有一个仅包含’a’和’b’两种字符的字符串s，长度为n，
每次操作可以把一个字符做一次转换（把一个’a’设置为’b’，或者把一个’b’置成’a’)；
但是操作的次数有上限m，问在有限的操作数范围内，能够得到最大连续的相同字符的子串的长度是多少。

输入描述:
第一行两个整数 n , m (1<=m<=n<=50000)，第二行为长度为n且只包含’a’和’b’的字符串s。

输出描述:
输出在操作次数不超过 m 的情况下，能够得到的 最大连续 全’a’子串或全’b’子串的长度。

输入例子1:
8 1
aabaabaa

输出例子1:
5

例子说明1:
把第一个 'b' 或者第二个 'b' 置成 'a'，可得到长度为 5 的全 'a' 子串。


注释及调试：
先从0开始以(l+r)/2为step长去找 如果找到将l向右扩 在以此时的(l + r)/2去找
相当于在原来的step上在加上后边部分的一半
至于i~j a和b的数量 手动算下就知道了asums[j] - asums[i]
8 1
babaabaa
i=0 step=3 i+step=3
i=1 step=3 i+step=4
l=4 r=7 mid=3
i=0 step=5 i+step=5
i=1 step=5 i+step=6
i=2 step=5 i+step=7
l=4 r=4 mid=5
i=0 step=4 i+step=4
i=1 step=4 i+step=5
i=2 step=4 i+step=6
i=3 step=4 i+step=7
l=5 r=4 mid=4
5
--------------------- 
作者：bobbymly 
来源：CSDN 
原文：https://blog.csdn.net/bobbymly/article/details/79267864 
版权声明：本文为博主原创文章，转载请附上博文链接！


该字符串非 a 即 b 也就是说在区间 l~r之间把所有字符变为 a 所需的步骤数是 该区间内 b 的数量。反之亦然.
用数组 count[i] 表示 字符串中位置区间 0~i 包含的 a 的个数
则 区间 l~r 的 a 的个数为 count[r]-count[l-1]
b 的个数用 a 的个数算出 即 区间 l~r 的 b 的个数为 r+1-count[r]-(l+1-1-count[l-1])=r+1-count[r]-l+count[l-1]
可以这么考虑：
l~r总的长度为r-l+1
l~r区间内a的个数为count[r] - count[l-1]
则b的个数为r - l + 1 - (count[r] - count[l-1])

在区间 l~r 的 a 和 b 的个数已知的情况下
若 区间长度step内的 a 的个数 <= m 则 可以通过 m 个步骤 产生 长度为step的字符串 b
若 区间长度step内的 b 的个数 <= m 则 可以通过 m 个步骤 产生 长度为step的字符串 a

归纳为 ：若 区间长度step内的 b 或 a 的个数 <= m 则 可以通过 m 个步骤 产生 长度为step的字符串

这样  就可以直接计算出一个字符串长度（区间长度step）是否可行，
因此不需要进行递推，可以直接进行二分搜索，得到最大长度。
检查一个长度step是否可行的时间复杂度为O(n),二分搜索的时间复杂度为O(log n)。
--------------------- 
作者：bobbymly 
来源：CSDN 
原文：https://blog.csdn.net/bobbymly/article/details/79267864 
版权声明：本文为博主原创文章，转载请附上博文链接！
