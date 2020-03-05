#! /bin/bash

exec 3>./test_pipe

echo "Launching minishell..."
echo "./minishell" >&3

read -p "Press enter to continue"

echo "$> echo \"It works\""
echo "echo \"It works\"" >&3
echo "The message must be properly displayed."

read -p "Press enter to continue"

echo "$> echo It works (without the double quotes)."
echo "echo It works" >&3
echo "The message must be properly displayed."

read -p "Press enter to continue"

echo "$> echo $HOME"
echo "echo \$HOME" >&3
echo "The value bar must be displayed."

read -p "Press enter to continue"

echo "Testing complete..."
echo "exit" >&3
read -p "Press enter to continue"
