#include<bits/stdc++.h>
using namespace std;

// TLE 56/65 testcases passed only
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(j - i != nums[j] - nums[i]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};