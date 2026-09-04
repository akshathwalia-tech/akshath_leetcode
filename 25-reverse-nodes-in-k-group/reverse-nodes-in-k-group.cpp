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
private:
    // Helper to find the k-th node from 'curr'
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode dummy(0, head);
        ListNode* prevGroupTail = &dummy;

        while (true) {
            // 1. Find the k-th node of the current group
            ListNode* kthNode = getKthNode(prevGroupTail, k);
            if (!kthNode) {
                // Fewer than k nodes remaining; leave as-is
                break;
            }

            ListNode* nextGroupHead = kthNode->next;
            ListNode* groupHead = prevGroupTail->next;

            // 2. Reverse the k nodes
            ListNode* prev = nextGroupHead;
            ListNode* curr = groupHead;

            while (curr != nextGroupHead) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // 3. Connect previous group's tail to the new group head (kthNode)
            prevGroupTail->next = kthNode;

            // 4. Move prevGroupTail forward to the end of this group (original groupHead)
            prevGroupTail = groupHead;
        }

        return dummy.next;
    }
};