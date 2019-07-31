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
		//���굱ǰ�ַ�
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
		//���굱ǰ�ַ�����һ���ַ� ȥ������
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

//�ҽ����󴸣���һ�ҳ�����ı༭���Ҹ���У��Ͷ������Ӣ�ĸ������ݹ����ǳ����ˣ�
//��Ϊÿ�춼Ҫȥ����������ƴд����
//���ǣ��������������ƽ���Ĺ����з��������ҷ���һ������ƴд����Ľݾ���

//1. ����ͬ������ĸ����һ��һ����ƴд����ȥ��һ���ľͺ��������� helllo -> hello
//2. ����һ������ĸ��AABB�ͣ�����һ��һ����ƴд����ȥ���ڶ��Ե�һ����ĸ�ͺ��������� helloo -> hello
//3. ����Ĺ������ȡ������ҡ�ƥ�䣬�������AABBCC����ȻAABB��BBCC���Ǵ���ƴд��
//Ӧ�����ȿ����޸�AABB�����ΪAABCC

//�������Ǹ���ţ���������ѧ���ھ���ͳ�����ƣ��������ԭ��д��һ���Զ�У������
//����Ч�ʴӴ���ɡ��ò��˶�ã��Ҿͻ����CEO�����϶��³���ӭȢ�׸��������������۷壬���붼�е�С�����أ�
//����û�뵽���ұ������ˣ�����ʱ�ϰ����˵�� ����������Ҫ����ҵҵ�����ڿҿҡ������ַ֣���Ҫ���У���һ����һ�С�
//һ���������У�Ҫ�ǲ��У���һ�в���һ�У�һ�в������в��С��� �����������˺����л��㱵ġ���

//�����⣺��ʵ�ִ󴸵��Զ�У�Գ���

//��������:
//��һ�а���һ������N����ʾ���������������ٸ���У����ַ�����

//�������N�У�ÿ��Ϊһ����У����ַ�����

//�������:
//N�У�ÿ�а���һ�����޸�����ַ�����

//��������1:
//2
//helloo
//wooooooow

//�������1:
//hello
//woow