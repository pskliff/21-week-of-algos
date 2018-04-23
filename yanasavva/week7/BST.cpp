#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };


class BST
{
public:
    TreeNode *root;
    void addNode(int val)
    {
        if (!root)
            root = new TreeNode(val);
        else{

        }
    }
    void addNodeBST(int val)
    {
        if (!root)
            root = new TreeNode(val);
        else
            {
                TreeNode *curr = root;
                while (curr)
                {
                    if (val > curr->val)
                    {
                        if (!curr->right)
                        {
                            curr->right = new TreeNode(val);
                            return;
                        }else curr = curr->right;
                    }
                    else if (!curr->left)
                    {
                        curr->left = new TreeNode(val);
                        return;
                    }else curr = curr->left;
                }
            }

    }
};


bool isValidBST(TreeNode *root)
{
    bool valid_left = false, valid_right = false;
    if(!root->left)
        valid_left = true;
    if (!root->right)
        valid_right = true;
    if (root->left && root->val > root->left->val)
        valid_left = isValidBST(root->left);
    if (root->right && root->val < root->right->val)
        valid_right = isValidBST(root->right);

    return  valid_left && valid_right;
}


bool recursiveSymmetric(TreeNode *left, TreeNode *right)
{
    if(!left && !right)
        return true;
    else if (!left || !right)
        return false;
    if (left->val != right->val)
        return false;
    else
        return recursiveSymmetric(left->right, right->left) &&
               recursiveSymmetric(left->left, right->right);
}

bool isSymmetric(TreeNode *root)
{
    return recursiveSymmetric(root->left, root->right);
}


int main()
{
    ifstream fin;
    fin.open("input.txt");
    int n;
    fin >> n;
    BST tree;
    int num;
    fin >> num;
    tree.root = new TreeNode(num);
    TreeNode *nodes[n];
    nodes[0] = tree.root;
    for (int i = 1; i < n; ++i)
    {
        int num;
        fin >> num;
        TreeNode *node = new TreeNode(num);
        if (i % 2 == 0)
            nodes[(i - 2) / 2]->right = node;
        else nodes[i / 2]->left = node;
        nodes[i] = node;
    }
    fin.close();

//    cout << isValidBST(tree.root);
    cout << isSymmetric(tree.root);
    return 0;
}