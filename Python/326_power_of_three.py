class Solution(object):

    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """

        power_of_threes = [1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049,
        177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467]
    
        if n in power_of_threes:
            return True
        else:
            return False

sol = Solution()
print sol.isPowerOfThree(27)
print sol.isPowerOfThree(232345)
        