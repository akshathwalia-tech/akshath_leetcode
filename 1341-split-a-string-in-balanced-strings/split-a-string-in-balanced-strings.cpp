class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        vector<int> traverse(2,0);
        int i = 0;
        while(i<s.length()){
            if(s[i]=='R'){
                traverse[1]++;
            }
            else{
                traverse[0]++;
            }
            if(traverse[0]==traverse[1]){
                count++;
            }
            i++;
        }
        return count;
    }
};