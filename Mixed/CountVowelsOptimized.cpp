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

    // int isStartEnd(vector<string> words, int left, int right){
    //   int cnt = 0;
    //     for(int i = left; i <= right; i++){
    //         string str = words[i];
    //         if(staend(str)){
    //             cnt++;
    //         }
    //     }
    //     return cnt;
    // }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // // for storing the answers in a array format for each query 
        // vector<int> ans;
        // for(int i = 0; i < queries.size(); i++){
        //     int left = queries[i][0];
        //     int right = queries[i][1];
        //     int countWo = isStartEnd(words, left, right);
        //     ans.push_back(countWo);
        // }
        // return ans;

        int n = words.size();
        int m = queries.size();

        // creating a prefix array 
        vector<int> prefix(n);

        prefix[0] = staend(words[0]);
        for(int i = 1; i < n; i++){
            // if that word is having start and end character a vowel then add it into 
            // the prefix
            prefix[i] = prefix[i - 1] + staend(words[i]);
        }

        // create a vector for storing ans
        vector<int> ans;
        for(int i = 0; i < m; i++){
            int left = queries[i][0];
            int right = queries[i][1];
            int tot = 0;

            if(left != 0){
                tot = prefix[right] - prefix[left - 1];
            }
            else{
                tot = prefix[right];
            }
            ans.push_back(tot);
        }
        return ans;
    }
};