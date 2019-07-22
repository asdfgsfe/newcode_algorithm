#include <stdio.h>
#include <vector>

using std::vector;

int SkipTimes(const vector<int>& rooms)
{
	if (rooms.empty())
	{
		return 0;
	}
	vector<int> times(rooms.size(), 0);
	times[0] = 1;
	int i = 0;
	int skipNum = 0;
	while (i <= rooms.size()) //模拟跳的过程 记录跳的次数
	{
		++times[i];
		++skipNum;
		i = (times[i] & 0x01) == 0 ? i + 1 : rooms[i] - 1;
	}
	return skipNum;
}


//一种错误的递归留着提示
int SkipProcess(const vector<int>& rooms, int i)
{
  if (i == 0)
  {
    return 0;
  }
  std::cout << "i=" << i << std::endl;
  int pre = SkipProcess(rooms, i - 1);
  return (pre & 0x1) == 0 ? 1 + pre : pre + SkipProcess(rooms, rooms[i - 1] - 1) + 1;
}


int main(void)
{
	int n;
	scanf("%d", &n);
	vector<int> rooms(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &rooms[i]);
	}
	printf("%d\n", SkipTimes(rooms));

	return 0;
}
