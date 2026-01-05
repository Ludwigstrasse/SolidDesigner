##########################################################################################################
#--Date:    2025.11.24
#--Project: SolidDemoPlugin
#--Author:  hananiah
##########################################################################################################
message("*--*--*--*--*--*--*--*--*--*--*--*--*--Start SolidDemoPlugin--*--*--*--*--*--*--*--*--*--*--**--*--*--*")

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
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${SD_ARCH}/Debug/Plugins)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${SD_ARCH}/Release)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${SD_ARCH}/Release)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${SD_ARCH}/Release/Plugins)

elseif(SOLIDRENDER_LINUX)  
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/Plugins)
endif()



#=============================================================================
#指定工程为动态库程序
add_library(SolidDemoPlugin SHARED ${SDP_FILES})
#设定工程的过滤器
set_target_properties(SolidDemoPlugin PROPERTIES FOLDER "Demos")
#=============================================================================

# 目标级编译宏（代替全局 add_definitions）
target_compile_definitions(SolidDemoPlugin
    PRIVATE
        ALICE_DEMO_PLUGIN_HOME
)


#-----------------------------------------------------------------------------
# 根据系统及机器位数设置链接的位数
# 必须放在link之后,否则设置无效
#-----------------------------------------------------------------------------

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