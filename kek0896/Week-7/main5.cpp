//
// Created by Маргарита Мариампиллай on 21.04.2018.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root, long min, long max){
        if(!root)   return true;
        return (root->val > min && root->val < max)
               && (isValidBST(root->left, min, root->val)
                   && isValidBST(root->right, root->val, max));
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

};