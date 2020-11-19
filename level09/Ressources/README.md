`ls -l`
```
-rwsr-sr-x 1 flag09 level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09 level09   26 Mar  5  2016 token
```
`cat token`
```
f4kmm6p|=pnDBDu{
```

While trying random stuff with level09, we can see it seems to shift from 1 all the letters depending of the current index.

```
level09@SnowCrash:~$ ./level09 token
tpmhr
level09@SnowCrash:~$ ./level09 prout
psqxx
level09@SnowCrash:~$ ./level09 qqqq
qrst
level09@SnowCrash:~$ ./level09 wwwww
wxyz{
level09@SnowCrash:~$ ./level09 yyyy
yz{|
level09@SnowCrash:~$ ./level09 }}}}
}~
level09@SnowCrash:~$ ./level09 1111
1234
level09@SnowCrash:~$ ./level09 2222
2345
```

Wrote a programm to remove the shift on the result of `cat token` 

found: 

