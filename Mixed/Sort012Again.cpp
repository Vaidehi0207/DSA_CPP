#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int cnt0 = 0;
        // int cnt1 = 0;
        // int cnt2 = 0;

        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] == 0){
        //         cnt0++;
        //     }
        //     else if(nums[i] == 1){
        //         cnt1++;
        //     }
        //     else{
        //         cnt2++;
        //     }
        // }

        // for(int i = 0; i < cnt0; i++){
        //     nums[i] = 0;
        // }

        // for(int i = cnt0; i < cnt0 + cnt1; i++){
        //     nums[i] = 1;
        // }

        // for(int i = cnt0 + cnt1; i < nums.size(); i++){
        //     nums[i] = 2;
        // }

        int low = 0, curr = 0;
        int high = nums.size() - 1;

        while(curr <= high){
            if(nums[curr] == 0){
                swap(nums[curr], nums[low]);
                low++;
                curr++;
            }
            else if(nums[curr] == 1){
                curr++;
            }
            else{
                swap(nums[curr], nums[high]);
                high--;
            }
        }

    }
};