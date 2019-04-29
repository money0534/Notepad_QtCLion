cmake_minimum_required(VERSION 3.12)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project(XmlConverter)

set(CMAKE_CXX_STANDARD 11)

# Qt
# Set this to your Qt installation
#set(CMAKE_PREFIX_PATH C:/Qt/Qt5.12.0/5.12.0/msvc2017_64)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_BUILD_TYPE )

#src 1、当.h与.cpp不在同一路径中时，需要分别包含进来（在同一目录时可省略.h） 2、.ui文件（经测试，在CLion中.ui文件需要与对应的class在相同的路径内）
set(SOURCE_FILES src/main.cpp)
#resources 1、.qrc文件 2、存放图片资源文件等
set(RESOURCE_FILES resources/notepad.qrc)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Xml REQUIRED)

#图片等资源文件的文件夹包含进来
include_directories(resources/images)

#WIN32 indicates that the executable (when compiled on windows) is a windows app (using WinMain) not a console app (using main).
#增加WIN32 表明是一个windows桌面程序，而非console app不显示cmd window
#参考 https://cmake.org/pipermail/cmake/2008-March/020576.html
add_executable(${PROJECT_NAME}  ${SOURCE_FILES} ${RESOURCE_FILES})#WIN32

#Qt5::Core Qt5::Quick
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Xml)


