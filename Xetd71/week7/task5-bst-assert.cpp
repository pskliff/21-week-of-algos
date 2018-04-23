#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool isValidBST(TreeNode* root, long maxVal, long minVal) {
    if(!root)
        return true;
    if(root->val >= maxVal || root->val <= minVal)
        return false;
    return isValidBST(root->left, root->val, minVal) && isValidBST(root->right, maxVal, root->val);
}

bool isValidBST(TreeNode* root) {
    return isValidBST(root, INT64_MAX, INT64_MIN);
}

int main() {
    TreeNode* root = new TreeNode(INT32_MAX);
    cout << isValidBST(root);
    delete root;
}