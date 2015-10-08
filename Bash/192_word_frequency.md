# Word Frequency

Runtime: 16 ms; Your runtime beats 15.79% of bash submissions.

## Solution 1:

思路:
算word frequency大概是map reduce里面的经典问题, 做法大概就是按照空格分割然后统计词频. 我先看到了`tr`命令, 它可以把空格变成换行. 换行以后就很好啦, 拿去`sort`啊, 再`uniq`, 就可以拿到词频, 然后就是倒序排序并且输出的问题...
在测试的时候发现`tr`会把每个空格变成换行, 所以去查了一下怎么用`sed`去掉换行.

Remove blank lines: http://www.cyberciti.biz/faq/howto-linux-unix-command-remove-all-blank-lines/

```bash
cat words.txt | tr [:blank:] "\n" | sed '/^$/d' | sort | uniq -c | sort -r | awk '{split($0, a, " "); print a[2], a[1]}'
```
## Solution 2:

在看了这个答案(http://unix.stackexchange.com/questions/80017/how-to-count-total-number-of-words-in-a-file)以后, 果断尝试直接用`awk`写. 嗯这个问题还是挺适合`awk`的. 原问题里面有些小错误. 最后一个发现是`sort`可以直接对某一列排序, 实在是很开心. 运行速度比Solution 1要快.

```bash
cat words.txt | awk 'BEGIN { FS="[^a-zA-Z]+" } { for (i=1; i<=NF; i++) if ($i != "") { word = $i; words[word]++ } } END { for (w in words) printf("%s %d\n", w, words[w]) } ' | sort -rn -k2
```

我猜最快答案是用Perl写的, 我不会Perl, 就酱.