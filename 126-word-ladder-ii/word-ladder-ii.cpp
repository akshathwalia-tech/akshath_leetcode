#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
    unordered_map<string, int> mpp; // Stores distance (level) of each word from beginWord
    vector<vector<string>> ans;
    string bWord;

    // DFS Backtracking: reconstructs paths starting from endWord backwards to beginWord
    void dfs(string word, vector<string>& seq) {
        // Base case: Reached beginWord
        if (word == bWord) {
            vector<string> reverseSeq = seq;
            reverse(reverseSeq.begin(), reverseSeq.end());
            ans.push_back(reverseSeq);
            return;
        }

        int steps = mpp[word];

        // Try changing each character to find valid parents in the BFS tree
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                // Move backward: Parent must exist in map and have step count = steps - 1
                if (mpp.count(word) && mpp[word] == steps - 1) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back(); // Backtrack
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // If endWord is not in the dictionary, no sequence can be formed
        if (st.find(endWord) == st.end()) return {};

        bWord = beginWord;

        // Queue stores individual words (saves memory)
        queue<string> q;
        q.push(beginWord);
        
        mpp[beginWord] = 1; // Level 1
        st.erase(beginWord);

        int wordLen = beginWord.size();

        // Step 1: Standard BFS to record the shortest distance to each reachable word
        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if (word == endWord) break; // Reached target level

            for (int i = 0; i < wordLen; i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word);        // Mark visited
                        mpp[word] = steps + 1; // Store distance level
                    }
                }
                word[i] = original;
            }
        }

        // Step 2: DFS Backtracking from endWord back to beginWord
        if (mpp.count(endWord)) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};