#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> left;
        stack<int> star;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                left.push(i);
            }
            else if(s[i] == '*'){
                star.push(i);
            }
            else{
                if(!left.empty()){
                    left.pop();
                }

                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        // check for leftover parentheses 
        while(!left.empty() &&!star.empty()){
            if(left.top() > star.top()){
                return false;
            }
            left.pop();
            star.pop();
        }

        if(left.empty())
            return true;
        return false;
    }
};