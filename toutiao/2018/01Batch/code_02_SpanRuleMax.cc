����һ����������, ��Ҫ��ѡ��һ������, ʹ�ø����������������о������¼����ֵ����һ����

�����е���С�� * �����������ĺ�����������������������ֵ���ɣ�����Ҫ�����������䡣
���������  [6 2 1]�����������ʽ, �ɵõ����п���ѡ����������ļ���ֵ:

 

[6] = 6 * 6 = 36;

[2] = 2 * 2 = 4;

[1] = 1 * 1 = 1;

[6,2] = 2 * 8 = 16;

[2,1] = 1 * 3 = 3;

[6, 2, 1] = 1 * 9 = 9;

 

����������ɼ�ѡ������ [6] ������ֵΪ 36�� ��������Ϊ 36��

�����ڵ��������ֶ���[0, 100]�ķ�Χ��;


��������:
��һ�������������г���n���ڶ��������������С�
���� 50%������,  1 <= n <= 10000;
���� 100%������, 1 <= n <= 500000;

�������:
������龭�����������ֵ��

��������1:
3
6 2 1

�������1:
36

int MaxValInRuleSpan(const vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}
	int maxVal = 0x80000000;
	vector<int> sums(nums.size());
	stack<int> incrId;
	for (int i = 0; i < nums.size(); ++i)
	{
		sums[i] = i > 0 ? sums[i - 1] + nums[i] : nums[i];
		while (!incrId.empty() && nums[i] <= nums[incrId.top()])
		{
			int cur = incrId.top();
			incrId.pop();
			int sum = incrId.empty() ? sums[i - 1] : sums[i - 1] - nums[incrId.top()];
			maxVal = std::max(maxVal, nums[cur] * sum);
		}
		incrId.push(i);
	}
	return maxVal;
}