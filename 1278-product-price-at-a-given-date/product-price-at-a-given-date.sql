/* Write your T-SQL query statement below */
WITH b as (
    SELECT distinct product_id
    FROM Products
), t as (
    SELECT *,
    ROW_NUMBER() OVER(PARTITION BY product_id ORDER by change_date desc) as r
    FROM Products
    WHERE change_date <= '2019-08-16'
)

SELECT b.product_id, ifnull(t.new_price, 10) as price
FROM b left join t 
on b.product_id = t.product_id and t.r = 1