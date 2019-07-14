#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
 
using std::vector;
using std::string;
using std::set;
 

//�������ӣ�
//ABC
//BCA

//�� table = A B C D E F G H I J
//��λȨֵ Ϊ 1
//ʮλȨֵ Ϊ 10
//��λȨֵ Ϊ 100
//�������ƣ� û�г��ֵ���ĸȨֵΪ 0

//�� A ��Ȩ��Ϊ 100 + 1  = 101
//B ��Ȩ��Ϊ    10 + 100 = 110
//C ��Ȩ��Ϊ    1 + 10   = 11
//D - J ��Ȩ��Ϊ   0


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
    //ֻ�е������ַ�����ʱ �Ż��������ĸ����Ϊ0�����
    //�ҵ���������ĸ��Ȩ����С���Ǹ�charɾ�� ��Ϊ���Ļᱻ0�滻 ��Ӱ����
    //Ȼ���9~0��ʣ�µ��ַ�ӳ��
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
