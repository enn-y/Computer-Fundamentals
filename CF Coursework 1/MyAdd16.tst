load MyAdd16.hdl,
output-file MyAdd16.out,
compare-to MyAdd16.cmp,
output-list a%B1.16.1 b%B1.16.1 out%B1.16.1;

set a %B1000000000000000,
set b %B0000000000000001,
eval,
output;

set a %B1100000000000000,
set b %B0000000000000011,
eval,
output;

set a %B1110000000000000,
set b %B0000000000000111,
eval,
output;

set a %B1111000000000000,
set b %B0000000000001111,
eval,
output;

set a %B1111100000000000,
set b %B0000000000011111,
eval,
output;

set a %B1111110000000000,
set b %B0000000000111111,
eval,
output;

set a %B1111111000000000,
set b %B0000000001111111,
eval,
output;

set a %B1111111100000000,
set b %B0000000011111111,
eval,
output;

set a %B1111111110000000,
set b %B0000000111111111,
eval,
output;

set a %B1111111111000000,
set b %B0000001111111111,
eval,
output;

set a %B1111111111100000,
set b %B0000011111111111,
eval,
output;

set a %B1111111111110000,
set b %B0000111111111111,
eval,
output;

set a %B1111111111111000,
set b %B0001111111111111,
eval,
output;

set a %B1111111111111100,
set b %B0011111111111111,
eval,
output;

set a %B1111111111111110,
set b %B0111111111111111,
eval,
output;