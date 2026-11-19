SELECT COUNT(*), SUM(o.amount)
FROM users u
JOIN orders o ON u.id = o.user_id
WHERE o.order_date BETWEEN '2023-02-01' AND '2023-10-01' 
  AND u.group_id < 50;