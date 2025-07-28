# how to solve

First you comple your program 'gcc -g crackme.c -o crackme'.
Then you run it using GDB 'gdb ./crackme'.

IN GDB
'b main' To set up a breakpoint.
'r'  To run the program
'disas main' To disassembly main func.

TODO:
you have to get to <__isoc23_scanf@plt> using ni(next instructions).
<__isoc23_scanf@plt> is an input in C using scanf!
Then 'enter password: ' line will appear. Write wrong password and press enter.
use 'disas main' if your lost.
Go to (test %eax, %eax) // this is the 'if (strcmp(password_buffer, correct_password) == 0)' part.

Then we have to get feedback by using 'ni':

Go to '0x00000000004004ed <+87>:	jne    0x4004fb <main+101>' 0x00000000004004ed <- it's going to be differnt all the time.

'jne' is (jump if not equal) it usises ZF(zero flags) if it returns 0 password is correct if return is less or greater then 0 password is incorrect.


Then u should see: (0x00000000004004ef <+89>:	mov    $0x401270, %edi) <- output: 'correct password'.
(0x00000000004004fb <+101>:	mov    $0x401290, %edi) <- output: 'incorrect password'.

we need here:
0x00000000004004ef = 0x4004ef the 'correct password' output.
how to check it 'x/s 0x401270'.

After that you run your program again: 'r'.
Get back to (0x00000000004004eb <+85>:	test   %eax,%eax)

then you write 'set $rip 0x4004ef' it will tell the CPU even your passwords don't match, ignore that and jump to the part what will output a confirm.

so nothing hard.
