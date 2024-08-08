with cte as(
    select product_id,sum(unit) as units from Orders
    where order_date>='2020-02-01' and order_date<='2020-02-29'
    group by product_id
    having sum(unit)>=100
)
select p.product_name,c.units as unit from cte c
join Products p on p.product_id=c.product_id