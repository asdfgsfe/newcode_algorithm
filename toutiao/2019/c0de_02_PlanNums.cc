#include <stdio.h>
#include <vector>
using std::vector;
 
long long PlanNums(const vector<long>& buildings, long d)
{
    if (buildings.size() < 3 || d < 1)
    {
        return 0;
    }
    long long cnt = 0;
    for (long i = 0; i < buildings.size(); ++i)
    {
        long l = i;
        long r = buildings.size() - 1;
        long target = -1;
		//当前位置i 距离i+d是我最远能到达的距离 由于是排序的找到第一个大于i+d距离的位置
		//以每个位置开头 找到能选择的组合
        while (l <= r)
        {
            long m = (r + l) / 2;
            if (buildings[m] <= buildings[i] + d)
            {
                target = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        long len = target - i;
        len = buildings[target] <= buildings[i] + d ? len : len - 1;
        cnt += len >= 2 ? len * (len - 1) / 2 : 0;
    }
    return cnt < 0 ? cnt + 99997867 : cnt % 99997867 ;
}
 
int main(void)
{
    long n;
    long d;
    scanf("%d%d", &n, &d);
    vector<long> buildings(n);
    for (long i = 0; i < n; ++i)
    {
        scanf("%ld", &buildings[i]);
    }       
    printf("%ld\n", PlanNums(buildings, d));
    return 0;
}