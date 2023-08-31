# CMakeList.txt : CMake project for Raydiance, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Raydiance "Raydiance.cpp" "Raydiance.h" "Output.cpp" "Output.h" "Vec3.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Raydiance PROPERTY CXX_STANDARD 20)
endif() 

# TODO: Add tests and install targets if needed.
