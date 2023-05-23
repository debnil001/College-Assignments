-- designation table
create table designation_mca05(
desig_code varchar(16) primary key not null,
desig_desc varchar(20)
);
-- department table
create table department_mca05(
dept_code varchar(16) primary key not null,
dept_name varchar(20)
);
-- employee table
create table employee_mca05(
emp_code varchar(16) primary key not null,
emp_name varchar(20),
dept_code varchar(16),
desig_code varchar(16),
sex varchar(1),
address varchar(20),
city varchar(20),
state varchar(20),
pin char(6),
basic int,
join_date date
);
-- inserting values into designation table
insert into designation_mca05 values("122","Manager");
insert into designation_mca05 values("112","Executive");
insert into designation_mca05 values("125","Officer");
insert into designation_mca05 values("150","Clerk");
insert into designation_mca05 values("142","Helper");
-- inserting values into department table
insert into department_mca05 values("100","Personnel");
insert into department_mca05 values("101","Production");
insert into department_mca05 values("102","Purchase");
insert into department_mca05 values("103","Finance");
insert into department_mca05 values("104","Research");
-- inserting values into employee table
insert into employee_mca05 values("E1254","ABC","103","125","M","Park Street, CA","Los Angelos","Albuquerque","215367","25000","1991-12-25");
insert into employee_mca05 values("E1443","XYZ","103","150","M","Park Street, CA","Los Angelos","Albuquerque","215317","25000","2010-12-25");
insert into employee_mca05 values("E1544","JKL","100","142","F","LA Street, QA","Los Pollos","Phiyal","214617","25050","2000-11-26");
insert into employee_mca05 values("E1674","MNO","102","142","F","Simon St, PX","Hermanos","Pipoline","215617","35000","2000-06-20");
insert into employee_mca05 values("E1700","QRS","100","150","F","KK Blair st, WS","Dutch","Nishamint","253618","45000","2004-10-1");
insert into employee_mca05 values("E1998","UVW","101","122","F","Perks Lane, PA","Orangeon","Itialier","100617","50000","1993-10-21");
insert into employee_mca05 values("E1008","SSS","101","142","M","Perker St, PA","Jill","Italy","123617","41000","2022-02-28");


--1
-- select dept_code,min(basic),max(basic),avg(basic) from employee_mca05 group by dept_code;


--2
-- select dept_code,count(*) from employee_mca05 where sex="F" group by dept_code;


-- 3
-- select dept_code,city,count(*) from employee_mca05 group by dept_code,city;


-- 4
-- select desig_code,count(*) from employee_mca05 where YEAR(join_date)=2000 group by desig_code,dept_code order by count(*) desc;

-- 5
-- select dept_code,sum(basic) from employee_mca05 group by dept_code having sum(basic)>50000 order by sum(basic) desc;


--6
-- select emp_name,desig_desc,basic from employee_mca05 
-- join designation_mca05 on employee_mca05.desig_code=designation_mca05.desig_code;


-- 7
-- select emp_name,dept_name,desig_desc,basic from employee_mca05 
-- join designation_mca05 on employee_mca05.desig_code=designation_mca05.desig_code
-- join department_mca05 on employee_mca05.dept_code=department_mca05.dept_code;


-- 8
-- select dept_code from employee_mca05 group by dept_code having count(*)=0;


-- 9
-- select dept_name from employee_mca05 join employee_mca05.dept_code=department_mca05.dept_code;


-- 10
select dept_name from employee_mca05 join department_mca05 
on employee_mca05.dept_code=department_mca05.dept_code 
group by dept_name having count(*)>=10;


-- 11
select dept_code from employee_mca05 where basic=(select max(basic) from employee_mca05);

-- 12
select desig_desc from employee_mca05 join designation 
on designation.desig_code=employee_mca05.desig_code
where basic=(select max(basic) from employee_mca05);


-- 13
select dept_code,count(*) as "No. of Managers" from employee_mca05 join department_mca05
on employee_mca05.dept_code=department_mca05.dept_code
join designation_mca05 on employee_mca05.desig_code=designation_mca05.desig_code where desig_desc="Manager"
group by dept_code;


-- 14
select basic from employee_mca05 order by basic desc limit 1;

-- 15
select basic from employee_mca05 order by basic limit 1;


--16
select dept_name from department_mca05 join employee_mca05 on employee_mca05.dept_code=department_mca05.dept_code
where basic=(select max(basic) from employee_mca05);

-- 16
select dept_name,sum(basic) from department_mca05 join employee_mca05 on employee_mca05.dept_code=department_mca05.dept_code
group by department_mca05.dept_name order by sum(basic) desc limit 1;

-- 17

insert into employee_mca05 values("E1254","LLL","100","277","F","Park Street, CA","Los Angelos","Albuquerque","215367","25000","1999-12-25");
insert into employee_mca05 values("E1443","QQQ","103","355","M","Park Street, CA","Los Angelos","Albuquerque","215317","25000","2000-10-10");

-- 18
delete from employee_mca05 where desig_code not in(
select desig_code from designation_mca05
);

-- 19
select emp_name,basic from employee_mca05 e1 join department_mca05 e2 
on e1.dept_code=e2.dept_code where e1.basic>(select avg(basic) from employee_mca05 group by dept_code) ans e1.sex="F";


-- 20
select count(*) as "Count of female employee" from employee_mca05 join designation_mca05 
on employee_mca05.desig_code=designation_mca05.desig_code where desig_desc="Manager" and sex="F";