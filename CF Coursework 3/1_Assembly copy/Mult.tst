// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/mult/Mult.tst

load Mult.asm,
output-file Mult.out,
compare-to Mult.cmp,
output-list RAM[3]%D2.6.2;

set RAM[1] 0,
set RAM[2] 0;
repeat 20 {
  ticktock;
}
output;

set PC 0,
set RAM[1] 1,
set RAM[2] 0;
repeat 50 {
  ticktock;
}
output;

set PC 0,
set RAM[1] 0,
set RAM[2] 2;
repeat 80 {
  ticktock;
}
output;

set PC 0,
set RAM[1] 3,
set RAM[2] 1;
repeat 120 {
  ticktock;
}
output;

set PC 0,
set RAM[1] 2,
set RAM[2] 4;
repeat 150 {
  ticktock;
}
output;

set PC 0,
set RAM[1] 6,
set RAM[2] 7;
repeat 210 {
  ticktock;
}
output;
