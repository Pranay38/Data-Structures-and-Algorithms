WITH totalreg AS (
    SELECT COUNT(*) AS totalusers FROM Users
),
countuser AS (
    SELECT contest_id, COUNT(DISTINCT user_id) AS registered 
    FROM Register
    GROUP BY contest_id
)
SELECT 
    c.contest_id,
    ROUND((c.registered / t.totalusers) * 100, 2) AS percentage
FROM 
    countuser c
JOIN 
    totalreg t  -- Explicitly reference the alias 't'
ORDER BY 
    percentage DESC,  -- Order by percentage descending
    c.contest_id ASC;  -- Then order by contest_id ascending
