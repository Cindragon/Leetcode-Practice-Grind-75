# Write your MySQL query statement below
WITH firstsale AS (
    SELECT product_id, MIN(year) AS firstyear
    FROM Sales
    GROUP BY product_id
)
SELECT s.product_id, f.firstyear AS first_year, s.quantity, s.price
FROM Sales s
JOIN firstsale f
ON s.product_id=f.product_id AND s.year=f.firstyear
