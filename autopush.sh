#!/bin/bash

commitContents=$1

git add *
echo -e "\033[43;31mGit Add is completed!!\033[0m"

git commit -m "${commitContents}"
echo -e "\033[43;31mGit Commit is completed!! = ${commitContents}\033[0m"

git push origin master
echo -e "\033[43;31mGit Push is completed!!\033[0m"
