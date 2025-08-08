# Write your MySQL query statement below
WITH ranked_salary AS(
    SELECT 
    d.name AS Department, 
    e.name AS Employee,
    e.salary AS Salary,
    DENSE_RANK() OVER(  #DENSE_RANK 不會跳號
        Partition BY e.departmentId #遇到重複的不會合併
        ORDER BY e.salary DESC
    ) AS ranking
    FROM Employee e
    JOIN Department d 
    ON e.departmentId=d.id
)
SELECT Department, Employee, Salary
FROM ranked_salary
WHERE ranking<=3;