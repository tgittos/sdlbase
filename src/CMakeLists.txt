# http://www.cmake.org/cmake/help/examples.html

set(CORE_LIBS opengl32 glu32 SDL SDLmain)

# Make sure compiler can find SDL
include_directories("${helloworld_SOURCE_DIR}/include")
# Make sure linker can find SDL lib
link_directories("${helloworld_SOURCE_DIR}/lib/SDL")

if(WIN32)
# TODO: Replace absolute paths with $ENV{DXSDK_DIR}
# Make sure compiler can find DirectX
#include_directories("C:\\Program Files\\Microsoft DirectX SDK (June 2010)\\Include")
include_directories("$ENV{DXSDK_DIR}\\Include")
# Make sure linker can find DirectX lib
#link_directories("C:\\Program Files\\Microsoft DirectX SDK (June 2010)\\Lib\\x86")
link_directories("$ENV{DXSDK_DIR}\\Lib\\x86")
# Add DirectX to link libs
set(CORE_LIBS ${CORE_LIBS} d3d9 d3dx9 DxErr)
endif(WIN32)

# Use 'find_package' to find libs we need
find_package(OpenGL)
find_package(SDL REQUIRED)

# Add the Graphics library
add_subdirectory(Graphics)

# Make sure compiler can find Graphics headers
include_directories("${helloworld_SOURCE_DIR}/src/Graphics")
# Make sure linker can find Graphics library
link_directories("${helloworld_SOURCE_DIR}/src/Graphics")

# Stuff to build the project
set(EXECUTABLE_OUTPUT_PATH "${helloworld_SOURCE_DIR}/bin")
add_executable(helloworld Main Game)
target_link_libraries(helloworld Graphics ${CORE_LIBS})
