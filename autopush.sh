#!/bin/bash

commitMsg=$1

if [ $# -eq 1 ]
then
	git add *
fi

if [ $# -eq 2 ]
then
	commitContent=$2
	git add ./${commitContent}
fi

echo -e "\033[43;31mGit Add is completed!!\033[0m"

git commit -m "${commitMsg}"
echo -e "\033[43;31mGit Commit is completed!! Commit Msg = ${commitMsg}\033[0m"

git push origin master
echo -e "\033[43;31mGit Push is completed!!\033[0m"
