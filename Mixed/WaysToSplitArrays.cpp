#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long left = 0, right = 0;
        for(int i = 0; i < n; i++){
            right += nums[i];
        }
        int cnt = 0;

        for(int i = 0; i < n - 1; i++){
            left += nums[i];
            right -= nums[i];

            if(left >= right){
                cnt++;
            }
        }
        return cnt;
    }
};