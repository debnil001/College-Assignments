create database assignment3;
use assignment3;

create table department(
dcode int primary key,
dept_name varchar(50)
);

create table employee(
ecode int primary key,
name varchar(50),
dcode int not null,
address varchar(70),
city varchar(30),
basic float8 check(basic>=5000 && basic<=9000),
doj datetime default CURRENT_TIMESTAMP,
grades char(1) check (grades in ('A','B','C')),
foreign key(dcode) references department(dcode)
);

create table leave_reg(
ecode int not null,
leave_type char(3) check (leave_type in ('CL','El','ML')),
from_date date,
to_date date,
foreign key(ecode) references employee(ecode) on delete cascade
);
INSERT INTO department (dcode, dept_name)
VALUES (1, 'Sales');
INSERT INTO department (dcode, dept_name)
VALUES (2, 'Marketing');
INSERT INTO department (dcode, dept_name)
VALUES (3, 'Human Resources');

INSERT INTO employee (ecode, name, dcode, address, city, basic, grades)
VALUES (1, 'John Doe', 1, '123 Main Street', 'New York', 7000.00, 'A');
INSERT INTO employee (ecode, name, dcode, address, city, basic, doj, grades)
VALUES (2, 'Jane Smith', 2, '456 Elm Avenue', 'Los Angeles', 8000.00, '2023-05-28 10:30:00', 'B');
INSERT INTO employee (ecode, name, dcode, address, city, basic, grades)
VALUES (3, 'Sarah Johnson', 1, '789 Oak Lane', 'Chicago', 5000.00, 'C');
INSERT INTO employee (ecode, name, dcode, address, city, basic, doj, grades)
VALUES (4, 'Michael Brown', 2, '987 Pine Street', 'San Francisco', 7500.00, '2022-12-15 09:00:00', 'A');
INSERT INTO employee (ecode, name, dcode, address, city, basic, grades)
VALUES (5, 'Emily Wilson', 3, '654 Maple Avenue', 'Seattle', 8500.00, 'B');
INSERT INTO employee (ecode, name, dcode, address, city, basic, grades)
VALUES (6, 'Debnil Sarkar', 1, '123 Park Street', 'Kolkata', 9000.00, 'A');


INSERT INTO leave_reg (ecode, leave_type, from_date, to_date)
VALUES (1, 'CL', '2023-05-28', '2023-05-29');
INSERT INTO leave_reg (ecode, leave_type, from_date, to_date)
VALUES (2, 'El', '2023-06-01', '2023-06-05');
INSERT INTO leave_reg (ecode, leave_type, from_date, to_date)
VALUES (3, 'ML', '2023-06-10', '2023-06-20');



create view emp_view
as select ecode,name,dcode,basic from employee where dcode=1;

update emp_view set basic=basic+100;
drop view emp_view;


create view emp_view as
select e.ecode,dept_name,basic,leave_type,from_date,to_date from employee e
join department d on e.dcode=d.dcode
join leave_reg lr on lr.ecode=e.ecode;
drop view emp_view;


create table emp as(
select ecode,name,dept_name,basic from employee e 
join department d on e.dcode=d.dcode
where e.dcode=1 and basic=7000
); 
drop table emp;


create table emp as(
select ecode,name,dept_name,basic from employee e 
join department d on e.dcode=d.dcode
where e.dcode=1 and basic>=7000
); 


alter table emp
add column net_pay float8 not null;

update emp set net_pay=basic*1.5;