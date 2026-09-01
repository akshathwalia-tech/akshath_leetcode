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
    vector<int> values;

public:
    Solution(ListNode* head) {
        while (head != nullptr) {
            values.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        int idx = rand() % values.size();
        return values[idx];
    }
};