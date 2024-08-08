# Write your MySQL query statement below
with cte as(
    select a.sell_date,count(distinct a.product) as num_sold,
    group_concat(distinct product order by product asc) as products from Activities a
    group by a.sell_date
)
select c.sell_date,c.num_sold,c.products from cte c
order by c.sell_date asc