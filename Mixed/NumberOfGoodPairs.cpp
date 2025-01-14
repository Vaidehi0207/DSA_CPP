#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // int cnt = 0;
        // int n = nums.size();
        // for(int i = 0; i < n - 1; i++){
        //     for(int j = i + 1; j < n; j++){
        //         if(j - i != nums[j] - nums[i]){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;

        int n = nums.size();
        long long ans = 0;

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            // good pairs would be j - nums[i] == i - nums[i] because bad pairs are
            // j - i != nums[j] - nums[i]

            if(mp.find(i - nums[i]) == mp.end()){
                ans += i;
                // and add in the map
                mp[i - nums[i]] = 1;
            }
            else{
                // if i-nums[i] is present in the map then 
                ans = ans + i - mp[i - nums[i]];
                mp[i - nums[i]]++;
            }
        }
        return ans;
    }
};