#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int n = nums.size();
        // int maxi = INT_MIN;
        // for(int i = 0; i < n; i++){
        //     int sum = 0;
        //     for(int j = i; j < n; j++){
        //         sum += nums[j];
        //         if(sum > maxi){
        //             maxi = sum;
        //         }
        //     }
        // }
        // return maxi;

        int curr = 0, maxi = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            maxi = max(maxi, curr);
            if(curr < 0)
            curr = 0;
        }
        return maxi;
    }
};