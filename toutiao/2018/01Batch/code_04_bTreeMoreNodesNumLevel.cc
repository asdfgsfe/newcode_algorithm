给定一棵树的根节点, 在已知该树最大深度的情况下, 求节点数最多的那一层并返回具体的层数。
如果最后答案有多层, 输出最浅的那一层，树的深度不会超过100000。实现代码如下，请指出代码中的多处错误：

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

//2种方法 层序和前序遍历