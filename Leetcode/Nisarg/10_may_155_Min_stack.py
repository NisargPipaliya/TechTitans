class MinStack(object):
    mini = float('inf')
    stack = []
    def __init__(self):
        pass
        

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        if self.mini > val:
            temp = self.mini
            self.mini = val
            val = 2 * val - temp
        self.stack.append(val)

    def pop(self):
        """
        :rtype: None
        """
        ans = self.stack.pop()
        if ans < self.mini:
            temp = ans
            ans = self.mini
            self.mini = 2 * self.mini - temp

    def top(self):
        """
        :rtype: int
        """
        ans = self.stack[-1]
        if ans < self.mini:
            ans = self.mini
        return ans

    def getMin(self):
        """
        :rtype: int
        """
        return self.mini


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()