# Second Highest Salary

居然是简单题...估计是我的做法太麻烦了, 我用了`GROUP BY`去重, `ORDER BY`排序, `LIMIT 1 OFFSET 1`拿第二个, `UNION`把`NULL`拿进来.
有空查一下更厉害的做法.

```sql
mysql> create database 176_second_highest_salary;
Query OK, 1 row affected (0.00 sec)

mysql> use 176_second_highest_salary;
Database changed

mysql> create table Employee (Id int, Salary int);
Query OK, 0 rows affected (0.02 sec)

mysql> insert into Employee(Id, Salary) VALUES(1, 100);
Query OK, 1 row affected (0.00 sec)

mysql> insert into Employee(Id, Salary) VALUES(2, 200);
Query OK, 1 row affected (0.00 sec)

mysql> insert into Employee(Id, Salary) VALUES(3, 200);
Query OK, 1 row affected (0.00 sec)
```
