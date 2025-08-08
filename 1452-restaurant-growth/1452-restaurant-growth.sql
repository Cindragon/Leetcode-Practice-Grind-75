# Write your MySQL query statement below
WITH daily_amount AS(
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),  #算每一天的總和
rolling_7days AS(
    SELECT visited_on,
    SUM(amount) OVER(
        ORDER BY visited_on
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    )AS total_amount
    FROM daily_amount
)   #連續七天的總和
SELECT visited_on, total_amount AS amount, ROUND(total_amount/7, 2) AS average_amount
FROM rolling_7days
WHERE visited_on>=(
    SELECT MIN(visited_on)
    FROM Customer
)+INTERVAL 6 DAY
GROUP BY visited_on;