	AREA RESET, CODE, READONLY
	
	MOV R0,0X09
	MOV R1,0X06
	
	ORR R1,R0,R1
HERE		B HERE

	AREA RESET, CODE, READONLY
	LDR R0,=0X40000000
	LDR R1,=0X40000050
	MOV R2,0X0A
	
BACK	LDR R3,[R0],#4
	    STR R3,[R1],#4
	    SUBS R2,R2,#1
	    BNE BACK
HERE		B HERE