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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, array<int,3>> m;
        unordered_map<int, int> traversed;
        unordered_map<int, int> distMap;
        queue<TreeNode*> q;
        int max = 0;

        q.push(root);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            TreeNode* left = temp->left;
            TreeNode* right = temp->right;
            int val = temp->val;

            q.pop();

            if(left != nullptr) {
                q.push(left);
                m[val][1] = left->val;
                m[left->val][0] = val;
            }

            if(right != nullptr) {
                q.push(right);
                m[val][2] = right->val;
                m[right->val][0] = val;
            }
        }

        queue<int> q2;
        q2.push(start);

        while(!q2.empty()) {
            int current = q2.front();
            traversed[current]++;
            q2.pop();

            for(int i : m[current]) {
                if(i && !traversed[i]) q2.push(i);
                else continue;
                distMap[i] = distMap[current] + 1;
                if(distMap[i] > max) max = distMap[i];
            }
        }
    
        return max;
    }
};