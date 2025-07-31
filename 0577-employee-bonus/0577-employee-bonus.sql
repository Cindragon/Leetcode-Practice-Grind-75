# Write your MySQL query statement below
Select e.name, b.bonus
From Employee e
LEFT JOIN Bonus b
on e.empId=b.empId
Where b.bonus<1000 OR b.bonus is null;