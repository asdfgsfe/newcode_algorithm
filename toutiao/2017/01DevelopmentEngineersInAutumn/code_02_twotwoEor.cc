#include <iostream>
#include <vector>
#include <algorithm>
 
using std::vector;

//给定整数m以及n各数字A1,A2,..An，将数列A中所有元素两两异或，共能得到n(n-1)/2个结果，
//请求出这些结果中大于m的有多少个。

//输入描述:
//第一行包含两个整数n,m. 

//第二行给出n个整数A1，A2，...，An。

//数据范围

//对于30%的数据，1 <= n, m <= 1000

//对于100%的数据，1 <= n, m, Ai <= 10^5

//输出描述:
//输出仅包括一行，即所求的答案

//输入例子1:
//3 10  
//6 5 10

//输出例子1:
//2


//考虑到从高位到地位，依次进行位运算，
//如果两个数异或结果在某高位为1，而m的对应位为0，//对于符号为特殊
//则肯定任何这两位异或结果为1的都会比m大。
//由此，考虑使用字典树（TrieTree）从高位到第位建立字典，
//再使用每个元素依次去字典中查对应高位异或为1， 
//而m为0的数的个数，相加在除以2既是最终的结果；直接贴出代码如下，非原创，欢迎讨论；
//补充：queryTrieTree在搜索的过程中，是从高位往低位搜索，
//那么，如果有一个数与字典中的数异或结果的第k位大于m的第k位，
//那么该数与对应分支中所有的数异或结果都会大于m， 
//否则，就要搜索在第k位异或相等的情况下，
//更低位的异或结果。queryTrieTree中四个分支的作用分别如下：
//1. aDigit=1， mDigit=1时，字典中第k位为0，异或结果为1，
//需要继续搜索更低位，第k位为1，异或结果为0，小于mDigit，不用理会；
//2. aDigit=0， mDigit=1时，字典中第k位为1，异或结果为1，
//需要继续搜索更低位，第k位为0，异或结果为0，小于mDigit，不用理会；
//3. aDigit=1， mDigit=0时，字典中第k位为0，异或结果为1，
//与对应分支所有数异或，结果都会大于m，第k位为1，异或结果为0，递归获得结果；
//4. aDigit=0， mDigit=0时，字典中第k位为1，异或结果为1，
//与对应分支所有数异或，结果都会大于m，第k位为0，异或结果为0，递归获得结果；

struct Node
{
	long long path;
	vector<Node*> nexts;
	Node()
		: path(0), nexts(2, nullptr)
	{}
};

class NumberTrie
{
public:
	NumberTrie()
	    :  root_(new Node())
	{}

	void AddNum(int num)
	{
		Node* cur = root_;
		for (int move = 31; move >= 0; --move)
		{
			int path = (num >> move) & 1;
			if (!cur->nexts[path])
			{
				cur->nexts[path] = new Node();
			}
			cur = cur->nexts[path];
            ++cur->path;
		}
	}

	long long EorMoreMCnt(Node* node, int num, int m, int index)
	{
		if (!node)
        {
            return 0;
        }
        Node* cur = node;
		for (int move = index; move >= 0; --move)
		{
			int path = (num >> move) & 1;
			int mPath = (m >> move) & 1;
			if (path == 1 && mPath == 1)
			{
				if (!cur->nexts[0])
				{
					return 0;
				}
				cur = cur->nexts[0];
			}
			else if (path == 1 && mPath == 0)
			{
				long cnt = EorMoreMCnt(cur->nexts[1], num, m, move - 1);
				return cur->nexts[0] ? cur->nexts[0]->path + cnt : cnt;
			}
			else if (path == 0 && mPath == 1)
			{
				if (!cur->nexts[1])
				{
					return 0;
				}
				cur = cur->nexts[1];
			}
			else//path == 0 mPath == 0
			{
				long long cnt = EorMoreMCnt(cur->nexts[0], num, m, move - 1);
				return cur->nexts[1] ? cur->nexts[1]->path + cnt : cnt;
			}
		}
		return 0;
	}
    
    Node* Root() const { return root_; }
private:
	Node* root_;
};
 

 //总结对于异或和的问题
 //1.利用e1 ^ e2 = e3 e3 ^ e2 = e1 的性质 求i~j着一段的异或和 
 //2.如果要选择等于某一个 或者大于的情况 利用trie树去做查找 
 //对于1 2 两种情况都可以用trie树解
int main(void)
{
    int n;
    int m;
    std::cin >> n >> m;
    vector<int> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }
	NumberTrie nTrie;
	nTrie.AddNum(as[0]);
	long long cnt = 0; //注意会溢出
    for (int i = 1; i < as.size(); ++i)
    {
		cnt += nTrie.EorMoreMCnt(nTrie.Root(), as[i], m, 31);
		nTrie.AddNum(as[i]);
    }
	std::cout << cnt << std::endl;
    return 0;
}