#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // first store the character of string in map 
        // like in the format a: [0, 3], b: [2], c: [3]
        map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]].push_back(i);
        }

        int ans = 0;
        for(auto it : mp){
            // first store the indexes in a vector 
            vector<int> ind = it.second;
            int st = ind[0];
            int end = ind[ind.size() - 1];
            if(end - st <= 1){
                continue;
            }

            else{
                // map me start wale index ke next se end wale index ke pehle tk ke uniqu
                // characters ko store kr lenge
                map<char, int> mpp;
                for(int i = st + 1; i < end; i++){
                    mpp[s[i]]++;
                }
                ans += mpp.size();
            }
        }
        return ans;
    }
};