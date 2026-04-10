SELECT e3.name as 'Department', e1.name as 'Employee', e1.salary as 'Salary' FROM employee e1 inner join department e3 on e1.departmentid = e3.id
WHERE 3 > (
    select count(distinct salary) from employee e2 WHERE e2.departmentId = e1.departmentId and e1.salary < e2.salary
);