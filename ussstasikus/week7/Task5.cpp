//
// Created by Stas Don on 21/04/2018.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool checkSubtree(TreeNode* node, long min_el, long max_el) {
        if (!node)
            return true;
        if (node->val >= max_el || node->val <= min_el)
            return false;
        else
            return checkSubtree(node->left, min_el, node->val) && checkSubtree(node->right, node->val, max_el);
    }

    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return checkSubtree(root->left, LONG_MIN, root->val) && checkSubtree(root->right, root->val, LONG_MAX);
    }
};

