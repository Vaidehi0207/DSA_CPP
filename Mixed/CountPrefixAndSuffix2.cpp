#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrefix(const string& s, const string& t) {
        return t.find(s) == 0;
    }
    
    bool isSuffix(const string& s, const string& t) {
        return t.rfind(s) == t.length() - s.length();
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefix(words[i], words[j]) && isSuffix(words[i], words[j])) {
                    if (words[i].length() <= words[j].length()) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};