#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int index){
        int n = days.size();
        //base case
        if(index >= n){
            //agar index saare days ko traverse kr liya then
            return 0;
        }
        //1 day ka pass liya 
        int option1 = costs[0] + solve(days, costs, index+1);

        int i;
        //7 days pass
        //skip till ith day is current day + 7 as we are buying pass for 1 week
        for(i = index; i<n && days[i]<days[index]+7; i++);
        //cost[1] jo ki 7 days pass ki cost h
        int option2 = costs[1] + solve(days, costs, i);

        //3rd case hoga for 30 days ke liye 
        //loop will run till we reach the days for 30 days 
        for(i = index; i<n && days[i]<days[index]+30; i++);
        int option3 = costs[2] + solve(days, costs, i);

        return min(option1, min(option2, option3));
    }
    int solveMem(vector<int>& days, vector<int>& costs, int index, vector<int>&dp){
        int n = days.size();
        //base case
        if(index >= n){
            //agar index saare days ko traverse kr liya then
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        //1 day ka pass liya 
        int option1 = costs[0] + solveMem(days, costs, index+1, dp);

        int i;
        //7 days pass
        //skip till ith day is current day + 7 as we are buying pass for 1 week
        for(i = index; i<n && days[i]<days[index]+7; i++);
        //cost[1] jo ki 7 days pass ki cost h
        int option2 = costs[1] + solveMem(days, costs, i, dp);

        //3rd case hoga for 30 days ke liye 
        //loop will run till we reach the days for 30 days 
        for(i = index; i<n && days[i]<days[index]+30; i++);
        int option3 = costs[2] + solveMem(days, costs, i, dp);

        dp[index] = min(option1, min(option2, option3));
        return dp[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return solveMem(days, costs, 0, dp);
    }
};