# ZigZag Conversion

Runtime: 8ms; Your runtime beats 40.64% of c submissions.

找规律...

```
1 2 3 4 5 6 7 8

1 3 5 7 9
2 4 6 8 0

1   5   9
2 4 6 8 0
3   7

1     7
2   6 8
3 5   9
4     0
```

第一次挂在处理n=1的情况上面了.