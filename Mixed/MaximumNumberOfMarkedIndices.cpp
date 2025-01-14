#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;
        int i = 0;
        int j = (n + 1) / 2;

        while(i < n / 2 && j < n){
            if(2 * nums[i] <= nums[j]){
                cnt += 2;
                i++;
                j++;
            }
            else{
                // increment only j
                j++;
            }
        }
        return cnt;
    }
};