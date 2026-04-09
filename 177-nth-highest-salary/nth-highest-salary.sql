CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set n = n -1;
  RETURN (
      # Write your MySQL query statement below.
        -- select distinct salary from employee e1 where (n-1) = (select count(distinct e2.salary) from employee e2 where e1.salary < e2.salary)
        select distinct(salary) from employee order by salary desc limit 1 offset n
  );
END