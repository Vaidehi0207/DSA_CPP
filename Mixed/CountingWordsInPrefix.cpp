#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int len = pref.size();
        // for(auto it : words){
        //     for(int i = 0; i < len; i++){
                
        //     }
        // }
        int cnt = 0;
        for(auto it : words){
            if(it.substr(0, len) == pref){
                cnt++;
            } 
        }
        return cnt;
    }
};