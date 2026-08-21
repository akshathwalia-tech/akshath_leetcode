#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Step 1: Sort both arrays to enable greedy pairing
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int childIdx = 0;  // Tracks the current child we are trying to satisfy
        int cookieIdx = 0; // Tracks the current cookie we are inspecting

        // Step 2: Iterate through cookies and match them with children
        while (childIdx < g.size() && cookieIdx < s.size()) {
            // If the current cookie is big enough for the current child
            if (s[cookieIdx] >= g[childIdx]) {
                childIdx++; // Child is content, move to the next child
            }
            cookieIdx++; // Always move to the next cookie
        }

        // childIdx equals the total number of content children
        return childIdx;
    }
};