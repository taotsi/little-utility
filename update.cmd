REM @echo off
cd extern/
if exist temp rmdir Catch2 /s /q
if exist catch2 rmdir catch2 /s /q
mkdir temp
cd temp
git clone https://github.com/catchorg/Catch2.git
cd ..
move temp/Catch2/single_include/catch2 ./
rmdir temp /s /q
cd ..