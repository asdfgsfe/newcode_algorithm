#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int SwapProcess(const vector<int>& idxs, int i, int j)
{
	if (i >= j)
    {
		return 0;
	}
	return SwapProcess(idxs, i + 1, j - 1) + (idxs[j] - idxs[i] - 1) - (j - i - 1);
}

//˼·�ǣ������������ӵĽ������ͬ�ַ� �����뵽��str�е�ÿ���ַ���str�е�λ�ü�¼���� 
//�˿�ΨһҪ���ľ������ĳһ���ַ���һ�������м������i~jλ���ַ��ƶ���ͬһ���Ĳ��� 
//Ȼ����ͬ���ķ�ʽ ���������ַ��� ����ѡ���ƶ���i~jλ�ò���������m����ַ�
//��ͬһ�������о�������ƶ��������i~j�ַ��ƶ���һ��Ĳ���
//�������������ÿ��λ�ý�β������£�����j��β����i~j�ַ��ƶ�һ��Ĳ���f(i,j)
//��f(i, j) = f(i + 1, j - 1) + (idxs[j] - idxs[i] - 1) - (j - i - 1)
//idxs[j] - idxs[i] - 1��ʾ�����İ�iλ���ַ��ƶ���j-1���Ĳ���
//j - i - 1 ��ʾ��i~j֮�仹����Щ��ͬ�ַ� �������һ���� ��Щλ�þ�û�б�Ҫ���ƶ� ���Լ�ȥ
//f(i, j)��ʾ��j��β������� ��i~j��Χ�������ַ��ƶ���һ��Ĳ���
int LonggestSameChar(const string& str, int m)
{
	if (str.empty())
	{
		return 0;
	}
	vector<vector<int>> charToIdxs(str.size());
	for (int i = 0; i < str.size(); ++i)
	{
		charToIdxs[str[i] - 'a'].emplace_back(i);
	}
	int longgest = 0;
	for (const auto& idxs : charToIdxs)
	{
        if (idxs.empty())
        {
            continue;
        }
		for (int i = 0; i < idxs.size(); ++i)
		{
			for (int j = i; j < idxs.size(); ++j)
			{
				int len = SwapProcess(idxs, i, j);
				longgest = len < m ? std::max(longgest, j - i + 1) : longgest;
			}
		}
	}
	return longgest;
}

//�ݹ�ⷨ AC
//�������⡿�ַ���S��Сд��ĸ���ɣ�����Ϊn��
//����һ�ֲ�����ÿ�ζ�������ѡ�ַ��������������������ĸ���н�����
//ѯ�������ཻ��m��֮���ַ���������ж��ٸ�������λ���ϵ���ĸ��ͬ��

int main(void)
{
	string str;
	int m;
    std::cin >> str >> m;
    printf("%d\n", LonggestSameChar(str, m));

	return 0;
}