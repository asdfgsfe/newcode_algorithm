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