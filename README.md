# tinyshell

**Authors: Aryaman Dubey, Swapnil Joshi**

A very basic Unix like shell made as part of a project for the course COMP2123 @ the University of Hong Kong.


## Usage: ##

**history** - Displays an ordered list of all input commands that tinyshell received in a session. In
this project, by default, the history command displays the 5 most recent commands (latest command shows first; if less than 5 commands have been executed, it displays them all).
The -sbu flag (Sort by Usage) sorts the history commands by execution duration (end time – start time) in descending order. 

**exit** - Exits from tinyshell. Basically, calls the exit(0) function.

**The input formats for the built-in commands are:**
[optionalSpace]exit[optionalSpace]
[optionalSpace]history[optionalSpace]
[optionalSpace]history[oneOrMoreSpace][-sbu][oneOrMoreSpace]

**Executing non-built-in commands:** 
Non built-in commands can also be executed. Tinyshell calls the system(const char* command) function from stdlib.h to do this.
