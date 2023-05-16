use employee_mca05;

create table designation_mca05(
desig_code varchar(16) primary key not null,
desig_desc varchar(20)
);

create table department_mca05(
dept_code varchar(16) primary key not null,
dept_name varchar(20)
);

create table employee_mca05(
emp_code varchar(16) primary key not null,
emp_name varchar(20) not null,
dept_code varchar(16),
desig_code varchar(16),
sex varchar(1),
address varchar(20),
city varchar(20),
state varchar(20),
pin char(6),
basic int,
jn_dt date,
foreign key(dept_code) references department_mca05(dept_code),
foreign key(desig_code) references designation_mca05(desig_code)
);

-- desc employee_mca05;
-- desc designation_mca05;
-- desc department_mca05;
insert into designation_mca05 values("122","Manager");
insert into designation_mca05 values("112","Executive");
insert into designation_mca05 values("125","Officer");
insert into designation_mca05 values("150","Clerk");
insert into designation_mca05 values("142","Helper");

insert into department_mca05 values("100","Personnel");
insert into department_mca05 values("101","Production");
insert into department_mca05 values("102","Purchase");
insert into department_mca05 values("103","Finance");
insert into department_mca05 values("104","Research");

insert into employee_mca05 values("E12","ABC","103","125","M","Park Street, CA","Los Angelos","Albuquerque","215367","25000","1991-12-25");
insert into employee_mca05 values("E13","XYZ","104","150","M","Park Street, CA","Los Angelos","Albuquerque","215317","25000","1991-12-25");
insert into employee_mca05 values("E15","JKL","100","142","F","LA Street, QA","Los Pollos","Phiyal","214617","25050","2000-11-26");
insert into employee_mca05 values("E16","MNO","102","142","F","Simon St, PX","Hermanos","Pipoline","215617","35000","2001-06-20");
insert into employee_mca05 values("E17","QRS","100","150","M","KK Blair st, WS","Dutch","Nishamint","253618","45000","2004-10-1");
insert into employee_mca05 values("E19","UVW","101","122","M","Perks Lane, PA","Orangeon","Itialier","100617","50000","1993-10-21");

alter table employee_mca05
alter dept_code set default null;

alter table employee_mca05
alter basic set default 0;

insert into employee_mca05 values("E59","UVW",default,"122","M","Perks Lane, PA","Orangeon","Itialier","100617",default,"1993-10-26");
insert into employee_mca05 values("E79","UVW",default,"122","M","Perks Lane, PA","Orangeon","Itialier","100617",default,"1992-06-15");
insert into employee_mca05 values("E66","UVW",default,"122","M","Perks Lane, PA","Orangeon","Itialier","100617",default,"2004-05-12");
insert into employee_mca05 values("E44","UVW",default,"122","M","Perks Lane, PA","Orangeon","Itialier","100617",default,"2000-03-28");

select * from employee_mca05;

select * from employee_mca05
where dept_code is null;

select * from employee_mca05
where basic=0;







