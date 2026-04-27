class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        // Add the index if this value is less than the current min in the stack
        if (mStack.empty() || val < mStack[mMinIndices.back()])
            mMinIndices.push_back(mStack.size());
        // Always push the value in underlying stack
        mStack.push_back(val);
    }
    
    void pop() {
        // If the top of the stack is minimum value, also pop its index from the index stack
        if (mMinIndices.back() == mStack.size()-1)
            mMinIndices.pop_back();
        // Always pop the value from the underlying stack
        mStack.pop_back();
    }
    
    int top() {
        return mStack.back();
    }
    
    int getMin() {
        return mStack[mMinIndices.back()];
    }

private:
    // Stack of values, the underlying stack for the data structure
    std::vector<int> mStack;
    // Stack of indices of the minimum values in the stack
    std::vector<int> mMinIndices;
};
