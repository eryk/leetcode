FILE(GLOB_RECURSE SRC_LIST *.cpp) # 递归获取目录下cpp文件

foreach (_target ${SRC_LIST})
    message(${_target})
    get_filename_component(cpp_name ${_target} NAME_WE) # NAME_WE = File name without directory or longest extension
    add_executable(${cpp_name} "${_target}")
endforeach ()