二阶魔方又叫小魔方，是2*2*2的立方形结构。每一面都有4个块，共有24个块。
每次操作可以将任意一面逆时针或者顺时针旋转90°，如将上面逆时针旋转90°操作如下。

Nero在小魔方上做了一些改动，用数字替换每个块上面的颜色，称之为数字魔方。
魔方上每一面的优美度就是这个面上4个数字的乘积，而魔方的总优美度就是6个面优美度总和。
现在Nero有一个数字魔方，他想知道这个魔方在操作不超过5次的前提下能达到的最大优美度是多少。
魔方展开后每一块的序号如下图：


输入描述:
输入一行包含24个数字，按序号顺序给出魔方每一块上面的数字。所有数大小范围为[-100,100]。

输出描述:
输出一行包含一个数字，表示最大优美度。

输入例子1:
2 -3 -2 3 7 -6 -6 -7 9 -5 -9 -3 -2 1 4 -9 -1 -10 -5 -5 -10 -4 8 2

输出例子1:
8281

int PerfectNumberMagic(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	vector<vector<vector<int>>> magic(6, vector<vector<int>>(2, vector<int>(2)));
	for (int i = 0; i < numbers.size(); i += 4)
	{
		magic[i / 4][0][0] = numbers[i];
		magic[i / 4][0][1] = numbers[i + 2];
		magic[i / 4][1][0] = numbers[i + 1];
		magic[i / 4][1][1] = numbers[i + 3];
	}
	int perfect = 0;
	//for (int i = 0; i < 6; ++i)
	{
		//perfect = std::max(perfect, RotateProcess(magic, 0, 5));
	}
	unordered_map<int, vector<int>> unConfiltPlans = {{1, {}}; {2, {}}; {3, {}}; {4, {}}; {5, {}}};
	return RotateProcess(magic, 0, 5);
}

int RotateProcess(magic, int plan, int times)
{
	if (times == 0 || plan == 6)
	{
		return 0;
	}
	int perfect = 0;
	for (int i = 0; i < times && i < 4; ++i)
	{
		perfect = Rotate(magic, plan, i);
		perfect = std::max(perfect, RotateProcess(magic, plan, times - i));
	}
	return perfect;
}

int Rotate(magic, int plan, int times, bool isOrder)
{
	vector<int>& plans = UnConfiltPlans[plan];
	if (isOrder)
	{
		for (int i = 0; i < plans.size(); ++i)
		{
			std::swap(magic[plans[i]][0][0], magic[plans[i + times]][0][0]);
			std::swap(magic[plans[i]][0][1], magic[plans[i + times]][0][1]);
		}
	}
	else
	{
		for (int i = plans.size() - 1; i >= 0; --i)
		{
			std::swap(magic[plans[i]][0][0], magic[plans[i - times]][0][0]);
			std::swap(magic[plans[i]][0][1], magic[plans[i - times]][0][1]);
		}
	}
	int fineVal = 1;
	for (int i = 0; i < 6; ++i)
	{
		allVal *= magic[i][0][0] + magic[i][0][1] + magic[i][1][0] + magic[i][0][1];
	}
	return fineVal;
}