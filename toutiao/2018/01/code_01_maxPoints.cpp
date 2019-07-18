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

//o(n*log(n)) ֻ�ܹ��ٷ�֮80-90 ����Ϊ������
void (void)
{
	vector<Point> points = Parse();
    std::sort(points.begin(), points.end(), 
             [](const Point& lhs, const Point& rhs) ->bool
              {
                 //�����Ŀ��Ҫ��x��С������� ���԰���x���� y�������� �ᰴ��y��С�������
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

//�Ѳ��� Ҳ��o(n*log(n)) ����vector�ڴ��ж�̬�仯�Ĵ���
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

//1.������o(n*n)��˼�� ������Ϊ��λ�ñ���ȥѡ���Ƿ���������
int main(void)
{
	MaxPoints();

	return 0;
}