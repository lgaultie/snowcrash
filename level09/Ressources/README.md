# Level09

## Research

```bash
level09@SnowCrash:~$ ls -l
total 12
-rwsr-sr-x 1 flag09 level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09 level09   26 Mar  5  2016 token
level09@SnowCrash:~$ cat token
f4kmm6p|=�p�n��DB�Du{��
```
The token seems to have a some unprintable characters.

```bash
level09@SnowCrash:~$ ./level09
You need to provied only one arg.
level09@SnowCrash:~$ ./level09 hi
hj
```

While trying random stuff with `level09`, we can see it seems to shift from 1 all the letters depending of the current index.

```
level09@SnowCrash:~$ ./level09 token
tpmhr
level09@SnowCrash:~$ ./level09 prout
psqxx
level09@SnowCrash:~$ ./level09 1111
1234
level09@SnowCrash:~$ ./level09 2222
2345
level09@SnowCrash:~$ ./level09 qqqq
qrst
level09@SnowCrash:~$ ./level09 wwwww
wxyz{
level09@SnowCrash:~$ ./level09 yyyy
yz{|
level09@SnowCrash:~$ ./level09 }}}}
}~

```
## Solution

Wrote a programm to remove the shift on the result of `cat token`

```c
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int i;

    if (argc != 2)
    {
        return -1;
    }
    i = 0;
    while (argv[1][i] != '\0')
    {
        printf("%c", (argv[1][i] - i));
        i++;
    }
    printf("\n");
    return 0;
}
```

```bash
➜  ex09 scp -P 4242 level09@[SnowCrash_VM_IP_address]:~/token .
➜  ex09 gcc decrypt.c
➜  ex09 ./a.out $(cat token)
cat: token: Permission denied
➜  ex09 chmod 777 token
➜  ex09 ./a.out $(cat token)
f3iji1ju5yuevaus41q1afiuq
```
We can now connect to `flag09` on the VM:
```bash
level09@SnowCrash:~$ su flag09
Password:
Don't forget to launch getflag !
```
