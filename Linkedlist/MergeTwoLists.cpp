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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* l3 = dummy;

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(l1 != NULL && l2 != NULL){
            if(l1 -> val <= l2 -> val){
                l3 -> next = l1;
                l1 = l1 -> next;
            }
            else{
                l3 -> next = l2;
                l2 = l2 -> next;
            }
            l3 = l3 -> next;
        }

        while(l1 != NULL){
            l3 -> next = l1;
            l1 = l1 -> next;
            l3 = l3 -> next;
        }

        while(l2 != NULL){
            l3 -> next = l2;
            l2 = l2 -> next;
            l3 = l3 -> next;
        }
        return dummy -> next;
    }
};