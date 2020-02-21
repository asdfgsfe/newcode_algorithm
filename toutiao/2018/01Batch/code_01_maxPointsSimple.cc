#include <stdio.h>
#include <vector>
#include <algorithm>

using std::vector;

struct Point
{
    int x;
    int y;
    Point() = default;
    Point(int i, int j) : x(i), y(j) {}
};

void MaxPoints(vector<Point>& points)
{
    if (points.empty())
    {
        return;
    }
    std::sort(points.begin(), points.end(), 
             [](const auto& lhs, const auto& rhs)
              {
					//y�Ӵ�С���� x�Ӵ��С��
					return lhs.y != rhs.y ? lhs.y > rhs.y : lhs.x < rhs.x;
              });
    int leftX = 0x80000000;
    //x���ұ��ƶ�ѡ��
    for (const auto& point : points)
    {
        if (point.x > leftX)
        {
            printf("%d %d\n", point.x, point.y);
            leftX = point.x;
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<Point> points(n);
    for (auto& point : points)
    {
        scanf("%d%d", &point.x, &point.y);
    }
    MaxPoints(points);
    return 0;
}
