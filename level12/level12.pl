#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

# A Perl subroutine or function is a group of statements that together performs a task. 
sub t {
  # y 
  $nn = $_[1];
  # x 
  $xx = $_[0];
# The operator =~ associates the string with the regex match and produces a 
# true value if the regex matched, or false if the regex did not match
# The tr operator in Perl translates all characters of 
# SearchList into the corresponding characters of ReplacementList.
# Syntax: tr/SearchList/ReplacementList/
# Do uppercase on x !
  $xx =~ tr/a-z/A-Z/;
# Substitution Operator or ‘s’ operator in Perl is used to substitute 
# a text of the string with some pattern specified by the user.
# Syntax: s/text/pattern
# \s Do a global search for whitespace characters in a string
# .* just means "0 or more of any character"
# remove all whitespaces !
  $xx =~ s/\s.*//;
# Variables of Array Datatype are preceded by an “at” (@) sign.
# egrep command searches for a text pattern, using extended regular expressions 
# standard error (stderr), to where programs can send their error messages.
# Standard output (stdout) can be screen or file depending on redirection
# 2>&1 redirect stderr to whatever value is set to stdout
# output (array) saves what is return on the stdout by the egrep command
# The threat must be here as all others line seems safe
# `` is for running command !
# grep " " run command inside !
# however getflag will become GETFLAG and won't work...
# ^ to find character missing in the string
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
# $_ = default variable in case no parameter is explicitly used
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }
}

n(t(param("x"), param("y")));