# Write your MySQL query statement below
SELECT s.user_id,     
ROUND(
    IFNULL(SUM(CASE WHEN c.action = 'confirmed' THEN 1 ELSE 0 END) /
    COUNT(c.action),0),
    2
) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c
    on s.user_id=c.user_id
GROUP BY s.user_id;