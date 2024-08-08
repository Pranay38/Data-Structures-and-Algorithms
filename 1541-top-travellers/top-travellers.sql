# Write your MySQL query statement below
with cte as(
    select u.id,u.name, ifnull(sum(r.distance),0)as travelled_distance from Users u
    left join Rides r on r.user_id=u.id
    group by u.name,u.id

)
select c.name,c.travelled_distance from cte c
order by c.travelled_distance desc, c.name asc