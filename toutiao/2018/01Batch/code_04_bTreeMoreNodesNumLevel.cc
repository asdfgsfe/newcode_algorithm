����һ�����ĸ��ڵ�, ����֪���������ȵ������, ��ڵ���������һ�㲢���ؾ���Ĳ�����
��������ж��, �����ǳ����һ�㣬������Ȳ��ᳬ��100000��ʵ�ִ������£���ָ�������еĶദ����

struct Node {
    vector<Node*> sons;
};

void dfsFind(Node *node, int dep, int counter[]) {
    counter[dep]++;
    for(int i = 0; i < node.sons.size(); i++) {
        dfsFind(node.sons[i], dep, counter);
    }
}

 
int find(Node *root, int maxDep) {
    int depCounter[100000];
    dfsFind(root, 0, depCounter);
    int max, maxDep;
    for (int i = 1; i <= maxDep; i++) {
        if (depCounter[i] > max) {
            max = depCounter[i];
            maxDep = i;
        }
    }
    return maxDep;
}

//2�ַ��� �����ǰ����� 
//�����򶼿��� ��������ǰ��
void dfsFind(Node *node, int dep, int counter[]) {
	if (!node)
	{
		return;
	}
    counter[dep]++;
    for(int i = 0; i < node->sons.size(); i++) {
        dfsFind(node->sons[i], dep + 1, counter);
    }
}

 
int find(Node *root, int maxDep) {
    int depCounter[100000];
	::memset(depCounter, 0, sizeof depCounter); // bzero(depCOunter, sizeof depCOunter);
    dfsFind(root, 0, depCounter);
    int max = 0;
	int minLevel = 0;
    for (int i = 1; i <= maxDep; i++) {
        if (depCounter[i] > max) {
            max = depCounter[i];
            minLevel = i;
        }
    }
    return minLevel;
}
