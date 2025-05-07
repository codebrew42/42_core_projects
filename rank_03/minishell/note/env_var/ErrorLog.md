# error
bash's behavior
```
jiepark@c4b5c1:~$ $bash && echo $?
0
jiepark@c4b5c1:~$ $USER && echo $?
jiepark: command not found
jiepark@c4b5c1:~$ echo $USER && echo $?
jiepark
0
jiepark@c4b5c1:~$ echo $USERNN && echo $?

0
jiepark@c4b5c1:~$ $USER
jiepark: command not found
jiepark@c4b5c1:~$ $NON
jiepark@c4b5c1:~$ 

```

minishell's behavior
jiepark@c4b5c1:~/sgoinfre/minishell/42_Minishell/minishell$ ./minishell
minishell> echo $USER && echo $?
jiepark
$?
minishell> $USER
minishell: jiepark: Command not found
minishell> $NON
Segmentation fault (core dumped)
jiepark@c4b5c1:~/sgoinfre/minishell/42_Minishell/minishell$ ./minishell
minishell> echo $NON && echo $?

$?
minishell> echo $USER && echo $?
jiepark
$?


## case 1
- most crucial : seg fault on $NON


## case 2
- crucial : not expanding after &&

Bash Behavior
Here's how bash handles these scenarios:
Execute the command stored in the 'bash' variable (likely '/bin/bash')
jiepark@c4b5c1:~$ $bash && echo $?
Exits the sub-bash, the main bash prints the exit code 0
0
Try to execute the value of USER ('jiepark') as a command
jiepark@c4b5c1:~$ $USER && echo $?
'jiepark' is not a command
jiepark: command not found
$? is not printed because the first command failed
Echo the value of USER, then echo the exit status (0 for success)
jiepark@c4b5c1:~$ echo $USER && echo $?
jiepark
0
Echo the value of USERNN (unset), which is empty, then echo exit status (0)
jiepark@c4b5c1:~$ echo $USERNN && echo $?
(empty line)
0
Try to execute the value of USER ('jiepark') as a command
jiepark@c4b5c1:~$ $USER
jiepark: command not found
Try to execute the value of NON (unset), which expands to nothing.
Bash treats this as an empty command, which does nothing and returns success (implicitly).
jiepark@c4b5c1:~$ $NON
jiepark@c4b5c1:~$
Key Bash Observations:
If an environment variable's value corresponds to a valid command path ($bash), it executes that command.
If an environment variable's value is not a command ($USER), bash reports "command not found".
If an environment variable is unset ($NON), trying to execute it results in an empty command, which does nothing and succeeds.
echo $? correctly prints the exit status of the immediately preceding command.
&& only executes the second command if the first one succeeds.
Minishell Behavior
Here's how minishell currently handles similar scenarios:
Minishell execution examples
jiepark@c4b5c1:~/sgoinfre/minishell/42_Minishell/minishell$ ./minishell
Echo USER, then attempt to echo exit status
minishell> echo $USER && echo $?
jiepark
$? # Issue: Prints '$?' literally instead of the exit code 0
Try to execute the value of USER ('jiepark') as a command
minishell> $USER
minishell: jiepark: Command not found # Correctly identifies 'jiepark' is not a command
Try to execute the value of NON (unset)
minishell> $NON
Segmentation fault (core dumped) # Issue: Crashes instead of handling the empty command
--- Another session ---
jiepark@c4b5c1:~/sgoinfre/minishell/42_Minishell/minishell$ ./minishell
Echo NON (empty), then attempt to echo exit status
minishell> echo $NON && echo $?
(empty line)
$? # Issue: Prints '$?' literally instead of the exit code 0
Echo USER, then attempt to echo exit status
minishell> echo $USER && echo $?
jiepark
$? # Issue: Prints '$?' literally instead of the exit code 0
Piping Behavior in Minishell
Pipe output of echo '$USER' (literal) to another echo '$USER' (literal)
The second echo ignores stdin and prints its own argument.
minishell> echo '$USER' | echo '$USER'
$USER
Pipe output of echo "$USER" (expanded) to another echo "$USER" (expanded)
The second echo ignores stdin and prints its own argument.
minishell> echo "$USER" | echo "$USER"
jiepark
Pipe output of echo $USER (expanded) to another echo $USER (expanded)
The second echo ignores stdin and prints its own argument.
minishell> echo $USER | echo $USER
jiepark
Key Minishell Observations & Issues:
Issue 1 (Segfault): Executing an unset variable ($NON) causes a segmentation fault. Bash handles this gracefully as an empty command.
Issue 2 (Incorrect $? Expansion): $? is not expanded to the exit status when used after &&. It's treated as a literal string. This seems to be a general expansion issue with $? in this context.
Correct Behavior: Minishell correctly identifies when a variable's value is not a command ($USER).
Piping: Variable expansion within single quotes, double quotes, and without quotes seems to work as expected before the pipe. The behavior of echo ignoring standard input when given arguments is standard. Correction based on user examples: The provided examples show the second echo printing its argument, which is standard behavior. The initial interpretation was incorrect.


