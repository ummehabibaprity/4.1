clear screen;
SET VERIFY OFF;
SET SERVEROUTPUT ON;
DECLARE
	input NUMBER;
	num money.id%TYPE:=0;
		
BEGIN
    dbms_output.put_line('1. move');
    dbms_output.put_line('2. undo');
	dbms_output.put_line('Choose an option');
    input := '&C';
    IF input = 1 THEN
		dbms_output.put_line(input||'.move');
		select count(id) into num from money;
		for i IN 1..3 LOOP
		num:=num+1;
		insert into newmoney values(num,'D',300);
		delete from money where id=num;
		END LOOP;
		
		
    ELSE
		dbms_output.put_line(input||'.undo');
		insert into money select * from newmoney;
    END IF;
END;

/
commit;

--select * from money;
--select * from newmoney;