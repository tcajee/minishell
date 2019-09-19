#! /bin/bash


exec 3>./minififo

echo "Launching minishell..."
echo "./minishell" >&3


read -p "Press enter to continue"

echo "foo" >&3
echo "It must fail with a proper error message and then give back the prompt."

read -p "Press enter to continue"
echo "Testing complete..."
echo "exit" >&3
#echo "$> /bin/ls"
#echo  "/bin/ls" | pbcopy
#echo "ls must be properly executed and then give back the prompt."
#read -p "Press enter to continue"

#echo "$> /bin/ls -laF"
#echo "/bin/ls -laF" | pbcopy
#echo "ls must be properly executed with the -l, -a, -F flags and then give back the prompt."
#read -p "Press enter to continue"

#echo "$> /bin/ls -l -a -F"
#echo "/bin/ls -l -a -F" | pbcopy
#echo "ls must be properly executed with the -l, -a, -F flags and then give back the prompt."
#read -p "Press enter to continue"

#echo "BUILTINS"
#read -p "Press enter to continue"

#echo "$> exit"
#echo "exit" | pbcopy
#echo "The program must terminate proprely and give back the parent's shell. Run the minishell again."
#read -p "Press enter to continue"

#echo "$> echo \"It works\""
#echo "echo \"It works\"" | pbcopy
#echo "The message must be properly displayed."
#read -p "Press enter to continue"

#echo "$> echo It works (without the double quotes)."
#echo "echo It works" | pbcopy
#echo "The message must be properly displayed."
#read -p "Press enter to continue"

#echo "$> cd /goinfre/$USER/Desktop"
#echo "cd /goinfre/$USER/Desktop" | pbcopy
#read -p "Press enter to continue"
#echo "$> /bin/pwd"
#echo "/bin/pwd" | pbcopy
#echo "must confirm that the current folder was updated."
#read -p "Press enter to continue"

#echo "$> cd ../../"
#echo "cd ../../" | pbcopy
#read -p "Press enter to continue"
#echo "$> /bin/pwd"
#echo "/bin/pwd" | pbcopy
#echo "must confirm that the current folder was updated."
#read -p "Press enter to continue"

#echo "$> cd"
#echo "cd" | pbcopy
#read -p "Press enter to continue"
#echo "$> /bin/pwd"
#echo "/bin/pwd" | pbcopy
#echo "/bin/pwd must confirm that the current folder is the user's home folder."
#read -p "Press enter to continue"

#echo "$> cd -"
#echo "cd -" | pbcopy
#read -p "Press enter to continue"
#echo "$> /bin/pwd"
#echo "/bin/pwd" | pbcopy
#echo "/bin/pwd must confirm that the current folder is the folder relative/path/of/your/choice used before."
#read -p "Press enter to continue"

#echo "$> cd ~/Desktop"
#echo "cd ~/Desktop" | pbcopy
#read -p "Press enter to continue"
#echo "$> /bin/pwd"
#echo "/bin/pwd" | pbcopy
#echo "/bin/pwd must confirm that the current folder was updated."
#read -p "Press enter to continue"

#echo "ENVS"
#read -p "Press enter to continue"

#echo "$> env"
#echo "env" | pbcopy
#echo "must be displayed as key=value."
#read -p "Press enter to continue"

#echo "$> setenv FOO bar [or] $> setenv FOO=bar  (depending on the implemented syntax)."
#echo "setenv FOO bar" | pbcopy

#read -p "Press enter to continue"
#echo "$> env"
#echo "env" | pbcopy
#echo "must display a FOO variable with the value bar."
#read -p "Press enter to continue"

#echo "$> echo $FOO"
#echo "echo \$FOO" | pbcopy
#echo "The value bar must be displayed."
#read -p "Press enter to continue"

#echo "$> /usr/bin/env"
#echo "/usr/bin/env" | pbcopy
#echo "Minishell must send the appropriate environment to ran binaries. /usr/bin/env must display environment including FOO and
#its value bar."
#read -p "Press enter to continue"

#echo "$> unsetenv FOO"
#echo "unsetenv FOO" | pbcopy
#read -p "Press enter to continue"
#echo "$> env"
#echo "env" | pbcopy
#echo "The environment variable FOO must not be displayed anymore."
#read -p "Press enter to continue"

#echo "$> unsetenv FOO"
#echo "unsetenv FOO" | pbcopy
#read -p "Press enter to continue"
#echo "$> env"
#echo "env" | pbcopy
#echo "Environment must not change."
#read -p "Press enter to continue"

#echo "$> /usr/bin/env"
#echo "/usr/bin/env" | pbcopy
#echo "/usr/bin/env must not display variable FOO anymore."
#read -p "Press enter to continue"

#echo "PATH"
#read -p "Press enter to continue"

#echo "$> unsetenv PATH"
#echo "unsetenv PATH" | pbcopy
#read -p "Press enter to continue"
#echo "$> setenv PATH '/bin:/usr/bin' [or] $> setenv 'PATH=/bin:/usr/bin' (depending on the implemented syntax)."
#echo "setenv PATH \"/bin:/usr/bin\"" | pbcopy
#read -p "Press enter to continue"
#echo "$> ls"
#echo "ls" | pbcopy
#echo "/bin/ls must be properly executed."
#read -p "Press enter to continue"

#echo "$> emacs"
#echo "emacs" | pbcopy
#echo "/usr/bin/emacs must be properly executed."
#read -p "Press enter to continue"

#echo "$> unsetenv PATH"
#echo "unsetenv PATH" | pbcopy
#read -p "Press enter to continue"
#echo "$> ls"
#echo "ls" | pbcopy
#echo "It must fail"
#read -p "Press enter to continue"
#echo "$> emacs"
#echo "emacs" | pbcopy
#echo "It must also fail."
#read -p "Press enter to continue"

#echo "$> /bin/ls"
#echo "/bin/ls" | pbcopy
#echo "/bin/ls must be properly executed."
#read -p "Press enter to continue"

#echo "$> /usr/bin/emacs"
#echo "/usr/bin/emacs" | pbcopy
#echo "/usr/bin/emacs must be properly executed."
#read -p "Press enter to continue"

#echo "CLM"
#echo "$>nothing"
#echo "The shell must do nothing and give back the prompt."
#read -p "Press enter to continue"
#echo "$>space"
#echo "The shell must do nothing and give back the prompt."
#read -p "Press enter to continue"
#echo "$>spaces and tabs"
#echo " \t \t \t" | pbcopy
#echo "the shell must do nothing and give back the prompt."
#read -p "Press enter to continue"
#echo "$> /bin/ls    -l \t -a  \t"

##echo "BONUS"
##echo "Ctrl-C"
##echo "kdfjhj Ctrl-C"
##echo "$> cat Ctrl-C"
##cat
##echo "The Minishell must kill cat's process and give back the prompt."
##echo "PATH rights"
##echo "mkdir /tmp/bin"
##mkdir /tmp/bin
##export PATH="$PATH:/tmp/bin"
##echo "export PATH=\"$PATH:/tmp/bin\""
##touch /tmp/bin/test_exec_rights.c && echo "
###include <stdio.h>
##int main()
##{
##	printf(\"KO\\n\");
##	return (0);
##}" >/tmp/bin/test_exec_rights.c
##echo "gcc -o /tmp/bin/test_exec_rights /tmp/bin/test_exec_rights.c"
##gcc -o /tmp/bin/test_exec_rights /tmp/bin/test_exec_rights.c
##echo "chmod 644 /tmp/bin/test_exec_rights"
##chmod 644 /tmp/bin/test_exec_rights
##From another folder, run the following
##command "$> test_exec_rights".
##echo "Check that the minishell refuses to run the program because of the missing execution rights."
##echo "Auto-completion"
##echo "$> ec"
##echo "then press tabulation. The minishell must complete the command into $> echo"
##echo  "$> ema"
##echo "The minishell must complete the command into $> emacs"
##echo "Semi colon"
##echo "$> echo TOP \; ls \; echo MIDDLE \; ls \; echo BOTTOM"
##TOP ; ls ; echo MIDDLE ; ls ; echo BOTTOM"
##echo "The 5 commands must be executed without any errors in the order they were written."
##echo "$> \;"
##echo "The minishell must either run nothing and give the prompt back or display a syntax error and give the prompt back."
