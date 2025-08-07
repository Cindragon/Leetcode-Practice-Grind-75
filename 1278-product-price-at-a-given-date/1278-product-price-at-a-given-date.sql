WITH last_change AS (
    SELECT product_id, MAX(change_date) AS last_change_date
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
)

SELECT 
    p_all.product_id,
    IFNULL(p.new_price, 10) AS price
FROM 
    (SELECT DISTINCT product_id FROM Products) AS p_all
LEFT JOIN last_change lc 
    ON p_all.product_id = lc.product_id
LEFT JOIN Products p 
    ON p.product_id = lc.product_id AND p.change_date = lc.last_change_date;
