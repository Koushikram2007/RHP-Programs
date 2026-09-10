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
    int count=0,sum=0,avgcnt=0;
    void sumdfs(TreeNode* root){
        if (root!=NULL){
            count++;
            sum+=root->val;
            sumdfs(root->left);
            sumdfs(root->right);
        }
    }
    void dfs(TreeNode* root){
        if (root!=NULL){
            count=0,sum=0;
            sumdfs(root);
            if (sum/count==root->val) avgcnt++;
            dfs(root->left);
            dfs(root->right);
        }
    }
    int averageOfSubtree(TreeNode* root) {
         dfs(root);
         return avgcnt;
    }
};