#include <iostream>
#include <vector>

using std::vector;

//�ݹ�
//n��λ�ñ�Ȼ�ӵ���ż����n - 1λ�õ��� ��һ�ε���n��ʱ���0~n-1ÿ��λ�þ����Ĵ�����Ȼȫ��Ϊż�� �������ż���Ͳ���ǰ��1
//��f(n - 1)Ϊ��ʱn-1λ�õĴ��� f(n -1)��Ϊż�� nλ��ֻ�ܴ�n-1���� ��Ҫ����ڶ��ε���f(n-1)�Ĵ���
//f(n) = f(n - 1) + �ڶ��ε���n-1λ�õĴ��� + 1 (1��ʾ��n-1Ϊż��������� ��n-1 �� n)
//��n - 1λ�û�����pi[n - 1]λ�� ���Եڶ��ε���n-1�Ǵ�pi[n - 1]����� 
//��0~pi[n-1]Ϊf(pi[n-1]) ��0~n-1Ϊf(n-1) ���pi[n-1]��f(n-1)Ϊ f(n-1) - f(pi[n-1]) + 1
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


//���˵ķ���
//��ϸ���� 1<=pi<=i ֪���ö�̬�滮����
//��¼��һ�ε���iΪdp[i]����ʱǰ��������ſ϶����Ѿ�����ż������
//��Ϊ����ֻ����ˣ�ǰ����Ψһ��ʽ��ż���ε��ﲢ+1��������Ծ
//���Ե���i��ǰ�������Ŷ��߹����Ҿ���ż���Σ�������Ҳ����֤����
//dp[i]=dp[i-1]+�ڶ��ε���i-1 + 1
//��һ�ε���i-1�ź�����һ����ص�p[i-1]����ʱp[i-1]�ŵ��������Σ����������ŵ���ż����
//��͵�һ�ε���p[i-1]�ŵ������ȫ��ͬ�����Դ�p[i-1]�Żص�i-1�ţ���Ҫdp[i-1]-dp[p[i-1]]
//����dp[i] = dp[i-1] + dp[i-1] - dp[p[i-1]] + 1 + 1
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