#!/bin/bash

OS_str="`uname -s`"

INSTALL="`ls /usr/include | grep ncurses`"

if [[ -n "$INSTALL" ]]
then
	echo "already installed!!"
	exit 0
else
	echo "your OS is $OS_str!!"
	if [[ "$OS_str" = "Linux"* ]] ; then
		sudo apt-get install libncurses5-dev libncursesw5-dev
	elif [[ "$OS_str" = "Darwin" ]]; then
		brew install ncurses
	fi
fi
