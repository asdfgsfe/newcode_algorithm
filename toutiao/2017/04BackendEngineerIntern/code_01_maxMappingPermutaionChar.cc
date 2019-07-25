#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using std::string;
using std::set;
using std::vector;

int ConvertNum(char ch, const string& per)
{
	int first = 9;
	for (int i = 0; i < per.size(); ++i, --first)
	{
		if (per[i] == ch)
		{
			return first;
		}
	}
	return 0;
}

void Permutations(string& str, int i, const set<char>& first, long& maxSum, const vector<string>& strs)
{
  if (i == str.size() && (str.size() < 10 || first.find(str[i - 1]) == first.end()))
  {
	long cur = 0;
	for (const auto& curs : strs)
	{
		long num = 0;
		for (char ch : curs)
		{
			num = num * 10 + ConvertNum(ch, str);
		}
		cur += num;
	}
	maxSum = std::max(maxSum, cur);
    return;
  }
  for (int s = i; s < str.size(); ++s)
  {
    std::swap(str[i], str[s]);
    Permutations(str, i + 1, first, maxSum, strs);
    std::swap(str[i], str[s]);
  }
}

long MaxSumStrToInt(const vector<string>& strs)
{
	if (strs.empty())
	{
		return 0;
	}
	set<char> first;
	set<char> allChars;
	for (const auto& str : strs)
	{
		for (int i = 0; i < str.size(); ++i)
		{
			first.insert(str[0]);
			allChars.insert(str[i]);
		}
	}
	string str;
	for (auto ch : allChars)
	{
		str += ch;
	}
	long maxSum = 0;
	Permutations(str, 0, first, maxSum, strs);
	return maxSum;
}


//全排列字符 这个代码写的不好
int main(void)
{
	int n;
	scanf("%d", &n);
	vector<string> strs(n);
	for (int i = 0; i < strs.size(); ++i)
	{
		std::cin >> strs[i];
	}
	printf("%ld\n", MaxSumStrToInt(strs));
	return 0;
}
