# Write your MySQL query statement below
 with cte1 as(
    select num,id-rank() over(partition by num order by id) as nrank
    from logs
 ),
 cte2 as(
    select num,count(*) as cnt
    from cte1
    group by num,nrank
 )
 select distinct num as ConsecutiveNums
 from cte2 
 where cnt>=3