#! /bin/bash

exec 3>./test_pipe

echo "Launching minishell..."
echo "./minishell" >&3

read -p "Press enter to continue"

echo "ENVS"

read -p "Press enter to continue"

echo "$> env"
echo "env" >&3
echo "must be displayed as key=value."

read -p "Press enter to continue"

echo "$> setenv FOO bar [or] $> setenv FOO=bar  (depending on the implemented syntax)."
echo "setenv FOO bar" >&3

read -p "Press enter to continue"

echo "$> env"
echo "env" >&3
echo "must display a FOO variable with the value bar."

read -p "Press enter to continue"

echo "$> echo $FOO"
echo "echo \$FOO" >&3
echo "The value bar must be displayed."

read -p "Press enter to continue"

echo "$> /usr/bin/env"
echo "/usr/bin/env" >&3
echo "Minishell must send the appropriate environment to ran binaries. /usr/bin/env must display environment including FOO and
its value bar."

read -p "Press enter to continue"

echo "$> unsetenv FOO"
echo "COMMENTED"
# echo "unsetenv FOO" >&3

read -p "Press enter to continue"

echo "$> env"
echo "env" >&3
echo "The environment variable FOO must not be displayed anymore."

read -p "Press enter to continue"

echo "$> unsetenv FOO"
echo "COMMENTED"
# echo "unsetenv FOO" >&3

read -p "Press enter to continue"

echo "$> env"
echo "env" >&3
echo "Environment must not change."

read -p "Press enter to continue"

echo "$> /usr/bin/env"
echo "/usr/bin/env" >&3
echo "/usr/bin/env must not display variable FOO anymore."

read -p "Press enter to continue"

echo "PATH"

read -p "Press enter to continue"

echo "$> unsetenv PATH"
echo "unsetenv PATH" >&3

read -p "Press enter to continue"

echo "$> setenv PATH '/bin:/usr/bin' [or] $> setenv 'PATH=/bin:/usr/bin' (depending on the implemented syntax)."
echo "setenv PATH /bin:/usr/bin" >&3

read -p "Press enter to continue"

echo "$> ls"
echo "ls" >&3
echo "/bin/ls must be properly executed."

read -p "Press enter to continue"

echo "$> emacs"
echo "emacs" >&3
echo "/usr/bin/emacs must be properly executed."

read -p "Press enter to continue"

echo "$> unsetenv PATH"
echo "unsetenv PATH" >&3

read -p "Press enter to continue"

echo "$> ls"
echo "ls" >&3
echo "It must fail"

read -p "Press enter to continue"

echo "$> emacs"
echo "emacs" >&3
echo "It must also fail."

read -p "Press enter to continue"

echo "$> /bin/ls"
echo "/bin/ls" >&3
echo "/bin/ls must be properly executed."

read -p "Press enter to continue"

echo "$> /usr/bin/emacs"
echo "/usr/bin/emacs" >&3
echo "/usr/bin/emacs must be properly executed."

read -p "Press enter to continue"

echo "Testing complete..."
echo "exit" >&3
read -p "Press enter to continue"
