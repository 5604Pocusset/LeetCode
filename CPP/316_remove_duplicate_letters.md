316 Remove Duplicate Letters

http://code.mforever78.com/algorithm/2015/12/14/leetcode-316-solution/

拿到题反应觉得是贪心, 大概就是正着扫反着扫来回确定下一个保证可行解并且字典序最小. 但是这个思路非常不明确, 并且我一直在尝试直接在O(N)搞定...

第二天再做就投降了, 去看了别人的题解. 我觉得题解中有一个说的很好, 算法其实要做两件事情:
1 选出其后出现了所有未选出的字母的字母。
2 从中选出字典序最小的那个。

在投降到O(N^2)搞定的解以后, 整体思路还是比较简单的:

预处理: 扫一遍, 知道有多少不同的字母
count = 不同的字母数
当前正在处理的子串开头 start_index = 0
while (count != 0) {
    倒着扫[start_index, s.size())
    如果某个位置开始的不同字母数等于count, 则比较字典序存入candidate
    把candidate更新到result里面
    count--
}

有些小细节具体看代码, 例如在比较字典序的时候用<=, 因为要尽量往前找, 这算是一个小贪心.