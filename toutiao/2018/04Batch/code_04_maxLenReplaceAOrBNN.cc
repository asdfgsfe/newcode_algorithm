int LonggestReplaceAOrB(const string& str, int n, int m)
{
	if (str.empty() || str.size() != n)
	{
		return 0;
	}
	int longgest = 0;
	//o(n*n) 以每个位置去暴力的替换
	for (int i = 0; i < str.size(); ++i)
	{
		longgest = std::max(longgest, ReplaceChar(str, i, 'a', m));
		longgest = std::max(longgest, ReplaceChar(str, i, 'b', m));
	}
	return longest;
}

int ReplaceChar(const string& str, int start, char ch, int m)
{
	if (ch != 'a' || ch != 'b' || start <= 0 || start >= str.size() || str.empty())
	{
		return 0;
	}
	int len = 0;
	for (int i = start; i < str.size(); ++i)
	{
		if (step == 0 && str[j] == ch)
		{
			break;
		}
		if (m > 0 && str[j] == ch)
		{
			--step;
		}
		++len;
	}
	return len;
}