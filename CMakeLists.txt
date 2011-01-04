# http://www.cmake.org/cmake/help/examples.html
# http://www.cmake.org/cmake/help/syntax.html
# http://public.kitware.com/cgi-bin/viewcvs.cgi/Tests/Tutorial/?root=CMake
# http://cabledogs.org/abinader/2009/12/07/how-cmake-simplifies-the-build-process-part-1-basic-build-system/
# http://rachid.koucha.free.fr/tech_corner/cmake_manual.html

cmake_minimum_required(VERSION 2.8)
project(helloworld)

# Add the src subdirectories
add_subdirectory(src)
