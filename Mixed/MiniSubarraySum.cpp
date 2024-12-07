#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int mini = INT_MAX;
        int sum = 0;

        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];

            while(sum >= target){
                if(j - i + 1 < mini){
                    mini = j - i + 1;
                }
                sum -= nums[j];
                i++;
            }
        }
        if(mini != INT_MAX){
            return mini;
        }        
        return 0;
    }
};