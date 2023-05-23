---1

create table dept3_arka
(
dcode varchar(10) primary key,
dname varchar(30)
);

create table emp3_arka
(
ecode varchar(10) primary key,
dcode varchar(10),
name varchar(30),
grade varchar(1),
basic number(8,2),
jn_dt date default sysdate,
address varchar(50),
city varchar(20),
foreign key (dcode) references dept3_arka(dcode) ,
constraint c1 check (basic>=5000 and basic<=9000),
constraint c2 check(grade in ('A','B','C')),
constraint c3 check (name=upper(name))
);

create table leave3_arka
(
ecode varchar(10),
leave varchar(2),
from_dt date,
to_dt date,
foreign key (ecode) references emp3_arka(ecode) on delete cascade,
constraint c4 check(leave in ('CL', 'EL', 'ML'))
);

---2

insert into dept3_arka values('D1', 'Colonel');
insert into emp3_arka values('E1', 'D1', 'Adam', 'A', '2000', '2-JAN-2020', '5 Downing Street', 'Delhi');
insert into emp3_arka values('E1', 'D2', 'ADAM', 'A', '5000', '2-JAN-2020', '5 Downing Street', 'Delhi');
insert into emp3_arka values('E1', 'D1', 'ADAM', 'A', '5000', '2-JAN-2020', '5 Downing Street', 'Delhi');
delete from dept3_arka where dcode='D1';
insert into leave3_arka values('E1', 'CL', '20-JAN-2021', '22-JAN-2021');
insert into leave3_arka values ('E2' , 'EL', '20-FEB-2021', '22-FEB-2021');
insert into leave3_arka values ('E3' , 'CL', '20-JUN-2021', '22-JUN-2021');
insert into leave3_arka values ('E4' , 'EL', '20-AUG-2021', '22-AUG-2021');
delete from emp3_arka where ecode='E2';
---3

insert into emp3_arka values('E1', 'D1', 'ADAM', 'A', '5000', '2-JAN-2020', '5 Downing Street', 'Delhi');
insert into emp3_arka values('E2', 'D1', 'MARK', 'A', '7000', '3-JAN-2020', '5 Downing Street', 'Delhi');
insert into emp3_arka values('E3', 'D1', 'SUNIL', 'A', '7000', '4-JAN-2020', '5 Downing Street', 'Delhi');
insert into emp3_arka values('E4', 'D1', 'JOHN', 'A', '9000', '6-JAN-2020', '5 Downing Street', 'Delhi');

---a

create table temp3_arka as
(
select ecode, name, dname, basic from emp3_arka join dept3_arka on emp3_arka.dcode=dept3_arka.dcode where basic=7000 and emp3_arka.dcode='D1'
);

---b

insert into temp3_arka 
select ecode, name, dname, basic from emp3_arka join dept3_arka on emp3_arka.dcode=dept3_arka.dcode where basic>7000;

---c

alter table temp3_arka add net_pay number(8,2);

---d

update temp3_arka set net_pay = 1.5*basic;

---e

alter table temp3_arka drop column net_pay;

---4

drop table leave3_arka;
drop table emp3_arka;
drop table dept3_arka;

---5

create table book_arka
(
bid number(5,0),
sno number(5,0),
title varchar(20),
author varchar(20),
publisher varchar(20),
price number(7,2),
to_be_returned_by date,
status varchar(20),
primary key (bid, sno),
constraint b1 check(status in ('Available', 'Unavailable'))
);

create table maxbooks_arka
(
mtype varchar(20) primary key,
num number(2,0),
constraint m1 check(mtype in ('Student', 'Faculty'))
);

create table member_arka
(
mtype varchar(20),
mid number(5,0) primary key,
name varchar(20),
email varchar(20),
address varchar(20),
foreign key (mtype) references maxbooks_arka(mtype)
);

create table transaction_arka
(
bid number(5,0),
sno number(5,0),
mid number(5,0),
type_trans varchar(20),
dt_issue date,
dt_return date,
primary key (bid, sno, mid),
foreign key (mid) references member_arka(mid),
foreign key (bid,sno) references book_arka(bid,sno),
constraint t1 check(type_trans in ('Issue', 'Return'))
);

insert into maxbooks_arka values('Student', 1);
insert into maxbooks_arka values('Faculty',2);

insert into member_arka values ('Student', 1, 'Amit' , 'amit@gmail', '3 Lake Road'); 
insert into member_arka values ('Student', 2, 'Rahul' , 'rahul@gmail', '5 Lake Road');
insert into member_arka values ('Student', 3, 'Kiran' , 'kiran@gmail', '7 Lake Road');
insert into member_arka values ('Faculty', 4, 'Sohail' , 'f4@gmail', '9 Lake Road');
insert into member_arka values ('Faculty', 5, 'Arun' , 'f5@gmail', '11 Lake Road');
insert into member_arka values ('Faculty', 6, 'Kumar' , 'f6@gmail', '15 Lake Road');


--- 201, Robin Hood, Anon, Penguin, 300,

declare
sno book_arka.sno%type;	
title book_arka.title%type;
author book_arka.author%type;
publisher book_arka.publisher%type;
price book_arka.price%type;
last_id book_arka.bid%type;
begin
select max(bid) into last_id from book_arka;
if last_id is null 
then last_id:=0;
end if;
last_id := last_id + 1;
insert into book_arka values (last_id, &sno, '&title', '&author', '&publisher', &price, null, 'Available');
end;
/

declare
bidi book_arka.bid%type;
snoi book_arka.sno%type;
midi transaction_arka.mid%type;
type_transi transaction_arka.type_trans%type;
dti transaction_arka.dt_issue%type;
bki book_arka%rowtype;
mi member_arka%rowtype;
cnt_issue number(5,0);
cnt_total number(5,0);
begins
bidi := &bidi;
midi := &midi;
type_transi := '&type_transi';
dti := '&dti';
if (type_transi='Issue') then
	snoi := &snoi;
	select * into bki from book_arka where bid=bidi and sno=snoi and status='Available';
	select * into mi from member_arka where mid=midi;
	select num into cnt_total from maxbooks_arka where mtype=mi.mtype;
	select count(*) into cnt_issue from transaction_arka where mid=midi and type_trans='Issue';
	if (cnt_issue<cnt_total) then
		insert into transaction_arka values(bidi, snoi, midi, 'Issue', dti, null);
		update book_arka set status='Unavailable' , to_be_returned_by=dti+7 where bid=bidi and sno=snoi;
	else
		dbms_output.put_line('Max Limit already reached.');
	end if;
elsif (type_transi='Return') then
	select * into mi from member_arka where mid=midi;
	select count(*) into cnt_issue from transaction_arka where bid=bidi and mid=midi and type_trans='Issue';
	if(cnt_issue=1) then
		select sno into snoi from transaction_arka where bid=bidi and mid=midi and type_trans='Issue';
		update book_arka set status='Available', to_be_returned_by=null where bid=bidi and sno=snoi;
		update transaction_arka set dt_return=dti, type_trans='Return' where bid=bidi and sno=snoi and mid=midi;
	else
		dbms_output.put_line('No such book issued.');
	end if;
else
	dbms_output.put_line('Invalid transaction type.');
end if;
end;
/

---	select * into bki from book_arka where bid=bidi and sno=snoi and status='Unavailable';

---a

select count(*) as Total, bid from book_arka group by bid;
select count(*) as Issued, bid from book_arka where status = 'Unavailable' group by bid;

---b

select count(*), mid from transaction_arka where dt_return is null and dt_issue+7 < SYSDATE group by mid;

---c

select bid, sno, mid, type_trans, dt_issue, dt_return, dt_return-dt_issue-7 as Delay from transaction_arka where dt_return is not null and dt_return-dt_issue > 7;

---d

select mid, name from member_arka where mtype='Student'
and mid not in 
(
select mid from transaction_arka
);

select mid, name from member_arka where mtype='Faculty'
and mid not in 
(
select mid from transaction_arka
);

---e

select bid, count(*) from transaction_arka group by bid;

