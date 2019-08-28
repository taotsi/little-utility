#!/bin/zsh

cd extern/
rm -rf Catch2
rm -rf catch2
git clone https://github.com/catchorg/Catch2.git
mv Catch2/single_include/catch2 .
rm -rf Catch2