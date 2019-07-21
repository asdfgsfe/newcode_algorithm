//˼·�������ģ����Ƕ�ÿһ����ĸ�ֱ���������ӵĳɵ������롣
//��ʱ�����Ҫ��26���б����ֱ𱣴�ÿ����ĸ�ĳ�����ԭ�ַ����е�λ�ã�������v��ʾ����
//�����������һ����ĸ���ǣ�
//dp[i][j]:��ʾv�е�i����j��λ�õ���ĸ�����Ҫ�ƶ�����һ����Ҫ�ƶ��Ĵ�����
//��ôת�Ʒ��̾�����

//dp[left][right] = dp[left+1][right-1] + (v[right] - v[left] - 1) - (right - left - 1)

//������һ��˵����
//���������λ��left�����ұ�λ��right�ַ��������ֻ��Ҫ�������ַ��ƶ���һ��
//����Ҫ�̶���(v[right] - v[left] - 1)���ƶ�����������������Ѿ������ƶ��õ�(right - left - 1)����ĸ��
//���Կ������ƶ���ô��Σ�����Ҫ��ȥ������֡�

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
 
 //���˵Ĵ��� ˼����ac
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