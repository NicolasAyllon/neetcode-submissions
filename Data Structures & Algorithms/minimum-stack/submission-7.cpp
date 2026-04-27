class MinStack {
public:
    MinStack() {
        // We always keep a sentinel value on the mins stack
        // so that we can compare to mins.top() even when we're adding the first element.
        mins.push(std::numeric_limits<int>::max());
    }
    
    void push(int val) {
        values.push(val);
        mins.push(std::min(val, mins.top()));
    }
    
    void pop() {
        values.pop();
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
