#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q1; // Main queue that holds the stack elements in LIFO order
    queue<int> q2; // Helper queue used during push operations

public:
    MyStack() {
        
    }
    
    // Push element x onto stack
    void push(int x) {
        // Step 1: Push the new element into helper queue q2
        q2.push(x);
        
        // Step 2: Transfer all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Step 3: Swap q1 and q2 so q1 always keeps elements in LIFO order
        swap(q1, q2);
    }
    
    // Removes the element on top of the stack and returns it
    int pop() {
        int topVal = q1.front();
        q1.pop();
        return topVal;
    }
    
    // Get the top element of the stack
    int top() {
        return q1.front();
    }
    
    // Returns whether the stack is empty
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */