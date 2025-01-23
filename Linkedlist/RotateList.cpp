#include<bits/stdc++.h>
using namespace std;
//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* temp = head;
        int length = 1;
        while(temp -> next != NULL){
            length++;
            temp = temp -> next;
        }

        // now temp is at the last node 
        // connect the last node to the first node and make it a circular list 
        temp -> next = head;

        ListNode* curr = head;
        
        k = k % length;
        // which will be 1 in first case 
        // length - k will be 3 - 1 = 2
        for(int i = 1; i < length - k; i++){
            curr = curr -> next;
        }

        head = curr -> next;
        curr -> next = NULL;

        return head;

    }
};