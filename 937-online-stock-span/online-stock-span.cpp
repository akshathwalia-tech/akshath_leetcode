#include <stack>
#include <utility>

class StockSpanner {
private:
    // Stack stores pairs of {price, span}
    std::stack<std::pair<int, int>> st;

public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        
        // Pop elements from stack while today's price is >= stack top's price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        // Push the accumulated span along with today's price
        st.push({price, span});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */