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

//转换的3中方法
//1.左神 左边怎么样 右边怎么样 然后让最后一个节点只想头节点
//2.递归的中序遍历
//3.非递归的中序遍历