class Solution {
public:

    /* Function to find the next greater 
    element for each element in the array */
    vector<int> nextGreaterElements(vector<int> nums) {
        
        int n = nums.size(); //size of array
        
        // To store the next greater elements
        vector<int> ans(n);
        
        // Stack to get elements in LIF fashion
        stack<int> st;
        
        // Start traversing from the back
        for(int i = 2*n-1; i >= 0; i--) {
            
            // Get the actual index
            int ind = i % n;
            
            // Get the current element
            int currEle = nums[ind];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            element is not the greater element */
            while(!st.empty() && st.top() <= currEle) {
                st.pop();
            }
            
            // Store the answer for the second half
            if(i < n) {
                
                /* If the greater element is not 
                found, stack will be empty */
                if(st.empty()) 
                    ans[i] = -1;
                    
                // Else store the answer
                else 
                    ans[i] = st.top();
            }
            
            /* Push the current element in the stack 
            maintaining the decreasing order */
            st.push(currEle);
        }
        
        // Return the result
        return ans;
    }
};