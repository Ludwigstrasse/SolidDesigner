##########################################################################################################
#--Date:    2015.01.24
#--Project: SolidDesignerCommand
#--Author:  hananiah
##########################################################################################################
message("*--*--*--*--*--*--*--*--*--*--*--*--*--Start SolidDesignerCommand--*--*--*--*--*--*--*--*--*--*--**--*--*--*")

add_definitions(-DSOLID_DESIGNER_UI_HOME)
add_definitions(-DSOLID_DESIGNER_COMMAND_HOME)

message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
# 先指定你项目内置的 Python 解释器
set(_SD_PY_ROOT "${CMAKE_SOURCE_DIR}/ToolChain/Python310")
set(Python3_EXECUTABLE "${_SD_PY_ROOT}/python.exe" CACHE FILEPATH "SolidDesigner bundled Python" FORCE)

# 然后再找 Python3
find_package(Python3 REQUIRED COMPONENTS Interpreter)

message(STATUS "Using Python3_EXECUTABLE = ${Python3_EXECUTABLE}")

message("${PROJECT_SOURCE_DIR}")

set(ABS_SDC "${PROJECT_SOURCE_DIR}/Designer/UI/SolidDesignerCommand")

file(GLOB SDC_FILES
  "${ABS_SDC}/*.cpp" "${ABS_SDC}/*.h"
  "${ABS_SDC}/BaseCommands/*.h" "${ABS_SDC}/BaseCommands/*.cpp"
  "${ABS_SDC}/EditCommands/*.h" "${ABS_SDC}/EditCommands/*.cpp"
  "${ABS_SDC}/HelpCommands/*.h" "${ABS_SDC}/HelpCommands/*.cpp"
  "${ABS_SDC}/GeneralCommands/*.h" "${ABS_SDC}/GeneralCommands/*.cpp"
)

source_group(TREE "${ABS_SDC}" FILES ${SDC_FILES})

#-----------------------------------------------------------------------------
# 库文件链接路径(ALICE_LIB_DIR 在上级定义了)
#-----------------------------------------------------------------------------
link_directories(${ALICE_LIB_DIR})

#-----------------------------------------------------------------------------
# 头文件搜索路径
#-----------------------------------------------------------------------------
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/Alice/Core/Foundation/AliceBasicTool/Public)
include_directories(${PROJECT_SOURCE_DIR}/Alice/Core/Foundation/AliceFoundation/Public)
include_directories(${PROJECT_SOURCE_DIR}/Alice/Interaction/Interface/AliceCommandInterface/Public)
include_directories(${PROJECT_SOURCE_DIR}/Alice/Interaction/Interface/AliceOperationInterface/Public)
include_directories(${PROJECT_SOURCE_DIR}/Alice/Data/Interface/AliceModelInterface/Public)

include_directories(${PROJECT_SOURCE_DIR}/Alice/UI/QFrameWork/AliceUiFrameWork/Public)

#=============================================================================
#指定工程为动态库程序
add_library(SolidDesignerCommand SHARED ${SDC_FILES})
#设定工程的过滤器
set_target_properties(SolidDesignerCommand PROPERTIES FOLDER "Designer/UI")
#=============================================================================


#-----------------------------------------------------------------------------
# 根据系统及机器位数设置链接的位数
# 必须放在link之后,否则设置无效
#-----------------------------------------------------------------------------
set(CMAKE_SHARED_LINKER_FLAGS "/machine:x64")


if(WIN32)
    # include the major version number in Windows shared library names (but not import library names)
    set_target_properties(SolidDesignerCommand PROPERTIES DEBUG_POSTFIX "")
    set_target_properties(SolidDesignerCommand PROPERTIES SUFFIX "${CMAKE_SHARED_LIBRARY_SUFFIX}")
else()
    set_target_properties(SolidDesignerCommand PROPERTIES DEBUG_POSTFIX "d")
endif()
if (WIN32 AND MINGW)
    # on Windows/gcc get rid of "lib" prefix for shared libraries,
    # and transform the ".dll.a" suffix into ".a" for import libraries
    set_target_properties(SolidDesignerCommand PROPERTIES PREFIX "")
    set_target_properties(SolidDesignerCommand PROPERTIES IMPORT_SUFFIX ".a")
endif()

#-----------------------------------------------------------------------------
# 定义项目构建中间文件的生成目录
#-----------------------------------------------------------------------------
message("${CMAKE_BINARY_DIR}")
set(CMAKE_GENERATOR_PLATFORM x64)
if(SOLIDRENDER_WIN)
    if("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "x64")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/x64/Debug)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/x64/Debug)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/x64/Debug)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/x64/Release)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/x64/Release)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/x64/Release)
    endif()

    if("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "Win32")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/x86/Debug)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/x86/Debug)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/x86/Debug)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/x86/Release)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/x86/Release)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/x86/Release)
    endif()

elseif(SOLIDRENDER_LINUX)  
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
endif()



#-----------------------------------------------------------------------------
# Automatically generate SolidDesignerCommands.h
#-----------------------------------------------------------------------------
set(COMMANDS_XML  ${PROJECT_SOURCE_DIR}/Designer/Data/CommandsConfig.xml)
set(COMMANDS_HDR  ${PROJECT_SOURCE_DIR}/Designer/UI/SolidDesignerCommand/SolidDesignerCommands.h)
set(COMMANDS_PY   ${CMAKE_SOURCE_DIR}/Designer/Data/Scripts/generate_solid_designer_commands.py)

message(STATUS "COMMANDS_XML = ${COMMANDS_XML}")
message(STATUS "COMMANDS_PY  = ${COMMANDS_PY}")

add_custom_command(
  OUTPUT  ${COMMANDS_HDR}
  COMMAND ${Python3_EXECUTABLE} ${COMMANDS_PY}
          --xml ${COMMANDS_XML}
          --out ${COMMANDS_HDR}
  DEPENDS ${COMMANDS_XML} ${COMMANDS_PY}
  VERBATIM
  COMMENT "Generating SolidDesignerCommands.h"
)

add_custom_target(SolidDesignerCommandsId DEPENDS ${COMMANDS_HDR})
add_dependencies(SolidDesignerCommand SolidDesignerCommandsId)

# 可选：让 IDE 看到生成文件
target_sources(SolidDesignerCommand PRIVATE ${COMMANDS_HDR})
set_source_files_properties(${COMMANDS_HDR} PROPERTIES GENERATED TRUE)

set_target_properties(SolidDesignerCommandsId PROPERTIES FOLDER "Designer/UI")


#-----------------------------------------------------------------------------
# 链接第三方的库
# @1、链接的动作需要放到add_library之后
#-----------------------------------------------------------------------------
target_link_libraries(SolidDesignerCommand
    AliceFoundation
    AliceBasicTool
    AliceCommandInterface
    AliceOperationInterface
    AliceModelInterface
    AliceUiFrameWork
)



message("*--*--*--*--*--*--*--*--*--*--*--**--*--*--End SolidDesignerCommand*--*--*--*--*--*--*--*--*--*--*--*--*--*")