#include <iostream>
#include <vector>

using std::vector;
//分配后的房间里，人数最少的那一个房间就是i号房间。
//如果有多个房间人数最少，则取x号房间往前数的第一个人最少的房间
//可能右多段最小且相等的区间 任取一段就行 对于同一段相等的取最后一个位置 最后一个位置一定为最开始区间
//设最小值区间为i~j 可以设x < i 或者i < x < j 或 x > j 去分析
//确定最小值区间后 最小值就是分配过程中转了几圈 因为自己是从0开始分配的
void AssignPerson(vector<long>& rooms, int n, int last)
{
	long minNum = rooms[0];
	for (int i = 0; i < n; ++i)
	{
		if (rooms[i] < minNum)
		{
			minNum = rooms[i];
		}
	}
	int rest = 0;
    last = last - 1;
    while (rooms[last] != minNum)
    {
		++rest;
        --rooms[last];
		last = last > 0 ? last - 1 : n - 1; 
    }
	for (int i = 0; i < n; ++i) 
	{
		rooms[i] -= minNum;
	}
	rooms[last] = n * minNum + rest;
}

int main(void)
{
	int n;
	int last;
	std::cin >> n >> last;
	vector<long> rooms(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> rooms[i];
	}

	AssignPerson(rooms, n, last);
	for (long person : rooms)
	{
		std::cout << person << " ";
	}
	std::cout << std::endl;

	return 0;
}
