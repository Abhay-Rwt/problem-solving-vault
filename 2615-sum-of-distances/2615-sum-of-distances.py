from collections import defaultdict
from typing import List

class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        mp = defaultdict(list)
        for i, x in enumerate(nums):
            mp[x].append(i)
        
        ans = [0] * len(nums)
        
        for arr in mp.values():
            n = len(arr)
            
            prefix = [0] * (n + 1)
            for i in range(n):
                prefix[i + 1] = prefix[i] + arr[i]
            
            for i in range(n):
                idx = arr[i]
                
                left = i * idx - prefix[i]
                right = (prefix[n] - prefix[i + 1]) - (n - i - 1) * idx
                
                ans[idx] = left + right
        
        return ans