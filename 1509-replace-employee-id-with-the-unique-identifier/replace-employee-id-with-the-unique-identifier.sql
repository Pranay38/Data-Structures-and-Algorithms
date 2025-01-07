# Write your MySQL query statement below
with cte as(
    select e.id,e.name,u.unique_id from employees e
    left join EmployeeUNI u on e.id=u.id
)
select c.unique_id,c.name from cte c
order by c.unique_id