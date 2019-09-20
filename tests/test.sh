#! /bin/bash

exec 3>./minififo
./minishell >&3
echo "echo test" >&3
