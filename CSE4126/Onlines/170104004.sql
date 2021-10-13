SET SERVEROUTPUT ON;
SET VERIFY OFF;
ACCEPT X NUMBER PROMPT "Enter ID="
ACCEPT Y CHAR PROMPT "Enter PASSWORD="


DECLARE
	
	A NUMBER;
	C VARCHAR2(10);
	FOUNT INT:=0;
	
BEGIN
	A:=&X;
	C:='&Y';
	DBMS_OUTPUT.PUT_LINE(A);
	DBMS_OUTPUT.PUT_LINE(C);		
END;
/
CREATE OR REPLACE FUNCTION INPUTFUNC
RETURN (supplier.sid%TYPE,supplier.sname%TYPE)
IS

P supplier.sid%TYPE;
Q supplier.sname%TYPE;


BEGIN
	
	FOR R IN (SELECT * FROM supplier) LOOP
		P := R.sid;
		Q := R.sname;
		IF P=A THEN
			f:=1;
			OUTPUTFUNC(p);
		ELSE
			F:=0;
			DBMS_OUTPUT.PUT_LINE('NOT FOUNT');
		END IF;
			
			
		
	END LOOP;
	return (P,Q);
END INPUTFUNC;
/

CREATE OR REPLACE PROCEDURE OUTPUTFUNC(P IN supplier.sid%TYPE)
IS

BEGIN
	DBMS_OUTPUT.PUT_LINE(P);
	
END OUTPUTFUNC;
/

DECLARE
	P supplier.sid%TYPE;
BEGIN
	IF P=1 THEN
		DBMS_OUTPUT.PUT_LINE('Welcome back Sham!');
	IF P=4 THEN
		DBMS_OUTPUT.PUT_LINE('Account not Found. Please Sign up.');
	IF P=3 THEN
		DBMS_OUTPUT.PUT_LINE('Invalid credentials.');
		
	OUTPUTFUNC(P);
	DBMS_OUTPUT.PUT_LINE(P);
END;
/