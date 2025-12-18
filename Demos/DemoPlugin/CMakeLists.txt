##########################################################################################################
#--Date:    2025.11.24
#--Project: SolidDemoPlugin
#--Author:  hananiah
##########################################################################################################
message("*--*--*--*--*--*--*--*--*--*--*--*--*--Start SolidDemoPlugin--*--*--*--*--*--*--*--*--*--*--**--*--*--*")

add_definitions(-DSOLID_DESIGNER_UI_HOME)
add_definitions(-DALICE_DEMO_PLUGIN_HOME)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.15.14/5.15.14/msvc2019_64")
find_package(Qt5Core       5.15 REQUIRED)
find_package(Qt5Gui        5.15 REQUIRED)
find_package(Qt5Widgets    5.15 REQUIRED)


message("${PROJECT_SOURCE_DIR}")

set(SDP "${PROJECT_SOURCE_DIR}/Demos/DemoPlugin")

file(GLOB SDP_FILES
  "${SDP}/*.cpp" "${SDP}/*.h" "${SDP}/*.xml"
  "${SDP}/Public/*.h"
)

source_group(TREE "${SDP}" FILES ${SDP_FILES})


set(RESOURCES "${SDP}/StyleTemplate.qrc")
source_group("resources" FILES ${RESOURCES})


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
include_directories(${PROJECT_SOURCE_DIR}/Alice/Core/Runtime/AlicePluginSystem/Public)
include_directories(${PROJECT_SOURCE_DIR}/Demos/DemoPlugin/Public)


#-----------------------------------------------------------------------------
# 定义项目构建中间文件的生成目录
#-----------------------------------------------------------------------------
message("${CMAKE_BINARY_DIR}")
set(CMAKE_GENERATOR_PLATFORM x64)
if(SOLIDRENDER_WIN)
    message("It is configuring the dir of output")
    if("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "x64")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/x64/Debug)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/x64/Debug)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/x64/Debug/Plugins)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/x64/Release)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/x64/Release)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/x64/Release/Plugins)
    endif()

    if("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "Win32")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/x86/Debug)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/x86/Debug)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/x86/Debug/Plugins)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/x86/Release)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/x86/Release)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/x86/Release/Plugins)
    endif()

elseif(SOLIDRENDER_LINUX)  
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
endif()



#=============================================================================
#指定工程为动态库程序
add_library(SolidDemoPlugin SHARED ${SDP_FILES})
#设定工程的过滤器
set_target_properties(SolidDemoPlugin PROPERTIES FOLDER "Demos")
#=============================================================================


#-----------------------------------------------------------------------------
# 根据系统及机器位数设置链接的位数
# 必须放在link之后,否则设置无效
#-----------------------------------------------------------------------------
set(CMAKE_SHARED_LINKER_FLAGS "/machine:x64")


if(WIN32)
    # include the major version number in Windows shared library names (but not import library names)
    set_target_properties(SolidDemoPlugin PROPERTIES DEBUG_POSTFIX "")
    set_target_properties(SolidDemoPlugin PROPERTIES SUFFIX "${CMAKE_SHARED_LIBRARY_SUFFIX}")
else()
    set_target_properties(SolidDemoPlugin PROPERTIES DEBUG_POSTFIX "d")
endif()
if (WIN32 AND MINGW)
    # on Windows/gcc get rid of "lib" prefix for shared libraries,
    # and transform the ".dll.a" suffix into ".a" for import libraries
    set_target_properties(SolidDemoPlugin PROPERTIES PREFIX "")
    set_target_properties(SolidDemoPlugin PROPERTIES IMPORT_SUFFIX ".a")
endif()




#-----------------------------------------------------------------------------
# 链接第三方的库
# @1、链接的动作需要放到add_library之后
#-----------------------------------------------------------------------------
target_link_libraries(SolidDemoPlugin
    AliceBasicTool
    AliceFoundation
    AlicePluginSystem
)



message("*--*--*--*--*--*--*--*--*--*--*--**--*--*--End SolidDemoPlugin*--*--*--*--*--*--*--*--*--*--*--*--*--*")