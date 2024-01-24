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
    int dfs(TreeNode* curr, vector<int>& record) {
        int val = curr->val;
        TreeNode* left = curr->left;
        TreeNode* right = curr->right;
        int sum = 0;

        record[val]++;

        //leaf
        if(!left && !right) {
            int odds = 0;
            for(int i : record) {
                if(i % 2 == 1) odds++;
            }

            record[val]--;
            return odds < 2; //false is 0, true is 1
        }

        if(left)
            sum += dfs(left, record);

        if(right)
            sum += dfs(right, record);

        record[val]--;
        return sum;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> record(10, 0);

        return dfs(root, record);
    }
};
