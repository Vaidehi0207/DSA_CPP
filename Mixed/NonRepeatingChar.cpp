#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string s, int start, int end){
        unordered_set<char> mp;
        for(int i = start; i <= end; i++){
            if(mp.find(s[i]) != mp.end()){
                return false;
            }
            else{
                // push that new character into the set
                mp.insert(s[i]);
            }
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(s, i, j)){
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
};