#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solveTab(vector<int> &coins, int amount){
        //create a dp array of value INT_MAX
        vector<int> dp(amount+1, INT_MAX);
        //in dp[i] i means that amount 
        //no coins needed to make amount0                                            
        dp[0]=0;
        //iterate from 1 to amount and update the dp table
        for(int i=1; i<=amount; i++){
            //now trying to solve for every amount from 1 to amount
            for(int j=0; j<coins.size(); j++){
                //dp table me update karenge value if dp[i-coins[j]!=INT_MAX]
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }
        if(dp[amount]==INT_MAX)
        return -1;
        else
        return dp[amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        return solveTab(coins, amount);
    }
};