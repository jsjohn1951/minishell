## -> Project Minishell 42
-> Started working on the parsing aspect
<li>-> The 'readline' directory contains</li>
<li>-> all the archieve files form the readline</li>
<li>-> library</li>
<li>-> The Makefile will compile the project using</li>
<li>-> these archieve files</li>
<li>-> So far it works, and the readline() function</li>
<li>-> displays the prompt and receives user input from</li>
<li>-> stdin</li>
<br></br>
<li>-> and a simple parser that detects whether it's </li>
<li>-> received the 'clear' or 'exit' commands</li>
<li>-> 'Clear' uses the printf clear characters but</li>
<li>-> we may want to replace that later with the</li>
<li>-> clear function in the $PATH directories.</li>
<li>-> 'exit' only takes one argument, but does</li>
<li>-> not handle errors</li>
<br></br>

## Version edits

<li>-> custom split works with input from the user including: :</li>
<li>-> -> '$> "hello" "world" aa'bob'yy is here' as input.</li>
<li>-> Work needs to be done for redirection and pipes to be handled properly.</li>

## -> ADDED :: Version 1.6
<li>-> -> added an echo functionality that will echo to the terminal</li>
<li>-> ADDED ;;</li>

## -> ADDED :: Version 1.7
<li>-> -> added 3 matrices with struct 'data' to store env, path, and</li>
<li>-> ->	commands.</li>
<li>-> -> commands are handled within the cmd_control which calls</li>
<li>-> -> 	related bus functions.</li>
<li>-> -> path matrix gets updated and freed with each iteration of the main</li>
<li>-> ->	loop in order to remain identical to the PATH element within the env.</li>
<li>-> ->	That is to say that once the env PATH gets changed by the user</li>
<li>-> ->	it's automatically updated with the next iteration.</li>
<li>-> ADDED ;;</li>
