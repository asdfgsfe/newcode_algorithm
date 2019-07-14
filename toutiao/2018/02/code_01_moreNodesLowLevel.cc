//1.树的深度等于层数 在知道深度的情况下求层数可以用深度遍历 
//遍历到每个节点的时候将 每个节点的孩子数量加起来 遍历到每个孩子的时候将同一层的加起来
//2.不知道树最大深度的情况下 可以用层序遍历 统计每个节点 适合孩子节点是链表存储的
struct Node
{
	vector<Node*> children;
};

//bfs层序
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
    counter[dep] += node->scons.size(); //也可以counter[dep++]++;类似于map记录每一层的节点
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
	::bzero(&depCounter, sizeof 100000); //初始化很重要
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