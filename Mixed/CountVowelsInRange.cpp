#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isVowel(char &ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        else{
            return false;
        }
    }

    bool staend(string &str){
        int n = str.size();
        if(isVowel(str[0]) && isVowel(str[n - 1])){
            return true;
        }
        else{
            return false;
        }
    }

    int isStartEnd(vector<string> words, int left, int right){
      int cnt = 0;
        for(int i = left; i <= right; i++){
            string str = words[i];
            if(staend(str)){
                cnt++;
            }
        }
        return cnt;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // for storing the answers in a array format for each query 
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];
            int countWo = isStartEnd(words, left, right);
            ans.push_back(countWo);
        }
        return ans;

    }
};

// gave tle in 92/93 testcases passed