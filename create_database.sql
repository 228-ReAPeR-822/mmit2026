CREATE DATABASE IF NOT EXISTS bench_db;
USE bench_db;

DROP TABLE IF EXISTS numbers;
CREATE TABLE numbers (n INT);
INSERT INTO numbers VALUES (0),(1),(2),(3),(4),(5),(6),(7),(8),(9);

DROP TABLE IF EXISTS users;
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    group_id INT,
    INDEX(group_id)
);

INSERT INTO users (name, group_id)
SELECT CONCAT('User_', a.n + b.n*10 + c.n*100 + d.n*1000 + e.n*10000), (a.n + b.n*10) % 100
FROM numbers a, numbers b, numbers c, numbers d, numbers e;

DROP TABLE IF EXISTS orders;
CREATE TABLE orders (
    id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT,
    amount DECIMAL(10,2),
    order_date DATE,
    INDEX(user_id)
);

INSERT INTO orders (user_id, amount, order_date)
SELECT (a.n + b.n*10 + c.n*100 + d.n*1000 + e.n*10000) % 100000 + 1, 
       (a.n + b.n*10) * 10.5, 
       DATE_ADD('2023-01-01', INTERVAL (a.n + b.n*10) DAY)
FROM numbers a, numbers b, numbers c, numbers d, numbers e;