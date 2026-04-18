# Write your MySQL query statement below
select name as Employee
from Employee t1
where t1.salary > (
    select t2.salary 
    from Employee t2
    where t2.id = t1.managerId
)