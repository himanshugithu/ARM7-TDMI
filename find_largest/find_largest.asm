	AREA RESET, CODE, READONLY
	
	LDR R0,=0X40000000
	MOV R1,0X00
	MOV r2,0x00
	MOV R3,0X09
	
JUMP	LDRB R1,[R0],#1
	CMP R1,R2
	MOVPL R2,R1
	SUBS R3,R3,#01
	BNE JUMP
	STRB R2,[R0]
HERE	B HERE
	END	