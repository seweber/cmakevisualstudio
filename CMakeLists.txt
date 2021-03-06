cmake_minimum_required(VERSION 3.8.1 )
project (cmakevisualstudio CXX)

# Add source code and setup folder structure.
set(src ci/main.cpp)

# here we specify the additional include directories for the project.
include_directories(include)

# It specifies the executable name. Here the executable is the first parameter i.e. hello and a file hello.exe will be created.

add_executable(hello ${src})

###Search for packages and External Libraries###
#Set the module path
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)




# Find package : Sqlite3 calling Find.cmake
find_package(sqlite3 REQUIRED)
include_directories(${SQLITE3_INCLUDE_DIR})
list(APPEND LIBRARIES ${SQLITE3_LIBRARY})
message("Found SQL in: ${SQLITE3_INCLUDE_DIR} ${SQLITE3_LIBRARY} ${SQLITE3_BINARY}")

# Find package : Eigen3 calling Findeigen.cmake
find_package(Eigen3 REQUIRED)
include_directories("${EIGEN3_INCLUDE_DIR}")
message("Found Eigen3 in: ${EIGEN3_INCLUDE_DIR}")

# Find package : Boost preinstalled
find_package(Boost COMPONENTS filesystem system program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
list(APPEND LIBRARIES ${Boost_LIBRARIES})


# Find package : OpenMP
find_package(OpenMP REQUIRED)
if (OPENMP_FOUND)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
message("FOUND OpenMP: ${CMAKE_CXX_FLAGS}")
endif()

# Find GSL
#message("PKG_CONFIG_PATH")
find_package(GSL REQUIRED)
include_directories(${GSL_INCLUDE_DIRS})
list(APPEND LIBRARIES ${GSL_LIBRARIES})
message("FOUND GSL: ${GSL_LIBRARIES}")
#message("CMake Path List : ${CMAKE_MODULE_PATH} ${CMAKE_PROGRAM_PATH}")

# get version info from git
find_package(Git REQUIRED)

# Find SWIG
find_package(SWIG REQUIRED)

#Python
find_package(PythonInterp 3 REQUIRED)
#Pythn UIC
find_package(PyUIC REQUIRED)
#Python Libraries###
find_package(PythonLibs 3 REQUIRED)
#NumPy
find_package(Numpy REQUIRED)

target_link_libraries(hello ${LIBRARIES})
