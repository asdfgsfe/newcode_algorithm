#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

void StringCheck(const string& str)
{
    if (str.empty())
    {
        return;
    }
    int cur = 0;
    string ret;
    while (cur < str.size())
    {
        int next = cur + 1;
		//找完当前字符
        while (next != str.size() && str[next] == str[cur])
        {
            ++next;
        }
        if (next - cur == 1)
        {
            ret += str[cur];
            cur = next;
            continue;
        }
        int mid = next;
		//找完当前字符的下一个字符 去做衡量
        while (next != str.size() && str[next] == str[mid])
        {
            ++next;
        }
        ret += str.substr(cur, 2) + str[mid];
        cur = next;
    }
    std::cout << ret << std::endl;
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
    for (const auto& str : strs)
    {
        StringCheck(str);
    }
    return 0;
}