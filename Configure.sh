#! /bin/bash

option=$1
ninja=1
DIR=build/
case $option in 
	"release")
		if [ ! -d "$DIR" ]; then
			mkdir build
		fi
		cd build
		cmake -DCMAKE_BUILD_TYPE=Release -S .. -B .
		make
		;;
	"debug")
		if [ ! -d "$DIR" ]; then
			mkdir build
		fi
		cd build
		cmake -DCMAKE_BUILD_TYPE=Debug -S .. -B .
		make
		;;
	"clean")
		cd build
		rm -rf CMakefiles CMakeCache.txt
		;;
	"ninja")
		if [ ! -d "$DIR" ]; then
			mkdir build
		fi
		cd build
		cmake -S .. -G Ninja
		ninja
		;;
esac

