#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        if(s.size() <= 2){
            return s.size();
        }

        // create a vector to store the frequency of each character 
        vector<int> freq(26, 0);
        string ans = "";
        for(auto& it : s){
            freq[it - 'a']++;
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] <= 2){
                continue;
            }

            if(freq[i] % 2){
                // contribution to the final answer would be 1 only
                cnt += freq[i] - 1;
            }
            // if the cnt be even then contribution to the final answer would be 2
            else{
                cnt += freq[i] - 2;
            }
        }
        return n - cnt;
    }
};