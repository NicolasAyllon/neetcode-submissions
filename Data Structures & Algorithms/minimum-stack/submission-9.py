class MinStack:

    def __init__(self):
        self.vals = []
        self.mins = []

    def push(self, val: int) -> None:
        self.vals.append(val)
        if len(self.mins) == 0:
            self.mins.append(val)
        else:
            self.mins.append(min(self.mins[-1], val))

    def pop(self) -> None:
        self.vals.pop()
        self.mins.pop()

    def top(self) -> int:
        return self.vals[-1]

    def getMin(self) -> int:
        return self.mins[-1] 
