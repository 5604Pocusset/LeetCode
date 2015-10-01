# Two Sum

思路: 把输入数组转成Hash, 然后去Hash中查表找匹配的数
* Hash Value通常是质数
* 注意负数的情况
* 我用的是最土的Hash Function...能感觉到会有很多问题, 例如Hash Value的大小, 太大就ME, 太小是会出现存满然后陷入遍历整张表的死循环.

提交记录: 提交3次
1. RE: 被负数坑了, 导致Hash出来的值有符号, 给Hash function加了abs
2. ME: Hash Value太大了...
3. AC.

实际应用: 这种问题其实有点像是去NoSQL database寻找匹配值.