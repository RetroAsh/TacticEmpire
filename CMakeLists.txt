cmake_minimum_required(VERSION 2.6)
project("TacticEmpire")
add_definitions(-Wall -Wextra)
SET(CMAKE_CXX_FLAGS_DEBUG  "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

if(${MINGW})
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++0x")
    SET(platform "mingw")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.8)
        SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DWINFOIREU")
    endif()
endif(${MINGW})

if(${UNIX})
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")
    SET(platform "gcc")
endif(${UNIX})

SET(BASEPATH "${CMAKE_SOURCE_DIR}")
INCLUDE_DIRECTORIES("${BASEPATH}")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDB")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -Os -s")

find_package(SFML 2.1 COMPONENTS system window graphics network audio REQUIRED)
if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML non trouvée")
endif(NOT SFML_FOUND)

include_directories(${SFML_INCLUDE_DIR})

file(
    GLOB_RECURSE
    files
    src/*.cpp
    include/*.hpp
)


find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(doc ${DOXYGEN_EXECUTABLE} doxygen.conf)
endif(DOXYGEN_FOUND)

if(WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${files})
else(WIN32)
    add_executable(${PROJECT_NAME} ${files})
endif(WIN32)

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${CMAKE_CURRENT_SOURCE_DIR}/extlib/${platform}/libjsoncpp.a)
