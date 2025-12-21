##########################################################################################################
#--Date: 2021.03.10
#--Author:hananiah
#--Note:位于Source目录下面
#--Note: @2023.01.24 调整注释的内容
##########################################################################################################
message(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Designer app Directory<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<")

message("CMAKE_SOURCE_DIR == ")
message("${CMAKE_SOURCE_DIR}")
message("${CMAKE_CURRENT_SOURCE_DIR}")

# 批量添加程序文件，包括源文件 头文件 资源文件等
# 注意路径是当前目录，不然的话文件无法正确添加到VS中
FILE(GLOB APP_FILES "${PROJECT_SOURCE_DIR}/Designer/APP/*.cpp" "${PROJECT_SOURCE_DIR}/Designer/APP/*.h")

FILE(GLOB SOURCE_CPP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
FILE(GLOB HEADER_H_FILES   "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
FILE(GLOB HEADER_HPP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

# QT的资源文件-qrc,qml,ui,pro
FILE(GLOB RESOURCE_QRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.qrc")
FILE(GLOB RESOURCE_QML_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.qml")
FILE(GLOB RESOURCE_UI_FILES  "${CMAKE_CURRENT_SOURCE_DIR}/*.ui")
FILE(GLOB RESOURCE_PRO_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.pro")
FILE(GLOB RESOURCE_XML_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.xml")



#-----------------------------------------------------------------------------
# 头文件搜索路径
#-----------------------------------------------------------------------------
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/Alice/Bootstrap/Interface/AliceLaunchInterface/Public)
include_directories(${PROJECT_SOURCE_DIR}/Alice/Core/Foundation/AliceBasicTool/Public)
include_directories(${PROJECT_SOURCE_DIR}/Alice/AliceCommonApplication/Public)
include_directories(${PROJECT_SOURCE_DIR}/Alice/InteractionLayer/Interface/AliceApplicationInterface/Public)


#-----------------------------------------------------------------------------
# 自动添加include目录
#-----------------------------------------------------------------------------
#由于生成的C++文件都是放在编译目录里的（在Shadow Building中有别于源码目录），
#所以还需要将编译目录包含到Include目录，否则编译器会找不到这些头文件：
set(CMAKE_INCLUDE_CURRENT_DIR ON)


#============================================================================#
#  给SolidRender这个工程配置第三方的库
#============================================================================#
if(WIN32)
set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.15.14/5.15.14/msvc2019_64")
# 设置QT的头文件包含路径
# 如果找不到环境变量QTDIR的路径，那么自己设置吧; 也可以在GUI交互界面上手动设置
SET(QTDIR C:/Qt/Qt5.15.14/5.15.14/msvc2019_64)
endif()

find_package(Qt5 COMPONENTS Core Gui Widgets Network Quick Qml REQUIRED)


# QT5头文件路径
if(WIN32)
    message("----------------qt5 files include directory--------------------")
    include_directories(${QTDIR}/include)
    include_directories(${QTDIR}/include/QtWidgets)
    include_directories(${QTDIR}/include/QtCore)
    include_directories(${QTDIR}/include/QtGui)
    include_directories(${QTDIR}/include/QtOpenGL)
    include_directories(${QTDIR}/include/QtMultimedia)
    include_directories(${QTDIR}/include/QtQuick)
    include_directories(${QTDIR}/include/QtQml)
    include_directories(${QTDIR}/include/QtNetwork)
    include_directories(${QTDIR}/mkspecs/win32-msvc2012)

    #-----------------------------------------------------------------------------
    # 添加需要链接的库文件目录LINK_DIRECTORIES
    # 例如QT库
    #-----------------------------------------------------------------------------
    link_directories(${QTDIR}/lib)
endif()

#-----------------------------------------------------------------------------
#---------------------------第三方库的头文件和二进制文件----------------------
#-----------------------------------------------------------------------------
#@1. 指定第三方的头文件
include_directories(${CMAKE_SOURCE_DIR}/externals/3rdParty/include)
include_directories(${CMAKE_SOURCE_DIR}/externals/3rdParty/include/freetype)
include_directories(${CMAKE_SOURCE_DIR}/externals/3rdParty/include/glad)
include_directories(${CMAKE_SOURCE_DIR}/externals/3rdParty/include/GLFW)
include_directories(${CMAKE_SOURCE_DIR}/externals/3rdParty/include/glm)
include_directories(${CMAKE_SOURCE_DIR}/externals/3rdParty/include/KHR)
include_directories(${CMAKE_SOURCE_DIR}/externals/3rdParty/include/log4cplus)
include_directories(${CMAKE_SOURCE_DIR}/externals/3rdParty/include/SFML)
include_directories(${CMAKE_SOURCE_DIR}/externals/3rdParty/include/soil)
include_directories(${CMAKE_SOURCE_DIR}/externals/3rdParty/src)

#@2. 指定第三方库的路径
link_directories(${CMAKE_SOURCE_DIR}/externals/3rdParty/lib)
link_directories(${CMAKE_SOURCE_DIR}/externals/3rdParty/lib/sfml)

#@3. 指定exe的输出路径
message("The executable file's path is: ")
message(${PROJECT_SOURCE_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/x64/Debug) 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/x64/Release) 
 
#@4. 指定自定义库的链接路径
#这个话会一次性添加两条路径，自动判断编译类型，智能！
#link_directories(${PROJECT_SOURCE_DIR}/bin)
message("The path of link lib: ")
message("CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
link_directories(${CMAKE_BINARY_DIR}/x64/${CMAKE_BUILD_TYPE})


#-----------------------------------------------------------------------------
# QRC文件打包及前处理命令
#-----------------------------------------------------------------------------
set(GEN_RCC_BAT   "${CMAKE_SOURCE_DIR}/Designer/UIResource/GenerateRcc.bat")
set(GEN_RCC_WD    "${CMAKE_SOURCE_DIR}/Designer/UIResource")
set(SD_RCC_DIR    "${CMAKE_BINARY_DIR}/rcc")
set(SD_RCC_FILE   "${SD_RCC_DIR}/SolidDesignerRes.rcc")

# 收集所有 .qrc（改变时触发重建）
file(GLOB_RECURSE SD_QRCS "${GEN_RCC_WD}/*.qrc")


#-----------------------------------------------------------------------------
# 添加可执行程序目标
#-----------------------------------------------------------------------------
# 生成可执行文件,包括筛选器common[COMMON_CPP_FILES,COMMON_H_FILES,COMMON_HPP_FILES]等
# 程序源文件
# 头文件
# 资源文件-QRC,QML,UI,PRO,XML
# 筛选器-common-CPP,H,HPP文件
add_executable(${PROJECT_NAME} 
 ${SOURCE_CPP_FILES}
 ${HEADER_H_FILES}
 ${HEADER_HPP_FILES}
 ${APP_FILES})


# 目标级编译宏（代替全局 add_definitions）
target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        _USRDLL
        _CRT_SECURE_NO_WARNINGS
)


# 定义：如何生成 .rcc
if(WIN32)
add_custom_command(OUTPUT "${SD_RCC_FILE}"
  COMMAND ${CMAKE_COMMAND} -E make_directory "${SD_RCC_DIR}"
  COMMAND ${CMAKE_COMMAND} -E echo ">>> GenerateRCC: ${GEN_RCC_BAT} -> ${SD_RCC_FILE}"
  COMMAND ${CMAKE_COMMAND} -E env "QTDIR_X64=$ENV{QTDIR_X64}" "${GEN_RCC_BAT}" "${SD_RCC_DIR}" #real execution

  WORKING_DIRECTORY "${GEN_RCC_WD}"
  DEPENDS ${SD_QRCS}           # .qrc 变更触发
  VERBATIM
)
else()
 # Linux/macOS：用 Qt 的 rcc 直接生成二进制 rcc
  find_program(QT_RCC_EXECUTABLE NAMES rcc rcc-qt5)
  if(NOT QT_RCC_EXECUTABLE)
    message(FATAL_ERROR "Qt rcc not found. Ensure Qt is installed and rcc is in PATH.")
  endif()

  add_custom_command(
  OUTPUT  "${SD_RCC_FILE}"
  COMMAND ${CMAKE_COMMAND} -E make_directory "${SD_RCC_DIR}"
  COMMAND "${QT_RCC_EXECUTABLE}" -binary ${SD_QRCS} -o "${SD_RCC_FILE}"
  WORKING_DIRECTORY "${GEN_RCC_WD}"
  DEPENDS ${SD_QRCS}
  VERBATIM
)
endif()

 # 声明一个“资源生成”目标，并让可执行程序依赖它
add_custom_target(SolidDesignerRes ALL DEPENDS "${SD_RCC_FILE}")
add_dependencies(${PROJECT_NAME} SolidDesignerRes)

# 无论什么生成器，把 .rcc 复制到运行目录（等价于通用版 “Pre-Build”）
add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${PROJECT_NAME}>/resources"
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
          "${SD_RCC_FILE}" "$<TARGET_FILE_DIR:${PROJECT_NAME}>/resources/SolidDesignerRes.rcc"
  VERBATIM
)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Designer/APP")
set_target_properties(SolidDesignerRes PROPERTIES FOLDER "Designer/APP")

set (CMAKE_INSTALL_PREFIX "${INSTALL_DIR}/INSTALL" CACHE INTERNAL "" FORCE)

# 把目标文件安装到指定的目录
message("install is ${INSTALL_DIR}")
install(TARGETS ${PROJECT_NAME} DESTINATION "${INSTALL_DIR}/INSTALL")

# 安装第三方库的DLL
install(DIRECTORY "${CMAKE_SOURCE_DIR}/externals/3rdParty/bin/" DESTINATION "${INSTALL_DIR}/INSTALL" FILES_MATCHING PATTERN "*.dll")

# 安装第三方库的头文件
install(DIRECTORY "${CMAKE_SOURCE_DIR}/externals/3rdParty/include" DESTINATION "${INSTALL_DIR}/INSTALL")

install(DIRECTORY "${CMAKE_SOURCE_DIR}/source/resource/data" DESTINATION "${INSTALL_DIR}/INSTALL")

install(DIRECTORY "${CMAKE_SOURCE_DIR}/source/resource/Script" DESTINATION "${INSTALL_DIR}/INSTALL")



# if(SOLIDRENDER_WIN)
    # if("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "x64")
        # #install(DIRECTORY "${CMAKE_BINARY_DIR}/x64/${CMAKE_BUILD_TYPE}" DESTINATION "${INSTALL_DIR}/INSTALL" FILES_MATCHING PATTERN "*.dll" PATTERN "${CMAKE_BUILD_TYPE}" EXCLUDE)
        # install(FILES "${CMAKE_BINARY_DIR}/x64/${CMAKE_BUILD_TYPE}/CommandSystem.dll" DESTINATION "${INSTALL_DIR}/INSTALL" )
        # install(FILES "${CMAKE_BINARY_DIR}/x64/${CMAKE_BUILD_TYPE}/AlicePropertyBrowser.dll" DESTINATION "${INSTALL_DIR}/INSTALL" )
        # install(FILES "${CMAKE_BINARY_DIR}/x64/${CMAKE_BUILD_TYPE}/XFrameWork.dll" DESTINATION "${INSTALL_DIR}/INSTALL" )
        # install(FILES "${CMAKE_BINARY_DIR}/x64/${CMAKE_BUILD_TYPE}/XRibbonBar.dll" DESTINATION "${INSTALL_DIR}/INSTALL" )
        # install(FILES "${CMAKE_BINARY_DIR}/x64/${CMAKE_BUILD_TYPE}/XToolbar.dll" DESTINATION "${INSTALL_DIR}/INSTALL" )
    # endif()

    # if("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "Win32")
        # install(DIRECTORY "${CMAKE_BINARY_DIR}/x86/${CMAKE_BUILD_TYPE}"  DESTINATION "${INSTALL_DIR}/INSTALL")
    # endif()

# elseif(SOLIDRENDER_LINUX)  
    # install(DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}"  DESTINATION "${INSTALL_DIR}/INSTALL")
# endif()


#-----------------------------------------------------------------------------
# 链接第三方的库
# @1、链接的动作需要放到add_library之后
#-----------------------------------------------------------------------------
message("PROJECT_NAME = ${PROJECT_NAME}")
if(WIN32)
    target_link_libraries(${PROJECT_NAME}
        glu32
        glew32
        opengl32
        freeimage
        log4cplusU
        AliceCoreApplicationInterface
        AliceUiFrameWork
        AliceBasicTool
        AliceComponentSystem
        AliceLaunchInterface
    )
else()
    target_link_libraries(${PROJECT_NAME}
        OpenGL::GL 
        OpenGL::GLU
        AliceCoreApplicationInterface
        AliceUiFrameWork
        AliceBasicTool
        AliceComponentSystem
        AliceLaunchInterface
    )
endif()


message(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>End Designer APP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<")