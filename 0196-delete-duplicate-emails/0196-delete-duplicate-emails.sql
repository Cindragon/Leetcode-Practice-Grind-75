# Write your MySQL query statement below
WITH duplicate_email AS(
    SELECT MIN(id) AS id, email
    FROM Person
    GROUP BY email
)

DELETE FROM Person
WHERE id NOT IN(
    SELECT id FROM duplicate_email 
);
