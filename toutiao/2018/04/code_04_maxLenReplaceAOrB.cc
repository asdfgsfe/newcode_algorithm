#include<iostream>
#include<string>
#include <vector>

using std::string;
using std::vector;
 
//检查当前区间长度(step)是否能在 m 个步骤内实现全 a 或 全 b 
bool IsDoneReplace(const vector<int>& aSums, int step, int m, int n)
{
    for(int i = 0; i + step < n; i++)
	{
        
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
	int l = 0;
	int r = n-1;
    while (l <= r)
	{
        int mid = l + (r - l) / 2;
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

先从0开始以(l+r)/2为step长去找 如果找到将l向右扩 在以此时的(l + r)/2去找
相当于在原来的step上在加上后边部分的一般
至于i~j a和b的数量 手动算下就知道了
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

在区间 l~r 的 a 和 b 的个数已知的情况下
若 区间长度step内的 a 的个数 <= m 则 可以通过 m 个步骤 产生 长度为step的字符串 b
若 区间长度step内的 b 的个数 <= m 则 可以通过 m 个步骤 产生 长度为step的字符串 a

归纳为 ：若 区间长度step内的 b 或 a 的个数 <= m 则 可以通过 m 个步骤 产生 长度为step的字符串

这样  就可以直接计算出一个字符串长度（区间长度step）是否可行，因此不需要进行递推，可以直接进行二分搜索，得到最大长度。
检查一个长度step是否可行的时间复杂度为O(n),二分搜索的时间复杂度为O(log n)。
--------------------- 
作者：bobbymly 
来源：CSDN 
原文：https://blog.csdn.net/bobbymly/article/details/79267864 
版权声明：本文为博主原创文章，转载请附上博文链接！