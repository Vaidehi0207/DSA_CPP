#include<bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        // -1 -> 1 -> 2 -> 3 -> 4 
        dummy -> next = head;
        ListNode* temp = dummy;
        ListNode* n1;
        ListNode* n2;

        while(temp -> next && temp -> next -> next){
            n1 = temp -> next; //1
            n2 = temp -> next -> next; //2
            n1 -> next = n2 -> next; // 1 -> 3
            n2 -> next = n1; //2 -> 1
            temp -> next = n2;
            temp = n1;
        }
        return dummy -> next;
    }
};