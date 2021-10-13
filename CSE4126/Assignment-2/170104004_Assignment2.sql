--Find Students sname who entrolled a course which is conducted by a faculty name as 'Zobair'
CLEAR SCREEN;
SET VERIFY OFF;
SET SERVEROUTPUT ON;

Declare

	num STUDENT.snum% TYPE:=0;
	s_name STUDENT.sname%TYPE:=0;

Begin

	select count(snum) into num from STUDENT;

	FOR i IN 1..26 LOOP
		num :=num+1;

		IF(num)= 1 || 14  THEN
        
			select STUDENT.sname into s_name from STUDENT  
			inner join ENROLLED on STUDENT.snum=ENROLLED.snum
			inner join COURSE on ENROLLED.cnum=COURSE.cnum
			inner join FACULTY on COURSE.Fid=FACULTY.Fid where FACULTY.fName='Zobair';
			DBMS_OUTPUT.PUT_LINE(s_name);
			
			
		END IF;
		
	
	END LOOP;       

END;

/