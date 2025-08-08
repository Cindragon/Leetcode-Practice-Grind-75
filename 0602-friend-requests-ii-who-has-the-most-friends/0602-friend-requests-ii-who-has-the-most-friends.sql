# Write your MySQL query statement below
SELECT id as id, COUNT(*) AS num
FROM(
    SELECT requester_id as id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id as id FROM RequestAccepted
)AS all_friends
GROUP BY id
ORDER BY num DESC
LIMIT 1;