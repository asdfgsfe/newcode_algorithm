#include <iostream>
#include <vector>

using std::vector;

//由于是排序的 可以用滑动窗口模型
int ArrestWays(const vector<int>& axis, int d)
{
    if (axis.size() < 3)
    {
        return 0;
    }
    int cnt = 0;
    int l = 0;
    int r = 0;
    int pre = 0;
    while (r < axis.size())
    {
        while (r < axis.size() && axis[r] - axis[l] <= d)
        {
            ++r;
        }
        int len = r - l;
        len = (r < axis.size() && axis[r] == axis[l] + d) ? len + 1 : len;
        cnt += len * (len - 1) * (len - 2) / 6 - //可以做出来就是计算重复值太麻烦了
    }
}

int main(void)
{
    int n;
    int d;
    std::cin >> n >> d;
    vector<int> axis(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> axis[i];
    }
    std::cout << ArrestWays(axis) << std::endl;
    return 0;
}