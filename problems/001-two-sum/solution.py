"""
LeetCode Problem #1: Two Sum
https://leetcode.com/problems/two-sum/

Difficulty: Easy

Problem Description:
Given an array of integers nums and an integer target, return indices of the 
two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may 
not use the same element twice.

You can return the answer in any order.

Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
    Input: nums = [3,2,4], target = 6
    Output: [1,2]

Example 3:
    Input: nums = [3,3], target = 6
    Output: [0,1]

Constraints:
    - 2 <= nums.length <= 10^4
    - -10^9 <= nums[i] <= 10^9
    - -10^9 <= target <= 10^9
    - Only one valid answer exists.

Solution Approach:
    We use a hash map to store the complement of each number as we iterate 
    through the array. For each number, we check if its complement (target - num)
    exists in the hash map. If it does, we have found our pair.
    
    Time Complexity: O(n)
    Space Complexity: O(n)
"""

from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        Find two indices such that their values add up to target.
        
        Args:
            nums: List of integers
            target: Target sum to find
            
        Returns:
            List containing the two indices
        """
        num_to_index = {}
        
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_to_index:
                return [num_to_index[complement], i]
            num_to_index[num] = i
        
        # Problem guarantees exactly one solution exists
        raise ValueError("No solution found - this should not happen per problem constraints")


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Test case 1
    assert solution.twoSum([2, 7, 11, 15], 9) == [0, 1], "Test case 1 failed"
    
    # Test case 2
    assert solution.twoSum([3, 2, 4], 6) == [1, 2], "Test case 2 failed"
    
    # Test case 3
    assert solution.twoSum([3, 3], 6) == [0, 1], "Test case 3 failed"
    
    print("All test cases passed!")
