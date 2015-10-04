SELECT Salary AS SecondHighestSalary
FROM
(
    (SELECT Salary
    FROM
    (
        SELECT Salary
        FROM Employee
        GROUP BY Salary
    ) AS S1
    ORDER BY Salary DESC
    LIMIT 1 OFFSET 1)
    UNION
    (SELECT NULL AS Salary)
) AS S2
LIMIT 1;