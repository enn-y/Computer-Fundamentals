// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R1 and R2 and stores the result in R3.
// (R1, R2, R3 refer to RAM[1], RAM[2], and RAM[3], respectively.)
// The algorithm is based on repetitive addition.

// put your code here

@3	//go to RAM[3]
M=0	//clear the RAM[3]

@1
D=M
@END
D;JEQ	//if RAM[1] is zero

@2
D=M
@END
D;JEQ	//if RAM[2] is zero

(LOOP)
@2	//gets 2ND NUM
D=M	//D stores 2ND NUM

@3	//go to RAM[3]
M=D+M	//RAM[3] now stores (2ND NUMBER + PREVIOUS 2ND NUMBER VALUE)

@1	//GET 1ST NUM - Program will loop RAM[1]-initial-input(times)
M=M-1	//1ST NUM-1

D=M
@LOOP	//jump to start of loop if 1st Num still has a value inside
D;JGT	//jump

(END)
@END
0;JMP	//end loop that runs forever