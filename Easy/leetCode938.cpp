#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        vector<TreeNode*> dfs;

        dfs.push_back(root);

        while(dfs.size()) {
            TreeNode* temp = dfs.back();
            dfs.pop_back();

            if(temp->left != nullptr) {
                dfs.push_back(temp->left);
            }
            if(temp->right != nullptr) {
                dfs.push_back(temp->right);
            }
            if(temp->val <= high && temp->val >= low) res += temp->val; 
        }


        return res;
    }
};