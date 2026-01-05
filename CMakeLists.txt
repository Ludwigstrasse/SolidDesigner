##########################################################################################################
#--Date:    2021.03.10
#--Project: SolidRender
#--Author:  hananiah
#--Note:位于SolidRender顶级目录下面
#--2021.10.03: 增加INSTALL项目，实现工程的自动安装功能
#              今日对工程的生成目录做重大调整，以后禁止VS工程的路径与源码同目录
##########################################################################################################
message("*--*--*--*--*--*--*--*--*--*--*--*--Start Top Level CmakeList*--*--*--*--*--*--*--*--*--*--*--*")

#-----------------------------------------------------------------------------
# 工程属性设置
#-----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
# 设置项目名称 语言
project(SolidDesigner VERSION 1.1.0  LANGUAGES CXX  DESCRIPTION "SolidRender is a parametric modeling software")

#-----------------------------------------------------------------------------
# 编译系统设置
#-----------------------------------------------------------------------------

#设置C++标准
set(CMAKE_CXX_STANDARD 17)

# 是否强制要求C++标准为${CMAKE_CXX_STANDARD},如果为OFF则可能使用旧的标准
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# 指定是否使用编译器特定的扩展
set(CMAKE_CXX_EXTENSIONS OFF)

#VS /MT模式的设置
message("The cmake source dir is:")
message("${CMAKE_SOURCE_DIR}")

set(CMAKE_USE_MAKE_RULES_OVERRIDE
    "${CMAKE_SOURCE_DIR}/cmake/c_flag_overrides.cmake")

set(CMAKE_USE_MAKE_RULES_OVERRIDE_CXX
    "${CMAKE_SOURCE_DIR}/cmake/cxx_flag_overrides.cmake")

#-----------------------------------------------------------------------------
# 检测操作系统
#-----------------------------------------------------------------------------
message("CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(SOLIDRENDER_LINUX True)
    
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(SOLIDRENDER_WIN True)
    # if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
        # set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/INSTALL" CACHE PATH "${PROJECT_NAME}的安装路径" FORCE)
    # endif()
else()
    message(SEND_ERROR, "No Support System!")
endif()


#-----------------------------------------------------------------------------
# 指定编译选项
#-----------------------------------------------------------------------------
#设置编译类型，此处需要考虑多种编译选项
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE debug)
endif()


if(MSVC)
    add_definitions(-DUNICODE -D_UNICODE)
endif()


#配置项目的安装选项
message("The project binary dir is:")
message("${PROJECT_BINARY_DIR}")
message("The current binary dir is:")
message("${CMAKE_CURRENT_BINARY_DIR}")
message("The cmake install bin dir is:")
message("${CMAKE_INSTALL_BINDIR}")
message("The cmake install prefix is:")
message("${CMAKE_INSTALL_PREFIX}")
message("The cmake binary dir is:")
message("${CMAKE_BINARY_DIR}")


#-----------------------------------------------------------------------------
# 定义变量作为项目的安装路径
#-----------------------------------------------------------------------------
#隐藏CMAKE_INSTALL_PREFIX宏
# set (CMAKE_INSTALL_PREFIX "${INSTALL_DIR}" CACHE INTERNAL "" FORCE)
# message("${CMAKE_INSTALL_PREFIX}")

# 安装路径预定义
if (NOT DEFINED INSTALL_DIR)
    message("install dir is not defined")
    # 设置Windows环境下的默认安装路径
    if (WIN32 AND NOT DEFINED CMAKE_INSTALL_PREFIX)
      message("set cmake install prefix macro")
      set (CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}")
    endif()
      message("set the value of install dir")
    # 设置安装路径
    set (INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}" CACHE PATH "")
else()
  message("The definition of install dir exists already")
  set (INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}" CACHE PATH "SolidRender的预设安装目录" FORCE)
  message("${INSTALL_DIR}")
endif()


#-----------------------------------------------------------------------------
# 定义项目构建中间文件的生成目录
#-----------------------------------------------------------------------------
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
# 从系统查找Qt模块,开启Qt中间文件的自动生成
#-----------------------------------------------------------------------------
#设置QT5的库路径
# set(Qt5_FOUND false)
# set(CMAKE_PREFIX_PATH $ENV{QTDIR})
# message("ENVIRONMENT PATH OF QT IS ${CMAKE_PREFIX_PATH}")
#set(Qt5_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5")
#Qt程序中的QRC资源文件需要用rcc来进行预处理，生成相应.h和.cpp文件。
#QObject派生的C++类也需要通过moc进行处理。
#这些都是编译系统中所谓的Rules。
#CMake中通过打开下面两个选项可以自动对这些后缀的文件进行相应处理
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_AUTOUIC ON)


#----------------------------------------------------------------------------
# 开启项目分组
#----------------------------------------------------------------------------
# option 目录定义了一个变量叫做USE_SOLUTION_FOLDERS，并给了初始值ON
option(USE_SOLUTION_FOLDERS "使用资源管理器文件夹" ON)
if(USE_SOLUTION_FOLDERS)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")
endif()

#-----------------------------------------------------------------------------
# 定义全局的链接路径
#-----------------------------------------------------------------------------
message("ALICE_LIB_DIR: ")

if(CMAKE_GENERATOR MATCHES "Visual Studio")
  # VS: 有平台子目录（x64/Win32），并且是多配置
  set(ALICE_LIB_DIR "${CMAKE_BINARY_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>")

elseif(CMAKE_GENERATOR STREQUAL "Ninja Multi-Config")
  # Ninja 多配置（CMake 3.17+）
  set(ALICE_LIB_DIR "${CMAKE_BINARY_DIR}/$<CONFIG>")

elseif(CMAKE_GENERATOR STREQUAL "Ninja")
  # Ninja 单配置：依赖 CMAKE_BUILD_TYPE
  # 例：cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug ..
  set(ALICE_LIB_DIR "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")

else()
  # 其他生成器兜底：先按“多配置”判断
  if(CMAKE_CONFIGURATION_TYPES)
    set(ALICE_LIB_DIR "${CMAKE_BINARY_DIR}/$<CONFIG>")
  else()
    set(ALICE_LIB_DIR "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")
  endif()
endif()

message("${ALICE_LIB_DIR}")
#-----------------------------------------------------------------------------
# 定义GNU标准的安装目录（GNUInstallDirs.cmake）
#-----------------------------------------------------------------------------
include(GNUInstallDirs)
set(CMAKE_INSTALL_LIBDIR "lib")

#-----------------------------------------------------------------------------
# 设置SPDLOG
#-----------------------------------------------------------------------------
set(SPDLOG_HEADER_ONLY ON CACHE BOOL "" FORCE)
set(SPDLOG_FMT_EXTERNAL OFF CACHE BOOL "" FORCE)

#-----------------------------------------------------------------------------
# 定义源代码的路径
#-----------------------------------------------------------------------------
# APPS 目录（可选：需要 Qt）
option(SD_BUILD_DESIGNER "Build the SolidDesigner GUI application (requires Qt)" ON)
if(SD_BUILD_DESIGNER)
  add_subdirectory(Designer)
else()
  message(STATUS "Skipping Designer application build (SD_BUILD_DESIGNER=OFF)")
endif()

# 平台层
add_subdirectory(Alice)

# 外部项目(包括第三方库)
add_subdirectory(Externals)

# 单元测试
add_subdirectory(UnitTest)

# Internal demos（可选：部分示例依赖 Qt）
option(SD_BUILD_DEMOS "Build demo targets (some require Qt)" ON)
if(SD_BUILD_DEMOS)
  add_subdirectory(Demos)
else()
  message(STATUS "Skipping demo targets (SD_BUILD_DEMOS=OFF)")
endif()






#-----------------------------------------------------------------------------
# Installation
#-----------------------------------------------------------------------------


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

# 测试target的存在性：
if(TARGET AliceCommandSystem)
  message(STATUS "AliceCommandSystem exists in APP scope")
else()
  message(STATUS "AliceCommandSystem NOT exists in APP scope")
endif()


# 建议：统一一个安装目的地根目录（你现在是 INSTALL_DIR/INSTALL）
set(SD_INSTALL_DST "${INSTALL_DIR}/INSTALL")
message("SD_INSTALL_DST = ${SD_INSTALL_DST}")
# 需要安装的目标列表
set(SD_INSTALL_TARGETS
    AliceCommandSystem
    AlicePropertyBrowser
    AliceRibbon
    AliceThemeSupport
    AliceUiBasicTools
    AliceUiFrameWork
    XRibbonBar
    XToolbar
)

# 可选：提前检查 target 是否存在（更容易定位问题）
foreach(_t IN LISTS SD_INSTALL_TARGETS)
    if(NOT TARGET ${_t})
        message(FATAL_ERROR "Install target not found: ${_t}")
    endif()
endforeach()

# Windows：必须加 WIN32，避免 Linux/Makefiles 被污染
if(WIN32 AND SOLIDRENDER_WIN)
    install(TARGETS ${SD_INSTALL_TARGETS}
        RUNTIME DESTINATION "${SD_INSTALL_DST}"   # .exe / .dll
        ARCHIVE DESTINATION "${SD_INSTALL_DST}"   # .lib（静态库或 import lib）
        LIBRARY DESTINATION "${SD_INSTALL_DST}"   # MinGW: .dll.a；MSVC 通常为空
    )

# Linux：同样用 TARGETS，CMake 会把 .so 走到 LIBRARY
elseif(UNIX AND NOT APPLE AND SOLIDRENDER_LINUX)
    install(TARGETS ${SD_INSTALL_TARGETS}
        RUNTIME DESTINATION "${SD_INSTALL_DST}"   # 通常为空（除非是可执行文件）
        LIBRARY DESTINATION "${SD_INSTALL_DST}"   # .so
        ARCHIVE DESTINATION "${SD_INSTALL_DST}"   # .a
    )
endif()

message("*--*--*--*--*--*--*--*--*--*--*--End Top Level CmakeList--*--*--*--*--*--*--*--*--*--*--*--*--*")