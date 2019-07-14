//1.������ȵ��ڲ��� ��֪����ȵ�������������������ȱ��� 
//������ÿ���ڵ��ʱ�� ÿ���ڵ�ĺ������������� ������ÿ�����ӵ�ʱ��ͬһ��ļ�����
//2.��֪���������ȵ������ �����ò������ ͳ��ÿ���ڵ� �ʺϺ��ӽڵ�������洢��
struct Node
{
	vector<Node*> children;
};

//bfs����
int MoreNodeLowLevel1(const Node* pRoot, int depth)
{
	if (!pRoot | depth < 1)
	{
		return 0;
	}
	queue<const Node*> nodes;
	nodes.push(pRoot);
	int lowLevel = 0;
	while (!nodes.empy())
	{
		int size = nodes.size();
		lowLevel = size > lowLevel ? size : lowLevel;
		while (size--)
		{
			pRoot = nodes.front();
			nodes.pop();
			for (const Node* pNode : pRoot->scons)
			{
				if (pNode)
				{
					nodes.push(pNode);
				}
			}
		}
	}
	return lowLevel
}

//dfs
void dfsFind(Node *node, int dep, int counter[]) {
	if (!node || dep == 100000)
	{
		return;
	}
    counter[dep] += node->scons.size(); //Ҳ����counter[dep++]++;������map��¼ÿһ��Ľڵ�
    for(int i = 0; i < node->sons.size(); i++) {
        dfsFind(node->sons[i], dep + 1, counter);
    }
}

int find(Node *root, int maxDep) {
	if (!root || maxDep < 1)
	{
		return 0;
	}
    int depCounter[100000];
	::bzero(&depCounter, sizeof 100000); //��ʼ������Ҫ
	depCount[0] = 1;
    dfsFind(root, 1, depCounter);

    int max = 0x80000000;
	int lowLevel = 0;;
    for (int i = 1; i <= maxDep; i++) {
        if (depCounter[i] > max) {
            max = depCounter[i];
            lowLevel = i;
        }
    }
    return lowLevel;
}