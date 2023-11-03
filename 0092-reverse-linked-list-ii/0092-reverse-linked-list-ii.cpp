#include <iostream>
#include <stack>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    if(left == right) {
        return head;
    }


        int tempIndex = 1;
        int temp2Index = 1;
        int temp3Index = 1;

        ListNode* newHead = new ListNode(0);
        ListNode* newTail = new ListNode(0);
        ListNode* sorted = new ListNode(0);
        ListNode* temp = head;
        ListNode* temp2 = head;
        ListNode* temp3 = head;
        

        //finds front section of LL
        if(left <= 1){
            sorted->next = head;
        } else {

            newHead->next = temp;
            while(tempIndex < left-1){
                temp = temp->next;
                temp3 = temp3->next;
                tempIndex++;
                temp3Index++;
            }
            sorted->next = temp3->next; //sets sorted beginning node
        }


        //gets me back section of LL
        while(temp2Index < right){
            temp2 = temp2->next;
            temp2Index++;
        }
        newTail->next = temp2->next;

        


        temp = newHead;
        tempIndex = 1;

        while(tempIndex < left){
            temp = temp->next;
            tempIndex++;
        }
        temp->next = nullptr;


        temp3 = sorted;
        int indexDiff = right - left;
        temp3Index = 0;
        while (temp3Index <= indexDiff){
            temp3 = temp3->next;
            temp3Index++;
        }
        temp3->next = nullptr;
        

        sorted = sorted->next;
        temp2 = sorted->next;
        temp3 = sorted;



        stack<int> stack;


        if(indexDiff == 1) {
            temp2->next = temp3;
            sorted = sorted->next;
            temp3->next = nullptr;
        } 
        else {
            while(temp3 != nullptr){
                stack.push(temp3->val);
                temp3 = temp3->next;
            }

            temp3 = sorted;

            while(temp3 != nullptr){
                int stackInt = stack.top();
                temp3->val = stackInt;

                stack.pop();
                temp3 = temp3->next;
            }
        }   




        newHead = newHead->next;
        newTail = newTail->next;

        if (newHead != nullptr){
            temp = newHead;

            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = sorted;


            temp = newHead;
            while(temp->next != nullptr){
                temp = temp->next;
            }

            temp->next = newTail;
        } else {
            newHead = sorted;
            temp = newHead;

            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newTail;
        }

        return newHead;
    };
};