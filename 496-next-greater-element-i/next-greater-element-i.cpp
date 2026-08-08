#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater; // Maps value -> Next Greater Element
        stack<int> st;                      // Monotonic stack (stores elements)

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int num = nums2[i];

            // Pop elements smaller than or equal to current num
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }

            // If stack is empty, no greater element exists to the right
            nextGreater[num] = st.empty() ? -1 : st.top();

            // Push current num onto stack
            st.push(num);
        }

        // Build result for nums1 using O(1) map lookups
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};