#include<iostream>
using namespace std;
//   Definition for a binary tree node.
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
//     vector<vector<int>> ans;
//     vector<vector<int>> levelOrder(TreeNode* root) {
//     if(root == NULL){
//             return ans;
//         }

//         queue<TreeNode*> q;
//         q.push(root);

//         while(!q.empty()){
//             vector<int> lev;
//             int size = q.size();
//             for(int i = 0; i < size; i++){
//                 TreeNode* node = q.front();
//                 q.pop();
                
//                 lev.push_back(node -> val);

//                 if(node -> left != NULL){
//                     q.push(node -> left);
//                 }
//                 if(node -> right != NULL){
//                     q.push(node -> right);
//                 }
//             }
//             ans.push_back(lev);
//         }
//         return ans;
//     }
//     int minimumOperations(TreeNode* root) {
//         vector<vector<int>> res = levelOrder(root);
//         for (auto &it : res) {
//             for (auto &j : it) {
//                 cout << j << " ";
//             }
//             cout << endl;
//         }
//         return 0;
//     }
// };
    int count(vector<int>& lev){
        int n = lev.size();
        // first create a vector which will store the elements of level in sorted order 
        vector<int> sortLev(lev);
        sort(sortLev.begin(), sortLev.end());

        // creating an unordered_map to store the elements of lev along with index 
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[lev[i]] = i;
        }

        int swaps = 0;

        for(int i = 0; i < n; i++){
            if(lev[i] != sortLev[i]){
                // correct wali index hogi jo sorted level me h usko map me find kra 
                int correct = mp[sortLev[i]];

                // the index of map for the swapped elements 
                mp[lev[i]] = correct;
                mp[lev[correct]] = i;

                // now swap the elements
                swap(lev[i], lev[correct]);
                swaps++;
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }

        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> lev;
            int size = q.size();

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
            // one level has been created now count the number of swaps required for 
            // this level first
            ans += count(lev);
        }

        return ans;

    }
};