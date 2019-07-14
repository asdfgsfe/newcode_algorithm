#include <iostream>
#include <vector>
#include <algorithm>
 
using std::vector;

//��������m�Լ�n������A1,A2,..An��������A������Ԫ��������򣬹��ܵõ�n(n-1)/2�������
//�������Щ����д���m���ж��ٸ���

//��������:
//��һ�а�����������n,m. 

//�ڶ��и���n������A1��A2��...��An��

//���ݷ�Χ

//����30%�����ݣ�1 <= n, m <= 1000

//����100%�����ݣ�1 <= n, m, Ai <= 10^5

//�������:
//���������һ�У�������Ĵ�

//��������1:
//3 10  
//6 5 10

//�������1:
//2


//���ǵ��Ӹ�λ����λ�����ν���λ���㣬
//����������������ĳ��λΪ1����m�Ķ�ӦλΪ0��//���ڷ���Ϊ����
//��϶��κ�����λ�����Ϊ1�Ķ����m��
//�ɴˣ�����ʹ���ֵ�����TrieTree���Ӹ�λ����λ�����ֵ䣬
//��ʹ��ÿ��Ԫ������ȥ�ֵ��в��Ӧ��λ���Ϊ1�� 
//��mΪ0�����ĸ���������ڳ���2�������յĽ����ֱ�������������£���ԭ������ӭ���ۣ�
//���䣺queryTrieTree�������Ĺ����У��ǴӸ�λ����λ������
//��ô�������һ�������ֵ��е���������ĵ�kλ����m�ĵ�kλ��
//��ô�������Ӧ��֧�����е���������������m�� 
//���򣬾�Ҫ�����ڵ�kλ�����ȵ�����£�
//����λ���������queryTrieTree���ĸ���֧�����÷ֱ����£�
//1. aDigit=1�� mDigit=1ʱ���ֵ��е�kλΪ0�������Ϊ1��
//��Ҫ������������λ����kλΪ1�������Ϊ0��С��mDigit��������᣻
//2. aDigit=0�� mDigit=1ʱ���ֵ��е�kλΪ1�������Ϊ1��
//��Ҫ������������λ����kλΪ0�������Ϊ0��С��mDigit��������᣻
//3. aDigit=1�� mDigit=0ʱ���ֵ��е�kλΪ0�������Ϊ1��
//���Ӧ��֧��������򣬽���������m����kλΪ1�������Ϊ0���ݹ��ý����
//4. aDigit=0�� mDigit=0ʱ���ֵ��е�kλΪ1�������Ϊ1��
//���Ӧ��֧��������򣬽���������m����kλΪ0�������Ϊ0���ݹ��ý����

struct Node
{
	long long path;
	vector<Node*> nexts;
	Node()
		: path(0), nexts(2, nullptr)
	{}
};

class NumberTrie
{
public:
	NumberTrie()
	    :  root_(new Node())
	{}

	void AddNum(int num)
	{
		Node* cur = root_;
		for (int move = 31; move >= 0; --move)
		{
			int path = (num >> move) & 1;
			if (!cur->nexts[path])
			{
				cur->nexts[path] = new Node();
			}
			cur = cur->nexts[path];
            ++cur->path;
		}
	}

	long long EorMoreMCnt(Node* node, int num, int m, int index)
	{
		if (!node)
        {
            return 0;
        }
        Node* cur = node;
		for (int move = index; move >= 0; --move)
		{
			int path = (num >> move) & 1;
			int mPath = (m >> move) & 1;
			if (path == 1 && mPath == 1)
			{
				if (!cur->nexts[0])
				{
					return 0;
				}
				cur = cur->nexts[0];
			}
			else if (path == 1 && mPath == 0)
			{
				long cnt = EorMoreMCnt(cur->nexts[1], num, m, move - 1);
				return cur->nexts[0] ? cur->nexts[0]->path + cnt : cnt;
			}
			else if (path == 0 && mPath == 1)
			{
				if (!cur->nexts[1])
				{
					return 0;
				}
				cur = cur->nexts[1];
			}
			else//path == 0 mPath == 0
			{
				long long cnt = EorMoreMCnt(cur->nexts[0], num, m, move - 1);
				return cur->nexts[1] ? cur->nexts[1]->path + cnt : cnt;
			}
		}
		return 0;
	}
    
    Node* Root() const { return root_; }
private:
	Node* root_;
};
 

 //�ܽ�������͵�����
 //1.����e1 ^ e2 = e3 e3 ^ e2 = e1 ������ ��i~j��һ�ε����� 
 //2.���Ҫѡ�����ĳһ�� ���ߴ��ڵ���� ����trie��ȥ������ 
 //����1 2 ���������������trie����
int main(void)
{
    int n;
    int m;
    std::cin >> n >> m;
    vector<int> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }
	NumberTrie nTrie;
	nTrie.AddNum(as[0]);
	long long cnt = 0; //ע������
    for (int i = 1; i < as.size(); ++i)
    {
		cnt += nTrie.EorMoreMCnt(nTrie.Root(), as[i], m, 31);
		nTrie.AddNum(as[i]);
    }
	std::cout << cnt << std::endl;
    return 0;
}