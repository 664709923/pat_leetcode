184. Department Highest Salary My Submissions QuestionEditorial Solution
Total Accepted: 9116 Total Submissions: 48038 Difficulty: Medium
The Employee table holds all employees. Every employee has an Id, a salary, and there is also a column for the department Id.

+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
+----+-------+--------+--------------+
The Department table holds all departments of the company.

+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    |
+----+----------+
Write a SQL query to find employees who have the highest salary in each of the departments. For the above tables, Max has the highest salary in the IT department and Henry has the highest salary in the Sales department.

+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| Sales      | Henry    | 80000  |
+------------+----------+--------+

select max(Salary), DepartmentId from Employee group by DepartmentId;


select b.Name as Department, a.Name as Employee, a.Salary as Salary 
	from Employee as a join Department as b where a.DepartmentId=b.Id;


select * from (select b.Name as Department, a.Name as Employee, a.Salary as Salary 
	from Employee as a join Department as b where a.DepartmentId=b.Id) as t1 
join (select max(Salary) Salary, DepartmentId from Employee group by DepartmentId) as t2
where t1.

select * from Employee e1 join (select max(Salary), DepartmentId from Employee group by DepartmentId) e2
where e1.Salary=e2.Salary and e1.DepartmentId=e2.DepartmentId;


select b.Name Department, a.Name Employee, a.Salary Salary from
(select e1.Name Name, e1.Salary Salary, e1.DepartmentId DepartmentId from Employee e1 join 
	(select max(Salary) Salary, DepartmentId from Employee group by DepartmentId) e2
where e1.Salary=e2.Salary and e1.DepartmentId=e2.DepartmentId) a join Department b where a.DepartmentId=b.Id;
