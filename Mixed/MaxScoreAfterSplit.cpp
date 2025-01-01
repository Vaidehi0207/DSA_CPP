#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int maxi = 0;

        int zero = 0;
        for(int i = 0; i < n - 1; i++){
            if(s[i] == '0'){
                zero++;
            }
            int one = 0;
            for(int j = i + 1; j < n; j++){
                if(s[i] == '1'){
                    one++;
                }
            }
            maxi = max(maxi, zero + one);
        }
        return maxi;
    }
};