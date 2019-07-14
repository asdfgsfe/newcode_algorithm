#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
 
using std::vector;
using std::string;
using std::set;
 

//输入例子：
//ABC
//BCA

//设 table = A B C D E F G H I J
//个位权值 为 1
//十位权值 为 10
//百位权值 为 100
//依次类推， 没有出现的字母权值为 0

//则 A 的权重为 100 + 1  = 101
//B 的权重为    10 + 100 = 110
//C 的权重为    1 + 10   = 11
//D - J 的权重为   0


long long MaxMapping(const vector<string>& strs)
{
    vector<std::pair<char, long long>> charToWeights(10);
    vector<bool> heads(10, false);
    set<char> visited;
    for (const auto& str : strs)
    {
        heads[str[0] - 'A'] = true;
        long long move = 1;
        for (int i = str.size() - 1; i >= 0; --i)
        {
            charToWeights[str[i] - 'A'].second += move;
            charToWeights[str[i] - 'A'].first = str[i];
            visited.insert(str[i]);
            move *= 10;
        }
    }
    std::sort(charToWeights.begin(), charToWeights.end(),
        [](const auto& lhs, const auto& rhs) ->bool
        {
            return lhs.second > rhs.second;
        });
    //只有当所有字符出现时 才会存在首字母不能为0的情况
    //找到不是首字母且权重最小的那个char删除 因为他的会被0替换 不影响大局
    //然后从9~0对剩下的字符映射
    int zeroIdx = charToWeights.size() - 1;
    while (zeroIdx >= 0 && visited.size() == 10 && heads[charToWeights[zeroIdx].first - 'A'])
    {
        --zeroIdx;
    }
    int num = 9;
    long long maxSum = 0;
    for (int i = 0; i < charToWeights.size(); ++i)
    {
        if (i == zeroIdx)
        {
            continue;
        }
        maxSum += num * charToWeights[i].second;
        --num;
    }
    return maxSum;
}
 
 
int main(void)
{
    int n;
    std::cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> strs[i];
    }
    std::cout << MaxMapping(strs) << std::endl;
 
    return 0;
}
