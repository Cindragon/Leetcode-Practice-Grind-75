# Write your MySQL query statement below
(
    SELECT name AS results
    FROM Users u
    JOIN MovieRating mr
    ON u.user_id=mr.user_id
    GROUP BY mr.user_id
    ORDER BY COUNT(*) DESC, name ASC 
    LIMIT 1
)

UNION ALL
(
    SELECT title AS results
    FROM Movies m
    LEFT JOIN movierating mr
    ON m.movie_id=mr.movie_id
    WHERE YEAR(mr.created_at)='2020' AND MONTH(mr.created_at)='02'
    GROUP BY m.movie_id
    ORDER BY AVG(mr.rating) DESC, title ASC
    LIMIT 1
);
