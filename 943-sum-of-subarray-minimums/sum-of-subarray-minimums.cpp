#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long totalSum = 0;
        int MOD = 1e9 + 7;

        // Arrays to store distance to previous smaller and next smaller elements
        vector<int> left(n), right(n);
        stack<int> st;

        // 1. Find distance to Previous Smaller Element (PSE) for each element
        // Using strict inequality '<' to avoid duplicate counting of equal elements
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            // If stack is empty, all elements on the left are greater
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        // Clear stack for reusing
        while (!st.empty()) st.pop();

        // 2. Find distance to Next Smaller or Equal Element (NSE) for each element
        // Using non-strict inequality '<=' to handle duplicate numbers correctly
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            // If stack is empty, all elements on the right are greater
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        // 3. Compute the total contribution of each element
        for (int i = 0; i < n; i++) {
            long long count = (long long)left[i] * right[i];
            long long contribution = (count % MOD * arr[i]) % MOD;
            totalSum = (totalSum + contribution) % MOD;
        }

        return totalSum;
    }
};