#include <iostream>
#include <vector>

using std::vector;
int d;
int ArrestProcess(const vector<int>& axis, int i, int aim, vector<int>& target)
{
    if (aim == 0)
    {
        return (target[2] - target[0] <= d) ? 1 : 0;
    }
    if (i == axis.size())
    {
        return 0;
    }
    target.emplace_back(axis[i]);
    int includeIt = ArrestProcess(axis, i + 1, aim - 1, target);
    target.pop_back();
    int notIncludeIt = ArrestProcess(axis, i + 1, aim, target);
    return includeIt + notIncludeIt;
}

int ArrestWays(const vector<int>& axis)
{
    if (axis.size() < 3)
    {
        return 0;
    }
    vector<int> target;
    return ArrestProcess(axis, 0, 3, target);
}

int main(void)
{
    int n;
    std::cin >> n >> d;
    vector<int> axis(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> axis[i];
    }
    std::cout << ArrestWays(axis) << std::endl;
    return 0;
}