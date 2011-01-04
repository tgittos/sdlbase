if exist build goto direxists
mkdir build
:direxists
cd build
cmake -G "Visual Studio 10" ..\
cd ..
