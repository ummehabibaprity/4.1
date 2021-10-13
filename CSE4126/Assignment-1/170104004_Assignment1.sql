clear screen;
drop table Suppliers;
drop table Parts;
drop table Catalogg;


create table Suppliers(sid int,sname varchar2(30),address varchar2(30));
create table Parts(pid int,pname varchar2(30),color varchar2(30));
create table Catalogg(sid int,pid int,cost real);


insert into Suppliers values(1,'sp1','Tangail');
insert into Suppliers values(2,'sp2','Dhaka');
insert into Suppliers values(3,'sp3','Mymensing');
insert into Suppliers values(4,'sp4','Rajshahi');
insert into Suppliers values(5,'sp5','Khulna');
insert into Suppliers values(6,'sp6','Tangail');


insert into Parts values(1,'pt1','white');
insert into Parts values(2,'pt2','black');
insert into Parts values(3,'pt3','red');
insert into Parts values(4,'pt4','red');
insert into Parts values(5,'pt5','green');
insert into Parts values(7,'pt5','purple');


insert into Catalogg values(6,6,1000);
insert into Catalogg values(3,2,2000);
insert into Catalogg values(6,3,3000);
insert into Catalogg values(4,4,4000);
insert into Catalogg values(5,4,6000);
insert into Catalogg values(2,1,8000);
insert into Catalogg values(1,2,12000);
insert into Catalogg values(4,3,10000);
insert into Catalogg values(4,4,10000);
insert into Catalogg values(2,5,1200);
insert into Catalogg values(1,7,1400);



select * from Suppliers;
select * from Parts;
select * from Catalogg;


--Qb1



select distinct Suppliers.sid from Suppliers
inner join Catalogg on Suppliers.sid=Catalogg.sid
inner join Parts on Catalogg.pid=Parts.pid
where Parts.color='red' or Parts.color='green';


--Qb2


select distinct Suppliers.sname from Suppliers
inner join Catalogg on Suppliers.sid=Catalogg.sid
inner join Parts on Catalogg.pid=Parts.pid
where Parts.color='red';


--Qb3


select distinct Suppliers.sid from Suppliers
inner join Catalogg on Suppliers.sid=Catalogg.sid
inner join Parts on Catalogg.pid=Parts.pid
where Catalogg.cost>( select avg (Catalogg.cost)
from Catalogg );

 


commit;


