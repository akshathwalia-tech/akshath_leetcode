#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

// Class to implement Minimum Stack
class MinStack {
private:
    // Stack storing pairs of {actual_value, minimum_so_far}
    stack<pair<int, int>> st;

public:
    // Constructor
    MinStack() {
    }
    
    // Method to push a value in stack
    void push(int value) {
        // If stack is empty, value is both the element and the current minimum
        if (st.empty()) {
            st.push({value, value});
            return;
        }
        
        // Calculate current minimum by comparing previous minimum with new value
        int mini = min(getMin(), value);
        
        // Push the pair {value, current_minimum}
        st.push({value, mini});
    }
    
    // Method to pop a value from stack
    void pop() {
        if (!st.empty()) {
            st.pop(); 
        }
    }
    
    // Method to get the top element of stack
    int top() {
        return st.top().first;
    }
    
    // Method to get the minimum element in stack
    int getMin() {
        return st.top().second;
    }
};