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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr || head->next == nullptr){
            return head;
        }

        int nodeCount = 0;
        ListNode* temp1 = head;

        while(temp1 != nullptr){
            temp1 = temp1->next;
            nodeCount++;
        }

        int reducedRotations = k % nodeCount;

        

        temp1 = head;
        ListNode* temp2 = head;
        for(int i = 0; i < reducedRotations; i++){
            while(temp1->next->next != nullptr){
                temp1 = temp1->next;
            }
            temp1->next->next = temp2;
            head = temp1->next;
            temp1->next = nullptr;

            temp1 = head;
            temp2 = head;
        }

        return head;
        
    }
};