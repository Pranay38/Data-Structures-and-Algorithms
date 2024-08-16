# Write your MySQL query statement below
with cte  as(
    select v.customer_id from Visits v
    left join Transactions t on v.visit_id=t.visit_id
    where t.transaction_id is NULL
)
select c.customer_id, count(c.customer_id) as count_no_trans
from cte c
group by c.customer_id