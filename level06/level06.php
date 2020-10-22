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
