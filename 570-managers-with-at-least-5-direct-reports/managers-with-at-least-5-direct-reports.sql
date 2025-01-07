# Write your MySQL query statement below
select name from Employee e 
join(
    select managerId from Employee e
    where managerId is not null
    group by managerId having count(managerId)>=5
) as m on e.id=m.managerId