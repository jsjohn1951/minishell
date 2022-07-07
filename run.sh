#!/bin/bash

make re && make clean && clear && valgrind -s --leak-check=full --track-fds=yes --show-leak-kinds=all --suppressions=.ignore_readline ./minishell