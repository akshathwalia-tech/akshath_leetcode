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
        // Handle empty list or single-node list
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 1. Find the length of the list
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // 2. Modulo k so we only rotate what is necessary
        k = k % n;
        if (k == 0) return head;

        // 3. Your original rotation logic (1 node at a time)
        while (k > 0) {
            ListNode* prev = head;
            
            // Move to the second-to-last node
            while (prev->next->next != nullptr) {
                prev = prev->next;
            }

            ListNode* curr = prev->next; // last node
            prev->next = nullptr;        // detach last node (curr->next is already null)
            curr->next = head;           // place last node at the front
            head = curr;                 // update head

            k--;
        }

        return head;
    }
};