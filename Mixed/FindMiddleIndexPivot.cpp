#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        // int n = nums.size();
        // int mid = n / 2;
        // if(mid == 0 || mid == n - 1){
        //     return 0;
        // }
        // int ans = 0;
        // for(int i = 0; i < mid; i++){
        //     ans += nums[i];
        // }
        // return ans;

        int sum = 0;
        int left = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }

        for(int i = 0; i < nums.size(); i++){
            sum -= nums[i];

            if(left == sum){
                return i;
            }
                left += nums[i];
        }
        return -1;
    }
};