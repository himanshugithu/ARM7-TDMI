	AREA RESET, CODE, READONLY
	
	    MOV R7,0X04  ; OUTER LOOP
BACK2	    MOV R6,0X04; INNER LOOP
	    LDR R0,=0X40000000
	
BACK1	    LDRB R2,[R0],#1
	    LDRB R3,[R0]
	    CMP R2,R3
            BMI SKIP
	    
		STRB R2,[R0]
		SUB R0,R0,#1
		STRB R3,[R0]
		ADD R0,R0,#1 
	
SKIP        SUBS R6,R6,#1
	    BNE BACK1
	    SUBS R7,R7,#1
	    BNE BACK2
HERE	    B HERE
	    END
