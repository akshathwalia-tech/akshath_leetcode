using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string word;
        vector<string> words(9); // Max 9 words as per constraints
        int wordCount = 0;

        while (ss >> word) {
            // Extract position from the last character
            int index = word.back() - '1'; 
            
            // Remove the digit from the word
            word.pop_back(); 
            
            // Store word at its target index
            words[index] = word; 
            wordCount++;
        }

        // Reconstruct the sentence
        string result = "";
        for (int i = 0; i < wordCount; i++) {
            result += words[i];
            if (i < wordCount - 1) {
                result += " ";
            }
        }

        return result;
    }
};