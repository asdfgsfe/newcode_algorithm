����ħ���ֽ�Сħ������2*2*2�������νṹ��ÿһ�涼��4���飬����24���顣
ÿ�β������Խ�����һ����ʱ�����˳ʱ����ת90�㣬�罫������ʱ����ת90��������¡�

Nero��Сħ��������һЩ�Ķ����������滻ÿ�����������ɫ����֮Ϊ����ħ����
ħ����ÿһ��������Ⱦ����������4�����ֵĳ˻�����ħ�����������Ⱦ���6�����������ܺ͡�
����Nero��һ������ħ��������֪�����ħ���ڲ���������5�ε�ǰ�����ܴﵽ������������Ƕ��١�
ħ��չ����ÿһ����������ͼ��


��������:
����һ�а���24�����֣������˳�����ħ��ÿһ����������֡���������С��ΧΪ[-100,100]��

�������:
���һ�а���һ�����֣���ʾ��������ȡ�

��������1:
2 -3 -2 3 7 -6 -6 -7 9 -5 -9 -3 -2 1 4 -9 -1 -10 -5 -5 -10 -4 8 2

�������1:
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