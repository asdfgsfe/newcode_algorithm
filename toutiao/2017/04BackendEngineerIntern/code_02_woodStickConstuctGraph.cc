#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <algorithm>
#include <map>

using std::vector;
using std::string;
using std::map;

��һ���ɺܶ�ľ�����ɵļ��ϣ�ÿ��ľ���ж�Ӧ�ĳ��ȣ�
�����ܷ��ü����е���Щľ����ĳ��˳����β��������һ��
������� 0 �ļ򵥶����������ľ����Ҫ���ϣ��򵥶���μ������Խ��Ķ���Ρ�

��ʼ�����ǿյģ������ֲ�����Ҫô���������һ������Ϊ L ��ľ����
Ҫôɾȥ�������Ѿ��е�ĳ��ľ����
ÿ�β����������㶼��Ҫ��֪�Ƿ����ü����е���Щľ������һ���򵥶���Ρ�


��������:
ÿ���������������һ�����ݣ�
ÿ�����ݵ�һ��Ϊһ�������� n ��ʾ����������(1 �� n �� 50000) �� 
��������n�У�ÿ�е�һ������Ϊ�������� i (i �� {1,2})��
�ڶ�������Ϊһ������ L(1 �� L �� 1,000,000,000)��
��� i=1 �����ڼ����ڲ���һ������Ϊ L ��ľ����
��� i=2 ����ɾȥ�ڼ����ڵ�һ������Ϊ L ��ľ����
�������ݱ�֤ɾ��ʱ�����бض����ڳ���Ϊ L ��ľ��������������󼯺϶��Ƿǿյġ�


�������:
����ÿһ�β���������һ���������������ڵ�ľ�����Թ��ɼ򵥶���Σ���� "Yes" ��
������� "No"��


��������1:
5
1 1
1 1
1 1
2 1
1 2

�������1:
No
No
Yes
No
No



//�ж�һЩ����ɼ��׶���ε�ԭ����: �ҳ�����maxEdge ������֮�ʹ����������
//����������˵ ����֮�ͱ�����ڵ����߲������������
void IsSimpleShape(const vector<vector<long>>& ops)
{
    map<long, long> stickToTimes;
	long edgeSum = 0;
    int cnt = 0;    //stickToTimes�Ὣ��ͬ���ȵ��� ������cntͳ�Ƽ����������ж���ľ��
	for (const auto& op : ops)
	{
		if (op[0] == 1)
		{
            ++cnt;
            edgeSum += op[1];
			++stickToTimes[op[1]];
		}
		else
		{
            --cnt;
            edgeSum -= op[1];
			auto stick = stickToTimes.find(op[1]);
			assert(stick != stickToTimes.end());
			if (--stick->second == 0)
			{
				stickToTimes.erase(stick);
			}
		}
		long maxEdge = stickToTimes.rbegin()->first;
		bool is = cnt >= 3 && (edgeSum - maxEdge) > maxEdge;
		std::cout << (is ? "Yes" : "No") << std::endl;
	}
}



int main(void)
{
	int n;
	std::cin >> n;
	vector<vector<long>> ops(n, vector<long>(2, 0));
	for (int i = 0; i < n; ++i)
	{
		std::cin >> ops[i][0] >> ops[i][1];
	}
	IsSimpleShape(ops);

	return 0;
}
