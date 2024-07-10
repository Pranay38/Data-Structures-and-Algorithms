SELECT s.name
FROM salesperson s
WHERE s.sales_id NOT IN (
    SELECT s.sales_id
    FROM salesperson s
    LEFT JOIN orders o ON s.sales_id = o.sales_id
    LEFT JOIN company c ON o.com_id = c.com_id
    WHERE c.name = "RED"
);
