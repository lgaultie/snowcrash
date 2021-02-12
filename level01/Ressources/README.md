# Level01

```bash
level01@SnowCrash:/$ cat /etc/passwd
[...]
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
[...]
```
Flag01 password is in clear but can be encrypted same ways as level00.

Let's install `john the ripper` on a personal computer, then use it on the password.
```bash
bash-3.2$ echo '42hDRfypTqqnw' > etc_passwd
bash-3.2$ john etc_passwd
Loaded 1 password hash (descrypt, traditional crypt(3) [DES 128/128 SSE2])
Press 'q' or Ctrl-C to abort, almost any other key for status
abcdefg          (?)
1g 0:00:00:00 100% 2/3 100.0g/s 76800p/s 76800c/s 76800C/s raquel..bigman
Use the "--show" option to display all of the cracked passwords reliably
Session completed
```
We found abcdefg

```bash
level01@SnowCrash:/$ su flag01
Password: abcdefg
Don't forget to launch getflag !
flag01@SnowCrash:~$ getflag
Check flag.Here is your token : XXXXXXXXXXXXXXXXXXX
```
