SET SERVEROUTPUT ON;
SET VERIFY OFF;

CREATE OR REPLACE PACKAGE mypack AS

	FUNCTION F1(A1 IN SUPPLIER.SID%TYPE,B1 IN SUPPLIER.SNAME%TYPE)
	RETURN NUMBER;
	
	PROCEDURE P1(B1 IN NUMBER);
END mypack;
/

CREATE OR REPLACE PACKAGE BODY mypack AS
	PROCEDURE P1(B1 IN NUMBER)
	IS
	
	BEGIN
	
		
		IF B1=1 THEN
			DBMS_OUTPUT.PUT_LINE('Welcome back.');
		ELSIF B1=2 THEN
			DBMS_OUTPUT.PUT_LINE('Invalid credentials');
		ELSIF B1=3 THEN
			DBMS_OUTPUT.PUT_LINE('Account not found. Please sign up.');		
	  
		END IF; 
		
	END P1;
	

	FUNCTION F1(A1 IN SUPPLIER.SID%TYPE,B1 IN SUPPLIER.SNAME%TYPE)
	RETURN NUMBER
	IS 
	C NUMBER;

	A SUPPLIER.SID%TYPE;
	B SUPPLIER.SNAME%TYPE;
	
	BEGIN
   	
		FOR R IN (SELECT * FROM SUPPLIER) LOOP  
			A := R.SID;
			B := R.SNAME;
						
			IF A=A1 and B=B1  THEN
				C := 1;
				DBMS_OUTPUT.PUT_LINE(B||'!');
				EXIT;
			ELSIF A=A1 and B!=B1  THEN 
            	C := 2;
				EXIT;
			ELSE
				C := 3;
				EXIT;			 
			
			END IF;	
		  		
		END LOOP;
   	
		RETURN C;

	END F1;
	
	
	
END mypack;
/

CREATE OR REPLACE TRIGGER T1 
BEFORE UPDATE 
OF SNAME
ON SUPPLIER
FOR EACH ROW
DECLARE
	A SUPPLIER.SID%TYPE;
	B SUPPLIER.SNAME%TYPE;

BEGIN
	A := :OLD.SID;
	B := :OLD.SNAME;
	INSERT INTO supplier2 VALUES(A, B);
END;
/

ACCEPT X NUMBER PROMPT "ENTER ID = "
ACCEPT Y CHAR PROMPT "ENTER PASSWORD = "

DECLARE
    A SUPPLIER.SID%TYPE;
	B SUPPLIER.SNAME%TYPE;
	D NUMBER;
	PRITY EXCEPTION;
	
	

BEGIN
    A := &X;
	B := '&Y';
	D := mypack.F1(A,B);
	mypack.P1(D);
	IF A < 0 THEN
		RAISE PRITY;
	END IF;
	
	EXCEPTION
	
	WHEN PRITY THEN
		DBMS_OUTPUT.PUT_LINE('Cannot be -ve');
	WHEN  ACCESS_INTO_NULL	 THEN
       dbms_output.put_line('Access into null execption');
    WHEN  CASE_NOT_FOUND THEN
       dbms_output.put_line('Case not found exception');	
	WHEN INVALID_NUMBER THEN
        DBMS_OUTPUT.PUT_LINE('Invalid number exception');
	WHEN LOGIN_DENIED THEN
        DBMS_OUTPUT.PUT_LINE('Login denied');
	WHEN  OTHERS THEN
       DBMS_OUTPUT.PUT_LINE('Exception other');

END;
/


drop table supplier2 ;

create table supplier2(
sid     integer, 
sname   varchar2(30),
PRIMARY KEY (sid));

select * from supplier2;


