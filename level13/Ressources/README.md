# Level13

## Research

```bash
level13@SnowCrash:~$ ls -l
total 8
-rwsr-sr-x 1 flag13 level13 7303 Aug 30  2015 level13
level13@SnowCrash:~$ ./level13
UID 2013 started us but we we expect 4242
level13@SnowCrash:~$ cat /etc/group | grep '2013'
level13:x:2013:
```
The program expect a user who has a particular uid. How to change our user uid without being root?
Let's try with a debugger:

```bash
level13@SnowCrash:~$ gdb ./level13
[...]
(gdb) disas main
Dump of assembler code for function main:
   0x0804858c <+0>:	push   %ebp
   0x0804858d <+1>:	mov    %esp,%ebp
   0x0804858f <+3>:	and    $0xfffffff0,%esp
   0x08048592 <+6>:	sub    $0x10,%esp
   0x08048595 <+9>:	call   0x8048380 <getuid@plt>
   0x0804859a <+14>:	cmp    $0x1092,%eax
   0x0804859f <+19>:	je     0x80485cb <main+63>
   0x080485a1 <+21>:	call   0x8048380 <getuid@plt>
[...]
```
The programm does a `getuid` (verified with `strings` command) and then compare the received uid to `%eax`.

Maybe we can change the value of `%eax`. 

## Solution

Let's place a breakpoint at `0x0804859a` to stop the program just before the comparison.
```bash
(gdb) b *0x0804859a
Breakpoint 1 at 0x804859a
(gdb) run
Starting program: /home/user/level13/level13

Breakpoint 1, 0x0804859a in main ()
(gdb) info registers
eax            0x7dd	2013
```
We can see that `%eax` is equal to our user uid. Let's change it with `set` and do `next`:

```bash
(gdb) set $eax = 4242
(gdb) n
Single stepping until exit from function main,
which has no line number information.
your token is XXXXXXXXXXXXXXXXXXXXXXXX
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
```
 
