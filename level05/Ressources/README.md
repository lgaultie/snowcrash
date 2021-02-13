# Level05

## Research 

```bash
level05@SnowCrash:~$ ls
```
returns nothing.

```bash
level05@SnowCrash:~$ find / -user flag05 2>/dev/null
/usr/sbin/openarenaserver
/rofs/usr/sbin/openarenaserver
```
```bash
level05@SnowCrash:~$ cd /usr/sbin && ls -l openarenaserver
-rwxr-x---+ 1 flag05 flag05 94 Mar  5  2016 openarenaserver
```

The file has ACLs extended permissions. We can do `getfacl openarenaserver` to see them.</br>

```bash
level05@SnowCrash:/usr/sbin$ cat openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```
For each file in `/opt/openarenaserver/` it will execute it then supress it.

`Invoking a Bash shell with the -x option causes each shell command to be printed before it is executed.` </br>
https://docs.actian.com/vector/4.2/index.html#page/SysAdmin/Bash_Shell_-x_Option.htm
`ulimit: user limits - limit the use of system-wide resources. -t The maximum amount of cpu time in seconds.`

```bash
level05@SnowCrash:/usr/sbin$ ./openarenaserver
bash: ./openarenaserver: Permission denied
```
We don't have rights to execute `openarenaserver`.
However the files I created to test stuff in `/opt/openarenaserver/` disappeared after a while, maybe `openarenaserver` is **launched by a cronjob** or something.

```bash
level05@SnowCrash:~$ echo "getflag" > /opt/openarenaserver/getflag
```
And waiting a bit of time for the program to be launch didn't do anything. Maybe redirect the output somewhere can work.

## Solution

```bash
level05@SnowCrash:~$ echo "getflag > /tmp/flag" > /opt/openarenaserver/getflag
```
Wait a bit...
```bash
level05@SnowCrash:~$ cat /tmp/flag
```
Give us the flag
