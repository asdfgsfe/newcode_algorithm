#include <iostream>
#include <vector>

using std::vector;

//递归
//n的位置必然从到达偶数次n - 1位置到来 第一次到达n的时候从0~n-1每个位置经过的次数必然全部为偶数 如果不是偶数就不会前进1
//设f(n - 1)为此时n-1位置的次数 f(n -1)必为偶数 n位置只能从n-1到来 则要算出第二次到达f(n-1)的次数
//f(n) = f(n - 1) + 第二次到达n-1位置的次数 + 1 (1表示从n-1为偶数的情况下 从n-1 到 n)
//而n - 1位置会跳到pi[n - 1]位置 所以第二次到达n-1是从pi[n - 1]到达的 
//从0~pi[n-1]为f(pi[n-1]) 从0~n-1为f(n-1) 则从pi[n-1]到f(n-1)为 f(n-1) - f(pi[n-1]) + 1
//f(n) = f(n - 1) + f(n-1) - f(pi[n-1]) + 1 + 1
//f(n) = 2*f(n-1) - f(pi[n-1]) + 2
long long SkipProcess(const vector<int>& pis, int n)
{
	if (n == 1)
	{
		return 0;
	}
	return (2 * SkipProcess(pis, n - 1) - SkipProcess(pis, pis[n - 1]) + 2) % 1000000007;
}

//dp
long long SkipDp(const vector<int>& pis, int n)
{
    vector<long long> dp(n + 1, 0);
    for (int i = 2; i < dp.size(); ++i)
    {
        dp[i] = (2 * dp[i - 1] - dp[pis[i - 1]] + 2) % 1000000007;
    }
    return dp.back();
}


int main(void)
{
	int n;
	std::cin >> n;
	vector<int> pis(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> pis[i];
	}
    long long skipTimes = SkipProcess(pis, n + 1);
	std::cout << (skipTimes < 0 ? skipTimes + 1000000007 : skipTimes % 1000000007) << std::endl;
	
	return 0;
}


//别人的分析
//仔细分析 1<=pi<=i 知道用动态规划做。
//记录第一次到达i为dp[i]，此时前面的所有门肯定是已经到达偶数次了
//因为传送只会后退，前进的唯一方式是偶数次到达并+1，不能跳跃
//所以到达i门前面所有门都走过并且经过偶数次（反正法也可以证明）
//dp[i]=dp[i-1]+第二次到达i-1 + 1
//第一次到达i-1门后再走一步会回到p[i-1]，此时p[i-1]门到达奇数次，其他所有门到达偶数次
//这和第一次到达p[i-1]门的情况完全相同，所以从p[i-1]门回到i-1门，需要dp[i-1]-dp[p[i-1]]
//所以dp[i] = dp[i-1] + dp[i-1] - dp[p[i-1]] + 1 + 1
//dp[i] = 2 * dp[i-1] - dp[p[i-1]] + 2

#include <iostream>
using namespace std;
 
long long p[1001], dp[1001], n;
const long long mod = 1e9?+?7;
 
int main (){
    cin >> n;
    for (int i = 1; i<= n; ++i) cin >> p[i];
    for (int i = 2; i<= n+1; ++i)
        dp[i] = (2 * dp[i-1] - dp[p[i-1]] + 2) % mod;
    cout << (dp[n + 1] < 0 ? dp[n + 1] + mod : dp[n + 1]);
}