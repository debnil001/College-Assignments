---1

create table emp_temp_arka
(
ecode number(3,0) primary key,
enamae varchar(30),
dcode number(3,0),
basic number(8,2),
foreign key (dcode) references dept_temp_arka(dcode)
);

insert into emp_temp_arka values(1, 'A', 1, 20000);
insert into emp_temp_arka values(2, 'B', 2, 30000);
insert into emp_temp_arka values(3, 'C', 1, 40000);
insert into emp_temp_arka values(5, 'D' ,3 ,25000);

DECLARE
r emp_temp_arka%rowtype;
BEGIN
select * into r from emp_temp_arka where ecode = &ecode;
dbms_output.put_line(r.enamae);
EXCEPTION
WHEN no_data_found THEN
dbms_output.put_line('No such employee found.');
END;
/

---2

create table dept_temp_arka
(
dcode number(3,0) primary key,
dname varchar(30)
);

insert into dept_temp_arka values (1, 'Finance');
insert into dept_temp_arka values (2, 'Technology');
insert into dept_temp_arka values (3, 'Management');

DECLARE
ecodei emp_temp_arka.ecode%type;
enamei emp_temp_arka.enamae%type;
dcodei emp_temp_arka.dcode%type;
basici emp_temp_arka.basic%type;
cnte number(3,0);
cntd number(3,0);
BEGIN
ecodei := &ecodei;
enamei := '&enamei';
dcodei := &dcodei;
basici := &basici;
select count(*) into cnte from emp_temp_arka where ecode = ecodei;
select count(*) into cntd from dept_temp_arka where dcode = dcodei;
IF cnte = 0 and cntd = 1 THEN
	insert into emp_temp_arka values(ecodei, enamei, dcodei, basici);
ELSE
	dbms_output.put_line('Invalid Data.');
END IF;
END;
/

---3

select * from 
(
select * from emp_temp_arka order by basic desc
)
where rownum <= 5;

---4

DECLARE
cnt number(3,0);
dcodei emp_temp_arka.dcode%type;
BEGIN
dcodei:=&dcodei;
select count(*) into cnt from emp_temp_arka where dcode=dcodei;
delete from emp_temp_arka where dcode = dcodei;
dbms_output.put_line('Deleted number of users is ');
dbms_output.put_line(TO_CHAR(cnt));
END;
/

---5


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
begin
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

---6

create table leave_temp_arka
(
ecode number(3,0),
monthno number(2,0),
leave number(2,0),
primary key (ecode, monthno),
foreign key(ecode) references emp_temp_arka(ecode)
);

insert into leave_temp_arka values(1,1,10);
insert into leave_temp_arka values(1,2,10);
insert into leave_temp_arka values(2,2,20);

---select emp_temp_arka.ecode, enamae, basic-(basic*leave)/(CAST(to_char(LAST_DAY(TO_DATE(monthno, 'MM')),'dd') AS INT)) as ebasic from emp_temp_arka join leave_temp_arka on emp_temp_arka.ecode = leave_temp_arka.ecode;

DECLARE
ecodei emp_temp_arka.ecode%type;
monthi leave_temp_arka.monthno%type;
cnt number(3,0);
ans number(8,2);
BEGIN
ecodei:=&ecodei;
monthi:=&monthi;
select count(*) into cnt from emp_temp_arka where ecode=ecodei;
if(cnt=1) then
		select basic into ans from emp_temp_arka where ecode=ecodei;
		select count(*) into cnt from leave_temp_arka where ecode=ecodei and monthno=monthi;
		if(monthi>=0 and monthi<=11) then
			if(cnt=1) then
				select basic-(basic*leave)/(CAST(to_char(LAST_DAY(TO_DATE(monthno, 'MM')),'dd') AS INT)) into ans from emp_temp_arka join leave_temp_arka on emp_temp_arka.ecode = leave_temp_arka.ecode and emp_temp_arka.ecode=ecodei and monthno=monthi;
			end if;
			dbms_output.put_line('Salary for the month is: ');
			dbms_output.put_line(to_char(ans));
		else
			dbms_output.put_line('Incorrect month number.');
		end if;
	else
		dbms_output.put_line('Employee does not exist');
	end if;
END;
/

---7

create table ordermast_arka
(
order_no char(5) primary key,
order_dt date
);

create table orderdetails_arka
(
order_no char(5) references ordermast_arka(order_no),
item_no char(5),
qty number(5,0),
primary key (order_no, item_no)
);

create table deliverymast_arka
(
delv_no char(5) primary key,
order_no char(5),
delv_dt date
);

create table delivery_details_arka
(
delv_no char(5) references deliverymast_arka(delv_no),
item_no char(5),
qty number(5,0),
primary key(delv_no, item_no)
);

insert into ordermast_arka values('O1','20-JAN-2021');
insert into ordermast_arka values('O2','22-JAN-2021');
insert into ordermast_arka values('O3','1-FEB-2021');

insert into orderdetails_arka values('O1','I1',20);
insert into orderdetails_arka values('O1','I2',30);
insert into orderdetails_arka values('O2','I1',10);
insert into orderdetails_arka values('O2','I2',5);
insert into orderdetails_arka values('O3','I1',20);

insert into deliverymast_arka values('D1','O1','20-FEB-2021');
insert into deliverymast_arka values('D2','O1','25-FEB-2021');
insert into deliverymast_arka values('D3','O2','07-MAR-2021');
insert into deliverymast_arka values('D4','O3','07-MAR-2021');

insert into delivery_details_arka values('D1','I1', 10);
insert into delivery_details_arka values('D1','I2', 10);
insert into delivery_details_arka values('D2','I1', 10);
insert into delivery_details_arka values('D2','I2', 5);
insert into delivery_details_arka values('D3','I2', 5);
insert into delivery_details_arka values('D4','I1', 20);

create table temp_arka
(
	order_no char(5),
	item_no char(5),
	qty number(3,0)
);

create table left_arka
(
	order_no char(5) references ordermast_arka(order_no),
	item_no char(5),
	qty number(5,0)
);

DECLARE
BDATE ordermast_arka.order_dt%type;
EDATE ordermast_arka.order_dt%type;
BEGIN
BDATE:='&BDATE';
EDATE:='&EDATE';
insert into temp_arka  
select deliverymast_arka.order_no as order_no, delivery_details_arka.item_no as item_no, sum(delivery_details_arka.qty) as qty from delivery_details_arka, deliverymast_arka, ordermast_arka where delivery_details_arka.delv_no = deliverymast_arka.delv_no and deliverymast_arka.order_no = ordermast_arka.order_no and ordermast_arka.order_dt>=BDATE and ordermast_arka.order_dt<=EDATE group by deliverymast_arka.order_no, delivery_details_arka.item_no;

insert into left_arka
select orderdetails_arka.order_no, orderdetails_arka.item_no, orderdetails_arka.qty from orderdetails_arka, ordermast_arka where orderdetails_arka.order_no = ordermast_arka.order_no and ordermast_arka.order_dt>=BDATE and ordermast_arka.order_dt<=EDATE;

FOR cursoradj in (select * from temp_arka)
	LOOP
	update left_arka set qty=qty-cursoradj.qty where order_no=cursoradj.order_no and item_no=cursoradj.item_no;
	END LOOP;

FOR cursor1 IN (SELECT * FROM left_arka) 
	LOOP
	DBMS_OUTPUT.PUT_LINE('ORDER NO = ' || cursor1.order_no || ', ITEM NO = ' || cursor1.item_no || ', QTY = ' || cursor1.qty);
	END LOOP;
delete from temp_arka;
delete from left_arka;
END;
/