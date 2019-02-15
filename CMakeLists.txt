cmake_minimum_required(VERSION 3.7)
project(MaintenanceTool)

set(CMAKE_CXX_STANDARD 11)


# Qt
# Set this to your Qt installation
set(CMAKE_PREFIX_PATH C:\\Qt\\Qt5.12.0\\5.12.0\\mingw73_64)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#src 1、当.h与.cpp不在同一路径中时，需要分别包含进来（在同一目录时可省略.h） 2、.ui文件（经测试，在CLion中.ui文件需要与对应的class在相同的路径内）
set(SOURCE_FILES src/main.cpp src/maindialog.cpp src/maindialog.h src/maindialog.ui)
#resources 1、.qrc文件 2、存放图片资源文件等
set(RESOURCE_FILES resources/notepad.qrc)

#libzippp dependency
#set(LIBZIPPP_PATH
#        D:/Workspace/CPP/frameworks/libzippp  # On Windows, this is where my tinyxml2 folder is
#        )
#
#find_path(LIBZIPPP_INCLUDE_DIR libzippp.h   # The variable to store the path in and the name of the header files
#        PATH_SUFFIXES include               # The folder name containing the header files
#        PATHS ${LIBZIPPP_PATH})
#find_library(LIBZIPPP               # The variable to store where it found the .a files
#        NAMES libzippp.a
#        PATH_SUFFIXES lib                   # The folder the .a file is in
#        PATHS ${LIBZIPPP_PATH})        # Where to look (defined above)
#include_directories(${LIBZIPPP_INCLUDE_DIR})

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

#图片等资源文件的文件夹包含进来
include_directories(resources/images)

# WIN32
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${RESOURCE_FILES} )# ${PROJECT_NAME} WIN32 ${SOURCE_FILES}

#Qt5::Core Qt5::Quick
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Network)

#target_link_libraries(${PROJECT_NAME} ${LIBZIPPP})
#target_link_libraries(${PROJECT_NAME} ${LIBZIPPP_PATH}/lib/libzippp.a)
