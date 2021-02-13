# Level01

```bash
level01@SnowCrash:/$ cat /etc/passwd
[...]
flag00:x:3000:3000::/home/flag/flag00:/bin/bash
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
flag02:x:3002:3002::/home/flag/flag02:/bin/bash
[...]
```

` x  --> Holding place for the user’s “encrypted password.” Traditionally, this field actually stored the user’s encrypted password. Modern Unix systems store encrypted passwords in a separate file (the shadow password file) that can be accessed only by privileged users.`
https://www.oreilly.com/library/view/practical-unix-and/0596003234/ch04s03.html

Flag01 password is in clear but is encrypted same ways as level00. However Caesar cipher doesn't seem to find anything.

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
