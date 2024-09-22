-- Code 1:
select coalesce(
    (select max(salary) from employee 
        where salary < (select max(salary) from employee)), null) as SecondHighestSalary;

-- Code 2:
select coalesce(
    (select distinct salary from employee
        order by salary desc limit 1, 1), null) as SecondHighestSalary;