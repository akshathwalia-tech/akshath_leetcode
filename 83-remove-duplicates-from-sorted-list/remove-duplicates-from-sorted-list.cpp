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
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                // Duplicate found: skip the next node
                ListNode* duplicateNode = curr->next;
                curr->next = curr->next->next;
                delete duplicateNode; // Free memory in C++
            } else {
                // Values are distinct: move to the next node
                curr = curr->next;
            }
        }

        return head;
    }
};