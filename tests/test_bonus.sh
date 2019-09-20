#! /bin/bash

exec 3>./minififo

echo "Launching minishell..."
echo "./minishell" >&3

read -p "Press enter to continue"

echo "BONUS"

read -p "Press enter to continue"

echo "$> cat Ctrl-C" >&3
echo "kdfjhj Ctrl-C" >&3

read -p "Press enter to continue"

echo "The Minishell must kill cat's process and give back the prompt."
echo "PATH rights"
echo "mkdir /tmp/bin"
mkdir /tmp/bin
export PATH="$PATH:/tmp/bin"
echo "export PATH=\"$PATH:/tmp/bin\""
touch /tmp/bin/test_exec_rights.c && echo "
#include <stdio.h>
int main()
{
	printf(\"KO\\n\");
	return (0);
}" >/tmp/bin/test_exec_rights.c

echo "gcc -o /tmp/bin/test_exec_rights /tmp/bin/test_exec_rights.c"
gcc -o /tmp/bin/test_exec_rights /tmp/bin/test_exec_rights.c
echo "chmod 644 /tmp/bin/test_exec_rights"
chmod 644 /tmp/bin/test_exec_rights
From another folder, run the following
command "$> test_exec_rights".
echo "Check that the minishell refuses to run the program because of the missing execution rights."
echo "Auto-completion"
echo "$> ec"
echo "then press tabulation. The minishell must complete the command into $> echo"
echo  "$> ema"
echo "The minishell must complete the command into $> emacs"
echo "Semi colon"
echo "$> echo TOP \; ls \; echo MIDDLE \; ls \; echo BOTTOM"
TOP ; ls ; echo MIDDLE ; ls ; echo BOTTOM"
echo "The 5 commands must be executed without any errors in the order they were written."
echo "$> \;"
echo "The minishell must either run nothing and give the prompt back or display a syntax error and give the prompt back."
