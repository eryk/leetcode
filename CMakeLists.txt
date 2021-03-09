cmake_minimum_required(VERSION 3.11)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

FILE(GLOB_RECURSE SRC_LIST *.cpp) # 递归获取目录下cpp文件

foreach (_target ${SRC_LIST})
    get_filename_component(cpp_name ${_target} NAME_WE) # NAME_WE = File name without directory or longest extension
    add_executable(${cpp_name} "${_target}")
endforeach ()