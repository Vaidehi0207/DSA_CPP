#include<bits/stdc++.h>
using namespace std;    

class Solution {
public:
    string multiply(string num1, string num2) {
        long long n1 = stoi(num1);
        long long n2 = stoi(num2);

        string result = to_string(n1 * n2);
        return result;

    }
};