# Write your MySQL query statement below
Select c.name as Customers
from Customers c
left join Orders o on c.id=o.CustomerId
where o.CustomerId is NULL