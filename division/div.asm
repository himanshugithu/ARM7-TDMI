	 AREA RESET,CODE,READONLY
	
	 LDR R0,=0X00000007 ; TAKE FIRST NUMBER (DIVIDENT)
	 LDR R1,=0X00000002 ; TAKE SECOND NUMBER (DIVISOR)
	 LDR R2,=0X00000000 ; INITIALIZE REGISTER FOR QUOTIENT
	 CMP R1,0x00        ; COMPARE R1 WITH 00 FOR EX(5/0=UNDEFINE , 0/5= 0) 
	 BEQ STOP           ; ZERO FLAG SET AND JUMP TO LABLE "STOP"
	 
JUMP CMP R0,R1          ; COMPARE R0 AND R1 IF RO < R1 
	 BMI DONE           ; NEGATIVE FLAG SET JUMP TO LABLE "DONE"
     SUB R0,R0,R1 		; SUBTRACT R0-R1 => R0
	 ADD R2,R2,#01      ; INCREMENT R2 BY ONE FOR QUOTIENT
	 B JUMP             ; UNCONDITIONAL JUMP
	 
DONE MOV R7,R0          ; REMAINDER
     MOV R6,R2          ; QUOTIENT
STOP MOV R10,0X00       ; DUMMY INSTRUCTION
     END 
	