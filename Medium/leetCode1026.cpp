//should come back and optimize

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
    int maxAncestorDiff(TreeNode* root) {
        unordered_map<TreeNode*, array<int, 2>> minMax;
        queue<TreeNode*> q;
        int maxDiff = 0;

        q.push(root);
        minMax[root] = {100000, 0};

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            TreeNode* left = temp->left;
            TreeNode* right = temp->right;
            int val = temp->val;
            int currMax;
            int currMin;

            currMin = min(val, minMax[temp][0]);
            currMax = max(val, minMax[temp][1]);

            int out = max(abs(currMin-val), abs(currMax-val));
            if(out > maxDiff) maxDiff = out;

            if(left != nullptr) {
                q.push(left);
                minMax[left] = {currMin, currMax};
            }

            if(right != nullptr) {
                q.push(right);
                minMax[right] = {currMin, currMax};
            }
        }

        return maxDiff;
    }
};
