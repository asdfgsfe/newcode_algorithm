#include<iostream>
#include<string>
#include <vector>

using std::string;
using std::vector;
 
//��鵱ǰ���䳤��(step)�Ƿ����� m ��������ʵ��ȫ a �� ȫ b 
bool IsDoneReplace(const vector<int>& aSums, int step, int m, int n)
{
    for(int i = 0; i + step < n; i++)
	{
        
		if (m >= step + 1 - (aSums[i + step] - aSums[i - 1]))//�滻a  ��ʽ m>=������ ͳ��b�ĸ���
        {
			return true;
        }	
		if (m >= aSums[i + step] - aSums[i - 1])//�滻 b  ��ʽ�� m>=������ ͳ��a�ĸ���
		{
			return true;
		}	 
    }
    return false;
}
 
int main(void)
{
	int n;
	int m;
    cin >> n >> m;
    string str;
    cin >> str;
    //���벢����� count ���� 
    int asum=0;
	vector<int> aSums(str.size(), 0);
    for(int i = 0;i < str.size(); i++)
	{
        if (str[i]=='a')
        {
			aSums[i] = ++asum;
        }
        else 
		{
			aSums[i] = asum;
		}
    }
 
    //���������������ֵ ������̰�� ���ö��ִ𰸵ķ���
	//���ڴ����ֵ�̶���������Ŀ ���Կ��Ƕ��ִ𰸵�˼· ������һ��ȥ�Ͻ缴l
	//�����Сһ��ȡ�½�r ����ĳ��Ψһ������ȥ����
	int l = 0;
	int r = n-1;
    while (l <= r)
	{
        int mid = l + (r - l) / 2;
        if (IsDoneReplace(aSums, mid, m, n))
		{
            l = mid + 1;
        }
		else 
		{
			r = mid - 1;
		}
		std::cout << "l=" << l << " r=" << r << std::endl;
    }
   std::cout << l << std::endl; //ȥ�Ͻ�
    return 0;
     
}

�ȴ�0��ʼ��(l+r)/2Ϊstep��ȥ�� ����ҵ���l������ ���Դ�ʱ��(l + r)/2ȥ��
�൱����ԭ����step���ڼ��Ϻ�߲��ֵ�һ��
����i~j a��b������ �ֶ����¾�֪����
8 1
babaabaa
i=0 step=3 i+step=3
i=1 step=3 i+step=4
l=4 r=7 mid=3
i=0 step=5 i+step=5
i=1 step=5 i+step=6
i=2 step=5 i+step=7
l=4 r=4 mid=5
i=0 step=4 i+step=4
i=1 step=4 i+step=5
i=2 step=4 i+step=6
i=3 step=4 i+step=7
l=5 r=4 mid=4
5
--------------------- 
���ߣ�bobbymly 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/bobbymly/article/details/79267864 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�


���ַ����� a �� b Ҳ����˵������ l~r֮��������ַ���Ϊ a ����Ĳ������� �������� b ����������֮��Ȼ.
������ count[i] ��ʾ �ַ�����λ������ 0~i ������ a �ĸ���
�� ���� l~r �� a �ĸ���Ϊ count[r]-count[l-1]
b �ĸ����� a �ĸ������ �� ���� l~r �� b �ĸ���Ϊ r+1-count[r]-(l+1-1-count[l-1])=r+1-count[r]-l+count[l-1]

������ l~r �� a �� b �ĸ�����֪�������
�� ���䳤��step�ڵ� a �ĸ��� <= m �� ����ͨ�� m ������ ���� ����Ϊstep���ַ��� b
�� ���䳤��step�ڵ� b �ĸ��� <= m �� ����ͨ�� m ������ ���� ����Ϊstep���ַ��� a

����Ϊ ���� ���䳤��step�ڵ� b �� a �ĸ��� <= m �� ����ͨ�� m ������ ���� ����Ϊstep���ַ���

����  �Ϳ���ֱ�Ӽ����һ���ַ������ȣ����䳤��step���Ƿ���У���˲���Ҫ���е��ƣ�����ֱ�ӽ��ж����������õ���󳤶ȡ�
���һ������step�Ƿ���е�ʱ�临�Ӷ�ΪO(n),����������ʱ�临�Ӷ�ΪO(log n)��
--------------------- 
���ߣ�bobbymly 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/bobbymly/article/details/79267864 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�