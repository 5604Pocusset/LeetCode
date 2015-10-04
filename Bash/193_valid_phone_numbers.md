# Valid Phone Numbers

嗯..正则表达式, 我喜欢. 知道的新知识是这个:

http://stackoverflow.com/questions/9929841/two-regular-expressions-in-grep-with-alternation

Basic vs Extended Regular Expressions

In basic regular expressions the meta-characters `?`, `+`, `{`, `|`, `(`, and `)` lose their special meaning; instead use the backslashed versions `\?`, `\+`, `\{`, `\|`, `\(`, and `\)`.


## Solution:

```bash
grep -E '^[0-9]{3}-[0-9]{3}-[0-9]{4}$|^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$' file.txt
```