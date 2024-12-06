#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }

        // for(auto it : operations){
        //     if(mp.find(it[0]) != mp.end()){
        //         mp[it[0]] = it[1];
        //     }
        // }
        // for(auto i : nums){
        //     i = mp[i];
        // }
        // int prev, curr, idx;
        // for(auto it : operations){
        //     // store the values first 
        //     prev = it[0];
        //     curr = it[1];

        //     idx = mp[prev];
        //     mp[curr] = idx;
        //     // convert in nums array
        //     nums[idx] = curr;
        // }

        for(int i = 0; i < operations.size(); i++){
            // look 1 in map to get the index of 1 in map 
            // mp[1] = 0
            // nums[0] = 3
            nums[mp[operations[i][0]]] = operations[i][1];
            // add new value to the map with same index and remove previous value 
            mp[operations[i][1]] = mp[operations[i][0]];
        }
        return nums;
    }
};