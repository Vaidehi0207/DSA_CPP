#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int maxi = INT_MIN;
        int st = 0;
        // vector<string> ans;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(s, i, j)){
                    if(j - i + 1 > maxi){
                        maxi = j - i + 1;
                        st = i;
                    }
                }
            }
        }
        return s.substr(st, maxi);

    }
};