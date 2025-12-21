##########################################################################################################
#--Date:    2015.01.24
#--Project: SolidDesignerCommand
#--Author:  hananiah
##########################################################################################################
message("*--*--*--*--*--*--*--*--*--*--*--*--*--Start SolidDesignerCommand--*--*--*--*--*--*--*--*--*--*--**--*--*--*")
message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
# 先指定你项目内置的 Python 解释器
if(WIN32)
    # Windows: use repo toolchain python
    set(_SD_PY_ROOT "${CMAKE_SOURCE_DIR}/ToolChain/Python310")
    set(Python3_EXECUTABLE "${_SD_PY_ROOT}/python.exe" CACHE FILEPATH "SolidDesigner bundled Python" FORCE)
else()
    message("Here is linux python... ...")
   # Linux/macOS: use system python3
    #find_program(_PY3 NAMES python3 python REQUIRED)
    #set(Python3_EXECUTABLE "${_PY3}" CACHE FILEPATH "Python3 interpreter" FORCE)

endif()


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

# 目标级编译宏（代替全局 add_definitions）
target_compile_definitions(SolidDesignerCommand
    PRIVATE
        SOLID_DESIGNER_COMMAND_HOME
)


#-----------------------------------------------------------------------------
# 根据系统及机器位数设置链接的位数
# 必须放在link之后,否则设置无效
#-----------------------------------------------------------------------------

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
# 用指针位数决定输出目录：x64 / x86
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(SD_ARCH "x64")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
  set(SD_ARCH "x86")
else()
  message(FATAL_ERROR "Unknown pointer size: ${CMAKE_SIZEOF_VOID_P}")
endif()

# Linux 侧需要 GNUInstallDirs 提供 CMAKE_INSTALL_LIBDIR/BINDIR
if(UNIX AND NOT APPLE)
  include(GNUInstallDirs)
endif()

# 防止误开关：Linux 下不允许走 SOLIDRENDER_WIN 分支
if(SOLIDRENDER_WIN AND NOT WIN32)
  message(FATAL_ERROR "SOLIDRENDER_WIN=ON but WIN32=OFF. Disable SOLIDRENDER_WIN on Linux.")
endif()
if(SOLIDRENDER_WIN)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${SD_ARCH}/Debug)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${SD_ARCH}/Debug)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${SD_ARCH}/Debug)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${SD_ARCH}/Release)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${SD_ARCH}/Release)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${SD_ARCH}/Release)

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
target_link_libraries(SolidDesignerCommand PRIVATE
    AliceFoundation
    AliceBasicTool
    AliceCommandInterface
    AliceOperationInterface
    AliceModelInterface
    AliceUiFrameWork
)



message("*--*--*--*--*--*--*--*--*--*--*--**--*--*--End SolidDesignerCommand*--*--*--*--*--*--*--*--*--*--*--*--*--*")