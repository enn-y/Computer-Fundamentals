
// ================================= Factorial ==================================
// This program calculates the Factorial F of a given number n 
// 	At run time:
//		- The user should enter the value of n into R0. i.e. RAM[0]
//		- The program then calculate the factorial of n    i.e. F(n)=n!
//			 F(n) = n*(n-1)*(n-2)*......*2*1
//		- The result F(n) should be saved in RAM[1]
//			-- You should also consider the F(0) case.
// ==============================================================================


// put your code here

@1
M=1     //answers of factorial is always 1 or bigger than 1, in this case 1 is used for 0!=1 and 1!=1 

@0
D=M
@END 
D;JLE   //if RAM[0] input <=0, skips the following loops and jumps to the end of the program

@0
D=M     
@1
M=D     //sets RAM[1] = value inside RAM[0] (n)

(START)
    
    @1
    D=M
    @3
    M=D //sets RAM[3] = value inside RAM[1]
    
    @0
    D=M-1
    @2
    M=D //sets RAM[2] = input - 1 (n-1)
    @END
    D;JEQ   //if n-1 = 0, jumps to end

(FACTOR)
    @2
    D=M-1   
    @OUT
    D;JEQ   //if RAM[2]-1 = 0, jumps out of this loop

    @3
    D=M     

    @1
    M=M+D   //RAM[1] = RAM[1]+RAM[3]

    @2
    M=M-1   //RAM[2] = RAM[2] - 1
    @FACTOR
    0;JMP   //jumps to start of FACTOR loop

(OUT)
@0
M=M-1   //RAM[0] = RAM[0] - 1 (n=n-1)
@START
D;JGE   //jumps to START if RAM[2]-1 >=0

(END)
    @END
    0;JMP