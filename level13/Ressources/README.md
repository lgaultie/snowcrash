strings shows us that he programm uses getuid, and expect a user uid of a particular number.

./level13 confirms it.

gdb ./level13

disas main </br>
We can see that the programm does a getuid and then compare the received uid to %eax

Maybe we can change the value of eax

We have to place a breakpoint at 0x0804859a

Run and next until the breakpoint

info registers can show us that eax = 2013

 let's set the value to change it
 set $eax = 4242
 
 let's do next
 
 we have the token
 
 
