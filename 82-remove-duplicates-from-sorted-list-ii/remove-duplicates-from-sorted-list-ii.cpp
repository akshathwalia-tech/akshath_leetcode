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
        if (!head || !head->next) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (head != nullptr) {
            // Check if current node is the start of duplicates
            if (head->next != nullptr && head->val == head->next->val) {
                // Move head to the very last node having the duplicate value
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Skip all duplicates by linking prev directly to the node after duplicates
                prev->next = head->next;
            } else {
                // No duplicate for this node; advance prev
                prev = prev->next;
            }
            // Move head to the next distinct value to inspect
            head = head->next;
        }

        return dummy.next;
    }
};