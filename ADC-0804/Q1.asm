
P2.6 = WR 
; P2.7 = INTR 
; P2.5 = RD 
; P1.0 – P1.7 = D0 – D7 of the ADC0804
;
MOV P1, #0FFH ; make P1=input
BACK: CLR P2.6 ; WR=0
SETB P2.6 ; WR=1 L-to-H to start conversion
HERE: JB P2.7, HERE ; wait for end of conversion
CLR P2.5 ; conversion finished, enable RD
MOV A, P1 ; read the data
ACALL DATA_DISPLAY ; display the data
SETB P2.5 ; make RD=1 for next round
SJMP BACK


