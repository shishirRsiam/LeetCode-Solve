select EM.name as Employee from Employee as EM, Employee as MN
where EM.managerId = MN.id and EM.salary > MN.salary;