#!/bin/zsh

cd extern/
rm -rf Catch2
rm -rf catch2
mkdir temp
cd temp
git clone https://github.com/catchorg/Catch2.git
cd ..
mv temp/Catch2/single_include/catch2 .
rm -rf temp