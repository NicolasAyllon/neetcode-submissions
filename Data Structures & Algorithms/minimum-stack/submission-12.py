class MinStack:

    def __init__(self):
        self.stack = [] # values, with the end of the list the top the stack
        self.min_indices = [] # indices of the minimum values in the stack

    def push(self, val: int) -> None:
        # If this value is less than the current min, push its index (len(stack) - 1) onto the stack of min_indices
        if not self.stack or val < self.stack[self.min_indices[-1]]:
            self.min_indices.append(len(self.stack))
        # Always add the value to the stack
        self.stack.append(val)

    def pop(self) -> None:
        # The current minimum is at the last index, so pop it
        if self.min_indices[-1] == len(self.stack) - 1:
            self.min_indices.pop()
        # Always pop the top value of the self.stack
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.stack[self.min_indices[-1]]
        
