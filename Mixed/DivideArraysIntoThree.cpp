#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i = 1; i < n; i++){
            nums[i] += nums[i - 1];
            // this s will contain the sum of all elements that is the last element of
            // this array
            s = nums.back();
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int first = nums[i];
                int second = nums[j] - nums[i];
                //remaining sum 
                int third = s - nums[j];

                if(first <= second && second <= third){
                    ans++;
                }
            }
        }
        return ans;
        // return s;
    }
};
// not optimisez approach 