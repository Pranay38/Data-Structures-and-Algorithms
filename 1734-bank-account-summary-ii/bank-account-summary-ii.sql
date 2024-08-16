# Write your MySQL query statement below
with cte as(
    select t.account,sum(t.amount) as balance from Transactions t
    group by t.account
)
select u.name,c.balance from cte c
left join Users u on u.account=c.account
where c.balance>10000