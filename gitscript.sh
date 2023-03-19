#!/bin/bash

read PROJECT
git clone git@github.com:fyasla/42_${PROJECT}.git $PROJECT
cd $PROJECT
git filter-repo --to-subdirectory-filter $PROJECT
cd ..
git remote add $PROJECT $PROJECT
git fetch $PROJECT --tags
git merge --allow-unrelated-histories $PROJECT/master
git remote remove $PROJECT
