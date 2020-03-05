#! /bin/bash

exec 3>./test_pipe
echo "./minishell" >&3
echo "echo test" >&3
