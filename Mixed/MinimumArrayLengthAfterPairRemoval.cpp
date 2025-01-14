#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // int n = A.size();
        // vector<int> C(n);
        // int com = 0;
        // // creating a vector for storing the frequency of elements in A and B 
        // vector<int> cnt(n + 1, 0);
        // for(int i = 0; i < n; i++){
        //     // first increment frequency 
        //     cnt[A[i]]++;

        //     if(cnt[A[i]] == 2)
        //     com++;
            
        //     cnt[B[i]]++;
        //     if(cnt[B[i]] == 2)
        //     com++;

        // update the C vector which  is the answer if we get 2 then add it to the C
        //     C[i] = com;
        // }

        // return C;

        int n = A.size();
        vector<int> C(n);

        unordered_map<int, int> freq;

        // if initial of A and B is same then add the cnt 1 in C vector 
        if(A[0] == B[0])
        C[0] = 1;

        freq[A[0]]++;
        freq[B[0]]++;
        //carry forward the count that we store previously 
        
        for(int i = 1; i < n; i++){
            //carry forward the count that we store previously 
            C[i] = C[i - 1];
            freq[A[i]]++;
            freq[B[i]]++;

            if(A[i] == B[i])
            C[i]++;
            else{
                if(freq[A[i]] == 2) C[i]++;
                if(freq[B[i]] == 2) C[i]++;
            }
        }

        return C;
    }
};