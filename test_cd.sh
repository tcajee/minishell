#! /bin/bash

exec 3>./test_pipe

echo "Launching minishell..."
echo "./minishell" >&3

read -p "Press enter to continue"

echo "BUILTINS"

read -p "Press enter to continue"

echo "$> cd /goinfre/$USER/Desktop"
echo "COMMENTED"
# echo "cd /goinfre/$USER/Desktop" >&3

echo "$> cd /"
echo "cd /" >&3

read -p "Press enter to continue"

echo "$> /bin/pwd"
echo "/bin/pwd" >&3
echo "must confirm that the current folder was updated."

read -p "Press enter to continue"

echo "$> cd ../../"
echo "cd ../../" >&3

read -p "Press enter to continue"

echo "$> /bin/pwd"
echo "/bin/pwd" >&3
echo "must confirm that the current folder was updated."

read -p "Press enter to continue"

echo "$> cd"
echo "cd" >&3

read -p "Press enter to continue"

echo "$> /bin/pwd"
echo "/bin/pwd" >&3
echo "/bin/pwd must confirm that the current folder is the user's home folder."

read -p "Press enter to continue"

echo "$> cd -"
echo "cd -" >&3

read -p "Press enter to continue"

echo "$> /bin/pwd"
echo "/bin/pwd" >&3
echo "/bin/pwd must confirm that the current folder is the folder relative/path/of/your/choice used before."

read -p "Press enter to continue"

echo "$> cd ../../../"
echo "cd ../../../" >&3

read -p "Press enter to continue"

echo "$> /bin/pwd"
echo "/bin/pwd" >&3
echo "/bin/pwd must confirm that the current folder was updated."

read -p "Press enter to continue"

echo "Testing complete..."
echo "exit" >&3
read -p "Press enter to continue"
