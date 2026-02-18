# Write your MySQL query statement below
SELECT IFNULL(
    (
        SELECT salary
        FROM (
            SELECT distinct salary
            FROM Employee
#           #group by salary
            ORDER BY salary DESC
            LIMIT 1 OFFSET 1
        ) AS Second
    ), NULL
) AS SecondHighestSalary;
-- SELECT MAX(salary) AS SecondHighestSalary
-- FROM Employee
-- WHERE salary < (SELECT MAX(salary) FROM Employee);