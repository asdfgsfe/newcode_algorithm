TreeNode* Convert(TreeNode* root)
{  
    if (root == NULL)  
        return root;
    TreeNode* listHead = NULL;
    TreeNode* listLastNode = NULL;
    stack<TreeNode*> s;
    while(root || !s.empty()) //
    {
        while(root)
        {
            s.push(root);    //
            root=root->left;
        }
        root =s.top();  
        s.pop();
        if (!listHead)
        {
            listHead = root;
        }
		if (listLastNod)
		{
			listLastNode->right = root
		}
        root->left = listLastNode; //
        listLastNode = root;
        root = root->right;
    }
    return listHead;
}

//ת����3�з���
//1.���� �����ô�� �ұ���ô�� Ȼ�������һ���ڵ�ֻ��ͷ�ڵ�
//2.�ݹ���������
//3.�ǵݹ���������