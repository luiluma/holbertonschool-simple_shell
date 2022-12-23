<html>
<body>

<img src="https://i.ibb.co/xX4LNXR/Captura.png" width=1012 height=auto/>
                                                
<h1>holbertonschool-simple_shell</h1>

<hr>

<h2>Flowchart:</h2>

<img src="https://app.code2flow.com/yyTaVb.png" width=1012 height=auto/>

<h2>Description:</h2>

<p>simple shell is our attempt to recreate a basic shell to communicate with the operating system. We are using the C programing language to write all our sourcecode.</p>

<img src="https://k62.kn3.net/taringa/4/F/6/5/2/8/AgustinLajeFan/550x556_142.jpg" width="300" height="300"/>

<h2>Output</h2>

<p>Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.</p>
<p>The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)</p>
  
<h2>Process to run</h2>

The next steps are a brief description about how the shell works:

1. First, the parent process is created when the user run the program.
2. Then, the *isatty()* function using *STDIN_FILENO* file descriptor -fd- to tests if there is an open file descriptor referring to a terminal. If *isatty()* returns 1, the prompt is showed using *write()* with *STDOUT_FILENO* as fd and waits for an input user command line.
3. When the user types a command, *getline()* function reads an entire line from the stream and *strtok()* function breaks the inputted command into a sequence of non-empty tokens.
4. Next, it creates a separate child process suing *fork()* that performs the inputted command. Unless otherwise is specified, the parent process waits for the child to exit before continuing.
5. After tokening the command, *execve()* function brings and executes it, the it frees all allocated memory with *free()*.
6. Finally, the program returns to main process: prints the prompt, and waits for another user input.

<h2>Functions files of the program</h2>

<p>Main: It contains the input function arguments and also has the output functions in each of the cases.</p>

<p>Shell.h: Its the header file</p>

<p>Auxiliar functions: It contains all the auxiliary functions that allow the program to be run.</p>
  
<p>Tokenizer and Make child: It contains all functions them allowing tokenization of shell input arguments.</p>
 
<p>Execution: Find and execute the command requested at the prompt.</p>

<hr>
<h3>AUTHORS</h3>

<p>Juan Esteban Enriquez</p> <img src="https://www.pofilo.fr/img/SPOF-github/github1600.png" width="100" height="100"/>
<hr>
<p>Luisa Maria Lopez</p> <img src="https://www.pofilo.fr/img/SPOF-github/github1600.png" width="100" height="100"/>
