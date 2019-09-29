P为给定的二维平面整数点集。定义 P 中某点x，如果x满足 P 中任意点都不在 x 的右上方区域内（横纵坐标都大于x），
则称其为“最大的”。求出所有“最大的”点的集合。（所有点的横坐标和纵坐标都不重复, 坐标轴范围在[0, 1e9) 内）

如下图：实心点为满足条件的点的集合。请实现代码找到集合 P 中的所有 ”最大“ 点的集合并输出。




输入描述:
第一行输入点集的个数 N， 接下来 N 行，每行两个数字代表点的 X 轴和 Y 轴。
对于 50%的数据,  1 <= N <= 10000;
对于 100%的数据, 1 <= N <= 500000;

输出描述:
输出“最大的” 点集合， 按照 X 轴从小到大的方式输出，每行两个数字分别代表点的 X 轴和 Y轴。

输入例子1:
5
1 2
5 3
4 6
7 5
9 0

输出例子1:
4 6
7 5
9 0



#include <iostream>
#include <vector>
#include <algorithm>
//https://github.com/ReyzalX/nowcode
using std::vector;

struct Point
{
	int x;
	int y;
	Point() {}
	Point(int x1, int y1)
		: x(x1),y(y1)
	{}
};

vector<Point> Parse(void)
{
	int len = 0;
	std::cin >> len;
	vector<Point> points(len);
	for (int i = 0; i < len; ++i)
	{
		int x;
		int y;
		std::cin >> x;
        std::cin >> y;
		points[i] = Point(x, y);
	}
	return points;
}

//o(n*log(n)) 只能过百分之80-90 是因为用了流
void (void)
{
	vector<Point> points = Parse();
    std::sort(points.begin(), points.end(), 
             [](const Point& lhs, const Point& rhs) ->bool
              {
                 //如果题目不要求x从小到大输出 可以按照x升序 y降序排列 会按照y从小到大输出
				 return lhs.y == rhs.y ? lhs.x > rhs.x : lhs.y < rhs.y;
              }
             );
	std::cout << points.back().x << " " << points.back().y << std::endl;
	int startX = points.back().x;
	for (int i = points.size() - 2; i >= 0; --i)
	{
		if (points[i].x > startX)
		{
			std::cout << points[i].x << " " << points[i].y << std::endl;
			startX = points[i].x;
		}
	}
} 

//堆操作 也是o(n*log(n)) 但是vector内存有动态变化的代价
void MaxPoints(void)
{
    int len = 0;
    scanf("%d", &len);
    vector<Point> points(len);
    for (int i = 0; i < len; ++i)
    {
        scanf("%d%d", &points[i].x, &points[i].y);
    }
    auto Comparator = [](const Point& lhs, const Point& rhs) ->bool
                    {
                        return lhs.y == rhs.y ? lhs.x > rhs.x : lhs.y < rhs.y;
                    };
    std::make_heap(points.begin(), points.end(), Comparator);
    std::cout << points.front().x << " " << points.front().y << std::endl;
    int maxX = points.front().x;
    std::pop_heap(points.begin(), points.end(), Comparator);
    points.pop_back();
    while (!points.empty())
    {
        if (points.front().x > maxX)
        {
            //std::cout << points.front().x << " " << points.front().y << std::endl;
            printf("%d %d\n", points.front().x, points.front().y);
            maxX = points.front().x;
        }
        std::pop_heap(points.begin(), points.end(), Comparator);
        points.pop_back();
    }
}

//1.还有种o(n*n)的思想 就是以为个位置遍历去选择是否满足条件
int main(void)
{
	MaxPoints();

	return 0;
}