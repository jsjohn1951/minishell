## minishell
<li>\\\\\\\\\\\\\\\\\\ </li>
<li>\\\ |||||||||||| \ </li>
<li>\\\\\\\ ||| \\\\\\ </li>
<li>\\\\\\\ ||| \\\\\\ </li>
<li>\\\\\\\ ||| \\\\\\ </li>
<li>\ ||| \ ||| \\\\\\ </li>
<li>\\\\ |||| \ ||| \\ </li>
<li>\\\\\\\\\\\\\\\\\\ </li>

### -> Project Minishell 42
-> Started working on the parsing aspect
-> 
-> The 'readline' directory contains
-> all the archieve files form the readline
-> library
-> The Makefile will compile the project using
-> these archieve files
-> So far it works, and the readline() function
-> displays the prompt and receives user input from
-> stdin
->
-> and a simple parser that detects whether it's 
-> received the 'clear' or 'exit' commands
-> 'Clear' uses the printf clear characters but
-> we may want to replace that later with the
-> clear function in the $PATH directories.
-> 'exit' only takes one argument, but does
-> not handle errors
->
<li>  _________________ </li>
<li> /*  Version 1.5 */ </li>
<li>/* list changes */  </li>
<li>-----------------   </li>

-> custom split works with simple input including :
-> <$ SEASHELL-S $> "hello" "world" aa'bob'yy is here
->
##-> FIXED :: Version 1.6
-> -> custom split fails with complex inputs, e.g.:
-> -> <$ SEASHELL-s $> ''a ''''b'' c'' y''
-> FIXED ;;
##-> ADDED :: Version 1.6
-> -> added an echo functionality that will echo to the terminal
-> ADDED ;;
##-> ADDED :: Version 1.7
-> -> added 3 matrices with struct 'data' to store env, path, and
-> ->	commands.
-> -> commands are handled within the cmd_control function by
-> -> 	bus functions.
-> -> path matrix gets updated with each iteration of the main
-> ->	loop.
-> ADDED ;;
