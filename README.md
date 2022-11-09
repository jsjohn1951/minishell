# Minishell
## About
	Appreciate the madness of Minihell.

	This project may seem simple at first glace, however, it took a good portion of a 4 month
	period to perfect and complete, and indroduced my teammate and I to many new concepts
	that we will continue to practice throughout our coding careers.
	
	For example:
		Multi-processing using the fork() function in C, and piping the output of one child
		process to the next using pipe() and dup() / dup2(). 

	One of the most prevelent and important subjects that this project taught me was how
	shell script is parsed, and expansions are applied, seeing as in the 42 cursus we
	incorporate the use of shells every day it is critical that we as students understand
	how shells are used as primary means of communication between the user and the machine.

	It is important to note that not all shells are created equal, and neither are the
	Minishells produced by 42 students. No shell will ever perfect.

---
## Project specifications
1. Must display a prompt.

		SEA SHELL ➜
   
2. The history must be working.
   
3. Must be able to search and launch the correct executables
	according to the PATH variable included in the envp.

4. More than one global variable is forbidden.
   
5. No need to interpret special characters like '\\', ';' or 
	handle unclosed quotes.

6. Must handle single quotes as a shell does ( prevents expansions ),
	and prevents interpreting of metacharacters.

7. Must handle double quotes which prevents interpreting of 
	metacharacters, however, expansions ('$') are not prevented.

		E.g: echo "hello$USER:" should output helloUserName: whereas
			echo 'hello$USER:' should output hello$USER: without expanding.

8. Must implement redirections ( > , < , >> , <<)
		
	Types of redirection:

		> , >> : stdout redirections - creates files, and redirects outputs
			to those files. '>' overwrites pre-existing content, whereas '>>'
			appends new content to existing content.

		< , << : stdin redirections - < redirects input from a file to a child
			process. << (Heredoc) redirects input from the stdin on the terminal
			to a child process, it may also display a prompt whilst waiting for
			input. << (Heredoc) will stop once it receives a signal, or the
			deliminator is entered. The syntax for Heredoc is always
							'nameOfProcess << deliminator.'
	[More info on heredoc](https://linuxize.com/post/bash-heredoc/)

		When you encounter a sequence of the same redirection type
			only the last redirection in the sequence is used. The same
			applies to the Heredoc ( << ) redirection.

			E.g: cat < test1 < test2 < test3 - only test3 will be piped to cat,
				similarly cat > test1 < test2 > test3 < test4 - test4 will be
				piped into cat and the output will be piped to test3.
			
			Mixed E.g: cat < test1 > test2 << bob >> test3 - Only the << (Heredoc) with bob 
				as the deliminator will be taken as input, and the output will be appended 
				into test3.
			
			Hint: Even though only the last redirection of a particular redir. type is used
				the shell will still ensure that each file exists, or in the case of stdout 
				redir. it will go and create each file, but only output to the last one.
9. Must implement pipes ( | ):
		
		The output of each child process in the pipeline should be piped to the next 
			child process in the pipeline.
			
			E.g: echo hello world | cat | grep -o hello | cat -e
				The output of echo is piped to cat, then cat's output is piped to the grep
				command, and so forth until the end. The last command will then
				display the output on the regular STDOUT or file descriptor 1.

			Pipes and redirections can be mixed as well inorder to redirect stdin or 
			stdout within a pipeline.

			E.g: cat < test.txt | cat -e > test2.txt | echo hi | cat -e

10. Handle '$' which will cause it and the consecutive characters to expand.
	
		If a '$' is found within a string of characters the shell takes the characters to
			the right up until the first non apha / numerical character as the name of an 
			evironmental variable. It will expand the variable to it's value in the 
			envp.
		
			E.g: echo $PWD will output the current directory:
				/Users/username/Desktop/minishell
				similarly echo $USER will expand to the username in the envp.

			Sometimes even mixed:

				E.g: echo Hello$PWD: 
				this will output Hello/Users/username/Desktop/minishell:

			All of this was easily achieved using my ft_strncmp(), modified ft_strjoin(), 
				and ft_substr() included in libft.

			In order to see the list of environmental variables, take in envp as 3rd 
				argument for your main() function. 

					This little program will display the envp from the previous shell:

					#include <stdio.h>

					int main(int argc, char **argv, char **envp)
					{
						int	i;

						i = -1;
						while (envp[++i])
							printf("%s\n", envp[i]);
						(void) argc;
						(void) argv;
						return (0);
					}

					Alternatively if you're lazy like me, just type env in the
						terminal ;)

11. One non-env expansion: '$?,' which expands to the exit status of the last child-process to
	be executed.

12. Crtl-c (SIGINT), crtl-d (eof), and crtl-\ (SIGQUIT).
	
		Type man signal into the terminal to findout more about SIGINT and SIGQUIT.
		Crtl-d is simply an EndOfFile input. The behaviour of these signals should be like
		in bash. They work normally on the child-processes, however, SIGINT simply displays 
		a new prompt and SIGQUIT does nothing. It is worth noting that SIGINT changes the 
		last exit status.

13. It is required by the subject that we implement several built-ins (thank goodness it's not all of bash's builtins).

        1.  echo - with the option to enter -n as a flag.
        2.  cd - with only absolute or relative path
        3.  pwd
        4.  export
        5.  unset
        6.  env - without any arguments or options
        7.  and - exit without options

---

## Conclusion
	Building a shell is not an easy task, and the more features you want to implement, the longer it takes to complete. For any 42 student busy with this project, there are plenty of resources online, but the most important resource will always be your peers.

	And for those who are just curious about this project, you are free to clone and enjoy my personal mini - version of bash :) just type 'make' and execute './minishell' inside a unix / linux environment. For windows users, you might have to install a virtual machine / docker, or use WSL.

	Thank you for the read and I hope this was informative.