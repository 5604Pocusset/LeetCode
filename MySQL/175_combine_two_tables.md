# Combine Two Tables

Runtime: 933 ms; Your runtime beats 41.03% of mysql submissions.

# Command line log

```sql
mysql> create database 175_combine_two_tables;
Query OK, 1 row affected (0.00 sec)

mysql> use 175_combine_two_tables;
Database changed

mysql> create table Person (PersonId int, FirstName varchar(255), LastName varchar(255));
Query OK, 0 rows affected (0.01 sec)

mysql> create table Address (AddressId int, PersonId int, city varchar(255), State varchar(255));
Query OK, 0 rows affected (0.01 sec)

mysql> insert into Person (PersonId, FirstName, LastName) values (1, "Light", "Xu");
Query OK, 1 row affected (0.00 sec)

mysql> select FirstName, LastName, City, State
    -> from Person
    -> left join Address
    -> on Person.PersonId = Address.PersonId;
+-----------+----------+------+-------+
| FirstName | LastName | City | State |
+-----------+----------+------+-------+
| Light     | Xu       | NULL | NULL  |
+-----------+----------+------+-------+
1 row in set (0.00 sec)
```