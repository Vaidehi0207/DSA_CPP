#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int preSum = 0;

        //create an unordered map for storing values 
        unordered_map<int, int> mp;
        //to handle base cases 
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];

            //also calculate if the sum of subarray gets divided by k 
            int rem = preSum % k;

            //adjust negative remainders to be positive
            if(rem < 0){
                rem += k;
            }

            //find in the map if we have already found the remainder that we got here 
            if(mp.find(rem) != mp.end()){
                cnt += mp[rem];
                //add it in the map also if not ofund 
                mp[rem]++;
            }else{
                mp[rem] = 1;
            }
        }
        return cnt;
    }
};
    //TLE - O(n2)
        // int n = nums.size();
        // int cnt = 0;

        // for(int i = 0; i < n; i++){
        //     int sum = 0;
        //     for(int j = i; j < n; j++){
        //         sum += nums[j];

        //         if(sum % k == 0){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;