class TimeMap:

    def __init__(self):
        self.keyToList = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.keyToList:
            self.keyToList[key] = []
        self.keyToList[key].append((value, timestamp))

    def get(self, key: str, timestamp: int) -> str:
        # We want the value for the largest time T with T <= timestamp
        valueTimes = self.keyToList.get(key, [])
        lo, hi = 0, len(valueTimes) - 1
        
        # The given timestamp occurred before the first time this key's value was set
        if not valueTimes or timestamp < valueTimes[0][1]: 
            return ""

        # timestamp >= valueTimes[0][1]
        # We maintain the invariant that there is at least one time in indices[lo, hi] before timestamp
        result = ""
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            # The midpoint has time before or equal to timestamp
            if valueTimes[mid][1] <= timestamp:
                result = valueTimes[mid][0]
                lo = mid + 1 # Search higher indices for a potentially later time closer to timestamp
            else:
                hi = mid - 1 # Times at index mid is too late

        return result