#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            int prod = 1;
            int gcdV = nums[i];
            int lcmV = nums[i];
            int maxL = 1e9;
            for(int j = i; j < nums.size(); j++){
                prod = prod * (long long)nums[j];
                if(prod > maxL)
                break;

                gcdV = gcd(gcdV, (long long)nums[j]);
                lcmV = lcm(lcmV, (long long)nums[j]);

                if(prod == gcdV * lcmV)
                maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};