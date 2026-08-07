#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> input;  // Used for push operations
    stack<int> output; // Used for pop/peek operations

    // Helper function to transfer elements from input stack to output stack
    void transferInputToOutput() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }
    
    // Push element x to the back of queue
    void push(int x) {
        input.push(x);
    }
    
    // Removes the element from the front of the queue and returns it
    int pop() {
        transferInputToOutput();
        int frontVal = output.top();
        output.pop();
        return frontVal;
    }
    
    // Get the front element of the queue
    int peek() {
        transferInputToOutput();
        return output.top();
    }
    
    // Returns whether the queue is empty
    bool empty() {
        return input.empty() && output.empty();
    }
};