# Write your MySQL query statement below
SELECT p.project_id, 
IFNULL(ROUND(AVG(e.experience_years), 2), 0) AS average_years
FROM Project p
LEFT JOIN Employee e
    on p.employee_id=e.employee_id
GROUP BY p.project_id;