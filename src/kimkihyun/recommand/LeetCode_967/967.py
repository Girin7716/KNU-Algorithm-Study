# jumping number
from typing import List

# def solve(n,k):
#     result = []
#     def dfs(total,end,cnt):
#         if cnt >= n:
#             result.append(total)
#             return
#
#         for i in range(10):
#             if abs(end-i) == k:
#                 dfs((10*total) + i,i,cnt+1)
#
#     for i in range(1,10):
#         dfs(i,i,1)
#
#     return result
#
# print(solve(3,7))

class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        result = []
        def dfs(total,end,cnt):
            if cnt >= n:
                result.append(total)
                return

            for i in range(10):
                if abs(end-i) == k:
                    dfs((10*total) + i,i,cnt+1)

        for i in range(1,10):
            dfs(i,i,1)
        return result

a = Solution
print(a.numsSameConsecDiff(3,2,1))
