#include <iostream>
#include <vector>

using std::vector;

int MinCount(const vector<int>& conis, int aim)
{
    if (aim < 1 || conis.empty())
    {
        return 0;
    }
    vector<int> dp(aim + 1, 0x7fffffff);
    dp[0] = 0;
    for (int i = 1; i < dp.size(); ++i)
    {
        for (int c : conis)
        {
            if (i - c >= 0 && dp[i - c] != 0x7fffffff)
            {
                dp[i] = std::min(dp[i], dp[i - c] + 1);
            }
        }
    }
    return dp[aim];
}
//f(s) = f(s - c) + 1 c属于所有金币
int main(void)
{
    vector<int> conis{1, 4, 16, 64};
    int cost;
    std::cin >> cost;
    std::cout << MinCount(conis, 1024 - cost) << std::endl;;
    return 0;
}
