# Regular Expression Matching

Runtime: 4ms; Your runtime beats 85.57% of c submissions.

20151007 决定先做Hard...

Regular Expression显然要用自动状态机来表达, 然后就觉得用递归非常显然啊.

特殊优化:

1. 去掉重复的`a*`
2. 如果pattern中没有`*`, 而两个字符串长度不一样, 直接返回`FALSE`.

边界: s和p都是空串pre