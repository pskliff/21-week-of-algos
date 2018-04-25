#include <iostream>


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;


    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {}
};

bool isValidRec(TreeNode* root, TreeNode* min_node, TreeNode* max_node)
{
    if(!root)
        return true;
    if(min_node && root->val <= min_node->val || max_node && root->val >= max_node->val)
        return false;
    return isValidRec(root->left, min_node, root) && isValidRec(root->right, root, max_node);
}


bool isValidBST(TreeNode* root)
{
    return isValidRec(root, nullptr, nullptr);
}


int main()
{

    return 0;
}