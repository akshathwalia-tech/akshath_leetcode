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
        if (!head || left == right) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        // Step 1: Reach the node just before position 'left'
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // 'curr' will remain at the original 'left' node (which becomes the tail of this segment)
        ListNode* curr = prev->next;

        // Step 2: Invert pointers one-by-one by moving curr->next right after 'prev'
        for (int i = 0; i < right - left; ++i) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
    }
};