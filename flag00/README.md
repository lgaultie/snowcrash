Catch a glimpse of what is going on:<br/>
`pwd` <br/>
`ls -l`<br/>
`whoami`<br/>
`find / -user level00 2> /dev/null`<br/>
`find / -user flag00 2> /dev/null`<br/>

found `john` file which seems encrypted.

As the file is called John, tried tool `John the Ripper` and found `abcdefg`<br/>
Couldn't connect to flag00 but could connect to flag01, it is next level password.

Go back to the basic of cryptography: Ceasar cipher
https://www.dcode.fr/chiffre-cesar

Found `nottoohardhere`
