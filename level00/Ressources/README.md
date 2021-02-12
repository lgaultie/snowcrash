# Level00

- Catch a glimpse of what is going on:<br/>
```bash
level00@SnowCrash:~$ pwd 
/home/user/level00
level00@SnowCrash:~$ ls -l
total 0 
level00@SnowCrash:~$ whoami
level00
level00@SnowCrash:~$ find / -user level00 2> /dev/null
```

Finds lots of files, but it seems there are no weird ones.<br/>
```bash
find / -user flag00 2> /dev/null
```
Found lot of files, with 2 weird ones: 
```bash
/usr/sbin/john
/rofs/usr/sbin/john
```

- The `/usr/sbin/john` file seems encrypted. Let's decrypt it.

As the file is called John, tried tool `John the Ripper` and found `abcdefg`<br/>
Couldn't connect to flag00 but could connect to flag01, it is next level password!

Go back to the basic of cryptography: used Ceasar cipher
https://www.dcode.fr/chiffre-cesar

Found `nottoohardhere`

- change user to flag00 then level01
```bash
level00@SnowCrash:~$ su flag00
Password: nottoohardhere
```
```bash
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : xxxxxxxxxxxxxxxxxxxxxxx
```

- Connect to level01 with this token.
