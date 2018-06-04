#!/bin/sh
read -n1 -p "Test SEGV? [y,n]: " P
if [ $P = "y" ]
	then
		echo "\n\nTest map negative" && ./../*.filler < trace/trace_tab_neg_vm &>/dev/null
		echo "Test piece negative" && ./../*filler < trace/trace_piece_neg_vm &>/dev/null
	fi
echo
read -n1 -p "Test Leaks? [y,n]: " P
if [ $P = "y" ]
	then
		touch trace_valgrind
		echo "\n" && valgrind --leak-check=full --log-file="trace_valgrind" ./../*.filler < trace/trace_vm &>/dev/null
		tail -n 12 trace_valgrind
	fi
echo
read -n1 -p "Remove Log valgrind? [y,n]: " P
if [ $P = "y" ]
	then
		rm -f trace_valgrind
		echo "\n\n\033[0;31mtrace_valgrind deleted\033[0m"
	fi
echo
read -n1 -p "Test champion? [y,n]: " P
if [ $P = "y" ]
	then
		echo "\n\n\033[0;32mQue le duel commence\033[0m\n"
		./battle.sh
	fi
