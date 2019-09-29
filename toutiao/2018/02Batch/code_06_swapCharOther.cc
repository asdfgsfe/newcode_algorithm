//思路是这样的，我们对每一个字母分别求可能连接的成的最大距离。
//这时候就需要用26个列表，来分别保存每个字母的出现在原字符串中的位置（代码中v表示）。
//我们下面针对一个字母考虑：
//dp[i][j]:表示v中第i到第j个位置的字母如果需要移动到在一起，需要移动的次数。
//那么转移方程就有了

//dp[left][right] = dp[left+1][right-1] + (v[right] - v[left] - 1) - (right - left - 1)

//这里做一下说明：
//对于最左边位置left和最右边位置right字符串，如果只需要将这俩字符移动在一起，
//则需要固定的(v[right] - v[left] - 1)次移动，但是这个区间内已经有了移动好的(right - left - 1)个字母，
//所以可以少移动这么多次，固需要减去这个数字。

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
 
string str;
int m;
 
int cnt(const vector<int>& vec) {
    int n = vec.size();
    vector< vector<int> > dp(n, vector<int>(n, 0));
    for(int i=0; i<n-1; ++i) {
        dp[i][i+1] = abs(vec[i+1] - vec[i]) - 1;
    }
    for(int j=2; j<n; ++j) {
        for(int i=0; i<n-j; ++i) {
            int row = i, col = i+j;
            dp[row][col] = dp[row+1][col-1] + abs(vec[col] - vec[row]) - (col-row);
        }
    }
    int Max = 0;
    for(int i=0; i<n; ++i) {
        for(int j=i; j<n; ++j) {
            if (dp[i][j] <= m) {
                Max = max(Max, j-i+1);
            }
        }
    }
    return  Max;
}
 
 //别人的代码 思考下ac
int main()
{
    cin >> str >> m;
    vector< vector<int> > vec(26);
    for(int i=0; i<str.size(); ++i) {
        vec[str[i]-'a'].push_back(i);
    }
    int Max = 0;
    for(int k=0; k<26; ++k) {
        Max = max(Max, cnt(vec[k]));
    }
    cout << Max << endl;
    return 0;
}