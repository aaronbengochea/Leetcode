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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* temp = new ListNode(0);
        ListNode* current = head;
        ListNode* prev = temp;

        while(current){
            bool isDuplicate = false;
            while(current->next && current->val == current->next->val){
                current = current->next;
                isDuplicate = true;
            }
            if(!isDuplicate){
                prev->next = current;
                prev = current;
            }
            current = current->next;
        }
        
        prev->next = nullptr;

        return temp->next;
    }
};