class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        values.push(val);
        // Add a minimum value if the stack was empty,
        // Or if it's equal or smaller than the current min, push on stack
        if (mins.empty() || val <= mins.top())
            mins.push(val);
    }
    
    void pop() {
        int val = values.top();
        values.pop();
        // If we removed the smallest value in the stack,
        // Also pop from mins:
        if (val == mins.top())
            mins.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return mins.top();
    }

private:
    std::stack<int> values;
    std::stack<int> mins;
};
