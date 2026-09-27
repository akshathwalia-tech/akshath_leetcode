#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> people(n);

        // Pair heights with names
        for (int i = 0; i < n; i++) {
            people[i] = {heights[i], names[i]};
        }

        // Sort in descending order based on height
        sort(people.begin(), people.end(), greater<pair<int, string>>());

        // Extract sorted names
        vector<string> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = people[i].second;
        }

        return result;
    }
};