#!/bin/sh

build_type="Debug"
current_dir=`pwd`

tools_rel_dir=`dirname $0`
source_dir=`cd $tools_rel_dir/.. && pwd`
workspace_dir=`cd $source_dir/.. && pwd`

dir=`basename $source_dir`
build_dir="$dir-build-$build_type"
install_dir="$dir-install-$build_type"

print_usage() {
	echo "Usage: `basename $0`"
	echo "  +- $workspace_dir"
	echo "     +- $dir"
	echo "     +- $dir-build"
	echo "        \$] cmake"
	echo "        \$] make"
	echo "        \$] make install"
	echo "     +- $dir-install"
	echo "        \$] ./bin/antlr4-c-demo"
}

if [ -z $1 ]; then
	# create build directory if neccessary
	if [ ! -d "$workspace_dir/$dir-build" ]; then
		mkdir -p "$workspace_dir/$dir-build"
	fi
	# create install directory if neccessary
	if [ ! -d "$workspace_dir/$dir-install" ]; then
		mkdir -p "$workspace_dir/$dir-install"
	fi
	cd "$workspace_dir/$dir-build"
	cmake -DCMAKE_INSTALL_PREFIX:PATH="$workspace_dir/$dir-install" -DCMAKE_BUILD_TYPE:STRING=Debug -DENABLE_DEBUG:BOOL=1 "$workspace_dir/$dir"
	make
	make install
elif [ $1 = '--help' -o $1 = '-h' ]; then
	print_usage
	exit 1
fi


