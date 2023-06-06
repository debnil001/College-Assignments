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
insert into employee_mca05 values("E1443","XYZ","104","150","M","Park Street, CA","Los Angelos","Albuquerque","215317","25000","1991-12-25");
insert into employee_mca05 values("E1544","JKL","100","142","F","LA Street, QA","Los Pollos","Phiyal","214617","25050","2000-11-26");
insert into employee_mca05 values("E1674","MNO","102","142","F","Simon St, PX","Hermanos","Pipoline","215617","35000","2001-06-20");
insert into employee_mca05 values("E1700","QRS","100","150","M","KK Blair st, WS","Dutch","Nishamint","253618","45000","2004-10-1");
insert into employee_mca05 values("E1998","UVW","101","122","M","Perks Lane, PA","Orangeon","Itialier","100617","50000","1993-10-21");
insert into employee_mca05 values("E1008","SSS","101","142","M","Perker St, PA","Jill","Italy","123617","41000","2022-02-28");

-- inserting rows without dept_code and basic
insert into employee_mca05 values("E5977","emp1",default,"122","M","Perks Lane, PA","Orangeon","Usawa","410617",default,"1993-01-26");
insert into employee_mca05 values("E7900","emp5",default,"122","F","Perks Lane, PA","Arkentine","Lokapet","550617",default,"1999-06-15");
insert into employee_mca05 values("E6662","emp7",default,"122","F","Perks Lane, PA","Otawatis","Plinit","100417",default,"2014-05-12");
insert into employee_mca05 values("E4410","emp2",default,"122","M","Perks Lane, PA","Kiminipo","Aquen","152617",default,"1990-09-15");

-- find row with unassigned dept_code
-- select * from employee_mca05 where dept_code is NULL;

-- find row where basic is zero
-- select * from employee_mca05 where basic is null;

-- find average salary of employee
-- select avg(basic) as average_salary from employee_mca05;

-- replace all basic with 0 for the row with unassigned basic
-- update employee_mca05 
-- set basic=0 where basic is null;
-- select avg(basic) from employee_mca05;

-- delete the rows with unassigned dept_cod
-- delete from employee_mca05 where dept_code is null;
-- select * from employee_mca05;

-- find net pay from empployee table
-- select emp_name, (basic+(basic*50*40)/200) as "Net Pay" from employee_mca05;

-- show emp_name and basic in ascending order of dept_code
-- select upper(emp_name) as "EMP NAME",basic from employee_mca05 order by dept_code;

-- select * from employee_mca05 where join_date>"2010-01-01";

-- select count(*) as "Employee Count" from employee_mca05 where month(join_date)=1;

-- select max(basic) as "Max Salary" from employee_mca05;
-- select min(basic) as "Minimum Salary" from employee_mca05;

-- select count(*) as "Female Employee Count" from employee_mca05 where sex="F";

-- update employee_mca05 set city=upper(city);
-- select * from employee_mca05;

-- select count(distinct(city)) as "Count of Cities" from employee_mca05;


-- select * from employee_mca05 order by dept_code,basic desc;
