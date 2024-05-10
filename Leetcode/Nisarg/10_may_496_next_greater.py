class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        m = {
            "num" : [],
            "ng": [],
        }
        stack = []
        temp = nums2
        temp.reverse()
        for i in temp:
            if len(stack) == 0:
                m['num'].append(i)
                m['ng'].append(-1)
            
            elif i < stack[-1]:
                m['num'].append(i)
                m['ng'].append(stack[-1])

            elif i > stack[-1]:
                m['num'].append(i)

                while  len(stack) > 0 and i > stack[-1]:
                    stack.pop()

                if len(stack) == 0:
                    m['ng'].append(-1)
                else:
                    m['ng'].append(stack[-1])
            stack.append(i)

        ans = []
        for i in nums1:
            index = m['num'].index(i)
            ans.append(m['ng'][index])
        return ans