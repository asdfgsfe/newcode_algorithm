#include <stdio.h>
#include <vector>

using std::vector;

int LessCoinNum(int n)
{
    if (n <= 0 || n >= 1024)
    {
        return 0;
    }
    int aim = 1024 - n;
    int cnt = 0;
    cnt += aim / 64;
    aim %= 64;
    cnt += aim / 16;
    aim %= 16;
    cnt += aim / 4;
    aim %= 4;
    cnt += aim / 1;
    
    return cnt;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", LessCoinNum(n));
    
    return 0;
}

Z国的货币系统包含面值1元、4元、16元、64元共计4种硬币，以及面值1024元的纸币。
现在小Y使用1024元的纸币购买了一件价值为的商品，请问最少他会收到多少硬币？

输入描述:
一行，包含一个数N。

输出描述:
一行，包含一个数，表示最少收到的硬币数。

输入例子1:
200

输出例子1:
17

例子说明1:
花200，需要找零824块，找12个64元硬币，3个16元硬币，2个4元硬币即可。