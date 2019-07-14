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
        if (listHead == NULL)
        {
            listHead = root;
        }
        else
        {
            root->left = listLastNode; //
            assert(listLastNode);
            listLastNode->right = root;
        }
        listLastNode = root;
        root = root->right;
    }
    return listHead;
}