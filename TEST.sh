#!/bin/bash

read -p "Please enter your folder:" PATH
read -p "Please enter your file(.exe):" RPOGRAM_FILE
echo $RPOGRAM_FILE


all_correct=true
for f in $PATH/*/*/*.in
do
    echo "${f}"
    $RPOGRAM_FILE < $f > tmp
    # diff.exe -c tmp ${f%.*}.ans
    # if [ $? != 0 ]; then
    #     all_correct=false
    #     break
    # fi
done
if [ $all_correct == true ]; then
    echo "ALL PASS"
fi
read -p "Press ENTER to exit." enter