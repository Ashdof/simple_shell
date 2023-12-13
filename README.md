# 0x16. C - Simple Shell
In our second programming project, we were tasked to write a simple UNIX command interpreter.

## The Shell
The Shell is a command-line intepreter program that provides an interface between the user and the operating system. This program takes instructions from the keyboard and passes them to the operating system to be executed.

## Flowchart
The following image shows the high level execution flow of this shell program
<br /> <img src="chart/0_simple_shell.png" alt="shell flowchart"><br />

## Issues
At the moment, valgrind reports a memory leakage of 12 bytes despite all memory freed after execution.

## General Objectives
- Identify the designer of the original Unix operating system
- Recognised the developer for the first version of the UNIX shell
- Identify the inventor for the B programming language (the direct predecessor to the C programming language)
- Get to know Ken Thompson
- Explain how does a shell work
- Define a pid and a ppid
- Describe how to manipulate the environment of the current process
- State the difference between a function and a system call
- Explain how to create processes
- Identify the three prototypes of main
- Explain how the shell use the PATH to find the programs
- Describe how to execute another program with the execve system call
- State how to suspend the execution of a process until one of its children terminates
- Explain the meaning of EOF / “end-of-file”?

## Reference Materials
The reference resources used in this project are:
- [Approaching a Project](https://intranet.alxswe.com/concepts/350)
- [All About Team Projects and Pairings](https://intranet.alxswe.com/concepts/100037)
- [PID & PPID](https://intranet.alxswe.com/concepts/64)
- [What is a Shell?](https://linuxcommand.org/lc3_lts0010.php)
- [Unix Shell](https://en.wikipedia.org/wiki/Unix_shell)
- [Thompson](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)

# Additional Notes

**Compilation** <br />
Our program was compiled using
` gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh `

## Tasks

**0. Betty would be proud** <br />
Write a beautiful code that passes the Betty checks

**1. Simple shell 0.1** <br />
Write a UNIX command line interpreter.

- Usage: simple_shell

Your Shell should:
- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)

**2. Simple shell 0.2** <br />
Simple shell 0.1 +
- Handle command lines with arguments

**3. Simple Shell 0.3** <br />
Simple shell 0.2 +

- Handle the PATH
- fork must not be called if the command doesn’t exist

**4. Simple shell 0.4** <br />
Simple shell 0.3 +

- Implement the exit built-in, that exits the shell
- Usage: exit
- You don’t have to handle any argument to the built-in exit

**5. Simple shell 1.0** <br />
Simple shell 0.4 +

- Implement the env built-in, that prints the current environment

**6. Simple shell 0.1.1** <br />
Simple shell 0.1 +

- Write your own getline function
- Use a buffer to read many chars at once and call the least possible the read system call
- You will need to use static variables
- You are not allowed to use getline

**7. Simple shell 0.2.1** <br />
Simple shell 0.2 +

- You are not allowed to use strtok

**8. Simple shell 0.4.1** <br />
Simple shell 0.4 +

- handle arguments for the built-in exit
- Usage: exit status, where status is an integer used to exit the shell

**9. setenv, unsetenv** <br />
Simple shell 1.0 +

- Implement the setenv and unsetenv builtin commands

setenv
- Initialize a new environment variable, or modify an existing one
- Command syntax: setenv VARIABLE VALUE
- Should print something on stderr on failure
unsetenv
- Remove an environment variable
- Command syntax: unsetenv VARIABLE
- Should print something on stderr on failure

**10. cd** <br />
Simple shell 1.0 +

Implement the builtin command cd:

- Changes the current directory of the process.
- Command syntax: cd [DIRECTORY]
- If no argument is given to cd the command must be interpreted like cd $HOME
- You have to handle the command cd -
- You have to update the environment variable PWD when you change directory

man chdir, man getcwd

**11. ;** <br />
Simple shell 1.0 +

- Handle the commands separator ;

**12. && and ||** <br />
Simple shell 1.0 +

- Handle the && and || shell logical operators

**13. alias** <br />
Simple shell 1.0 +

Implement the alias builtin command
- Usage: alias [name[='value'] ...]
- alias: Prints a list of all aliases, one per line, in the form name='value'
- alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
- alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value

**14. Variables** <br />
Simple shell 1.0 +

- Handle variables replacement
- Handle the $? variable
- Handle the $$ variable

**15. Comments** <br />
Simple shell 1.0 +

- Handle comments (#)

**16. File as input** <br />
Simple shell 1.0 +

Usage: simple_shell [filename]
- Your shell can take a file as a command line argument
- The file contains all the commands that your shell should run before exiting
- The file should contain one command per line
- In this mode, the shell should not print a prompt and should not read from stdin
