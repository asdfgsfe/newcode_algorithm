#include <iostream>
#include <vector>

using std::vector;
//�����ķ�����������ٵ���һ���������i�ŷ��䡣����ж�������������٣���ȡx�ŷ�����ǰ���ĵ�һ�������ٵķ���
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