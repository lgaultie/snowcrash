Catch a glimpse of what is going on:<br/>
`pwd` <br/>
/home/user/level00<br/>
`ls -l`<br/>
total 0 <br/>
`whoami`<br/>
level00 <br/>
`find / -user level00 2> /dev/null`<br/>
Lots of files, no weird ones<br/>
`find / -user flag00 2> /dev/null`<br/>
Found lot of files, with 2 weird ones: `/usr/sbin/john` and `/rofs/usr/sbin/john`<br/>
<br/>
`/usr/sbin/john` file seems encrypted.

As the file is called John, tried tool `John the Ripper` and found `abcdefg`<br/>
Couldn't connect to flag00 but could connect to flag01, it is next level password!

Go back to the basic of cryptography: Ceasar cipher
https://www.dcode.fr/chiffre-cesar

Found `nottoohardhere`
