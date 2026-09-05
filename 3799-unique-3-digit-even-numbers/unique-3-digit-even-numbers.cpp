class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> count(10,0);
        for(int d : digits){
            count[d]++;
        }
        int uniquecount = 0;
        for(int i = 100;i<=998;i+=2){
            int d1 = i/100;
            int d2 = (i/10) % 10;
            int d3 = i%10;
            
            vector<int> needed(10,0);
            needed[d1]++;
            needed[d2]++;
            needed[d3]++;

            if(needed[d1] <= count[d1] &&
                needed[d2] <= count[d2] &&
                needed[d3] <= count[d3]){
                    uniquecount++;
            }
        }
        return uniquecount;
    }
};