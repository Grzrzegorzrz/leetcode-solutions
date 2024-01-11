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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode*> dfs;
        vector<int> seq1;
        seq1.reserve(200);
        vector<int> seq2;
        seq2.reserve(200);

        dfs.push_back(root1);
        while(!dfs.empty()) {
            TreeNode* temp = dfs.back();
            dfs.pop_back();

            if(temp->left == nullptr && temp->right == nullptr) {
                seq1.push_back(temp->val);
                continue;
            }

            if(temp->left != nullptr) {
                dfs.push_back(temp->left);
            }

            if(temp->right != nullptr) {   
                dfs.push_back(temp->right);
            }
        }

        dfs.push_back(root2);
        while(!dfs.empty()) {
           TreeNode* temp = dfs.back();
            dfs.pop_back();

            if(temp->left == nullptr && temp->right == nullptr) {
                seq2.push_back(temp->val);
                continue;
            }

            if(temp->left != nullptr) {
                dfs.push_back(temp->left);
            }

            if(temp->right != nullptr) {   
                dfs.push_back(temp->right);
            }
        }

        return seq1 == seq2;
    }
};