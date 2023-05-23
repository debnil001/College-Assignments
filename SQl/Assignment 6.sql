--- 1

create table result_arka
(
roll number(3,0),
scode number(3,0),
marks number(5,2),
primary key (roll, scode)
);

create table backpaper
(
roll number(3,0),
scode number(3,0),
primary key (roll, scode),
foreign key (roll, scode) references result_arka(roll, scode)
;

--- to insert

create trigger insert_result_trigger
after 
insert on result_arka
for each row
begin
if :new.marks<50 then
	insert into backpaper values(:new.roll, :new.scode);
end if;
end;
/

--- 

insert into result_arka values(1,2,70);
insert into result_arka values(2,5,20);

--- to delete

create or replace trigger delete_result_trigger
before 
delete on result_arka
for each row
begin
if :old.marks<50 then
	delete backpaper where roll=:old.roll and scode=:old.scode;
end if;
end;
/

---

delete from result_arka where roll=2;

--- to update

create or replace trigger update_result_trigger
after
update on result_arka
for each row
begin
if :old.marks<50 and :new.marks>=50 then
	delete backpaper where roll=:old.roll and scode=:old.scode;
end if;
if :old.marks>=50 and :new.marks<50 then
	insert into backpaper values(:new.roll, :new.scode);
end if;
end;
/

---

update result_arka set marks=40 where marks=70;
update result_arka set marks=70 where marks=40;

--- 2

create table request_arka
(
req_no number(3,0) primary key,
req_dt date
);

create table service_log_arka
(
entry_no number(3,0) primary key,
req_no number(3,0),
service_dt date
);

create sequence service_sequence;

CREATE OR REPLACE TRIGGER service_on_insert
  BEFORE INSERT ON service_log_arka
  FOR EACH ROW
BEGIN
  SELECT service_sequence.nextval
  INTO :new.entry_no
  FROM dual;
END;
/

insert into request_arka values(1,'22-JAN-2020');
insert into request_arka values(2,'05-MAR-2021');

create or replace trigger request_erase_trigger
after
delete on request_arka
for each row
begin
	insert into service_log_arka(req_no, service_dt) values (:old.req_no, TO_CHAR(SYSDATE, 'DD-MON-YYYY'));
end;
/

delete from request_arka where req_no=2;