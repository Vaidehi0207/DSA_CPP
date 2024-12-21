#include<bits/stdc++.h>
using namespace std;
//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
// ek answer vector of vector create kra for storing level order traversal
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            // is point tk root h queue uska size store kr lete h 
            int size = q.size();
            vector<int> lev;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                lev.push_back(node -> val);

                if(node -> left != NULL){
                    q.push(node -> left);
                }
                if(node -> right != NULL){
                    q.push(node -> right);
                }
            }
            ans.push_back(lev);
        }
        return ans;
    }
};