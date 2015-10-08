# Longest Palindromic Substring

Runtime: 16 ms; Your runtime beats 55.88% of c submissions.

最长回文串问题

这也算是个经典问题了, 我有点忘了怎么做. 第一遍自己做的时候是枚举回文串头尾. 看了别人的博文以后改成枚举中点位置. 还有进一步利用对称性快速过滤非最优解的方法, 大概看懂了, 就不实现了嗯...以后面试面到了再后悔.

http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
http://www.felix021.com/blog/read.php?2040

顺便, strncpy是不会设置末尾0的...
