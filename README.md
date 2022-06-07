\\\\\\\\\\\\\\\\\\
\\\ |||||||||||| \
\\\\\\\ ||| \\\\\\
\\\\\\\ ||| \\\\\\
\\\\\\\ ||| \\\\\\
\ ||| \ ||| \\\\\\
\\\\ |||| \ ||| \\
\\\\\\\\\\\\\\\\\\
\ Your friendly  \
\ neighborhood   \
\ Parser dev. :) \
\\\\\\\\\\\\\\\\\\

-> Project Minishell 42
-> Started working on the parsing aspect
-> 
-> The 'readline' directory contains
-> all the archieve files form the readline
-> library
-> The Makefile will compile the project using
-> these archieve files
-> /* working on including their headers instead
-> of using the system installed library */
-> So far it works, and the readline() function
-> displays the prompt and receives user input from
-> stdin
->
-> So far I've incorporated a simple split function
-> and a simple parser that detects whether it's 
-> received the 'clear' or 'exit' commands
-> 'Clear' uses the printf clear characters but
-> we may want to replace that later with the
-> clear function in the $PATH directories.
-> 'exit' only takes one argument, but does
-> not handle errors