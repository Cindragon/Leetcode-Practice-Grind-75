# Write your MySQL query statement below
SELECT person_name
FROM(
    SELECT person_name, SUM(weight) OVER (ORDER BY turn) AS overallweight
    FROM Queue
    GROUP BY person_name
) AS temp
WHERE overallweight<=1000
ORDER BY overallweight DESC
LIMIT 1;