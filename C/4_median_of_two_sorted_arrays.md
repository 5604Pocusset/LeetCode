# Median of two sorted arrays

我知道了..面试就是特别喜欢出这种坑人的题目.
思路是很简单的了, 用两个指针一直走, 走到中位数的位置就停下来输出.
但是需要考虑两个问题:
1. 总个数是奇数或偶数对结果有影响.
2. 有可能在走的过程中或者输出结束时某一个序列走完了.

WA了两次, 主要是第二个问题要讨论的情况一开始没想清楚.