#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int n = nums.size();
        // int len = 0;
        // for(int i = 0; i < n; i++){
        //     int sum = 0;
        //     for(int j = i; j < n; j++){
        //         sum += nums[j];

        //         if(sum == k){
        //             len++;
        //         }
        //     }
        // }
        // return len;

        int n = nums.size();
        // creating a prefix array for storing prefix sum 
        vector<int> prefix(n);

        // for element at index 0 it will be the same as nums array
        prefix[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefix[i] = nums[i] + prefix[i - 1];
        }

        unordered_map<int, int> mp;

        int ans = 0;
        for(int i = 0; i < n; i++){
            // if prefix[i] == k then it will be added to the answer
            if(prefix[i] == k){
                ans++;
            }
            // if prefix[i] != k then check whether prefix[i] - k is present in the map
            // or not 
            if(mp.find(prefix[i] - k) != mp.end()){
                // if sahi then add it in the answer
                ans += mp[prefix[i] - k];
            }
            // put prefix sum in to the map 
            mp[prefix[i]]++;
        }
        return ans;

    }
};