#!/bin/bash

INSTALL="`ls /usr/include | grep ncurses`"

if [[ -n "$INSTALL" ]]
then
	echo "already installed!!"
	exit 0
else

	OS_str="`uname -s`"

	if [[ "$OS_str" = "Linux"* ]] ; then
		sudo apt-get install libncurses5-dev libncursesw5-dev
	fi

fi
