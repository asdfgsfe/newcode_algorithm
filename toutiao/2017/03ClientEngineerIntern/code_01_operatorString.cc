#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using std::string;
using std::vector;

������һ���ַ�������Ҫ������ַ������� n �β�����
ÿ�β��������������֣�(p, l) ��ʾ��ǰ�ַ����д��±�Ϊ p ���ַ���ʼ�ĳ���Ϊ l ��һ���Ӵ���
��Ҫ������Ӵ����ҷ�ת���������Ӵ�ԭ��λ�õ����󷽣�
�����õ����ַ�����ʲô���ַ������±��Ǵ� 0 ��ʼ�ģ�����Դ������еõ�������Ϣ��


��������:
ÿ���������������һ�����ݣ�ÿ�����ݵ�һ��Ϊԭ�ַ��������Ȳ����� 10 ��
��������Сд�ַ������֡�����������һ������ n ��ʾ�� n ��������
�ٽ������� n �У�ÿ��������������ʾÿ�β�����(p , l)��



��֤����Ĳ���һ���Ϸ������õ����ַ������Ȳ����� 1000��


�������:
���һ���ַ����������õ����ַ�����


��������1:
ab
2
0 2
1 3

�������1:
abbaabb

void OpStr(string& str, const vector<vector<int>>& ops)
{
	if (str.empty() || ops.empty() || ops[0].empty() || ops[0].size() != 2)
	{
		return;
	}
	for (const auto& op : ops)
	{
		string tmp = str.substr(op[0], op[1]);
		std::reverse(tmp.begin(), tmp.end());
		str = str.insert(op[0] + op[1], tmp);
	}
}

int main(void)
{	
	string str;
	std::cin >> str;
	int n;
	std::cin >> n;
	vector<vector<int>> ops(n, vector<int>(2));
	for (int i = 0; i < n; ++i)
	{
		std::cin >> ops[i][0] >> ops[i][1];
	}
	OpStr(str, ops);
	std::cout << str << std::endl;

	return 0;
}