cmake_minimum_required(VERSION 3.7)
project(SuperSerialPort)

set(CMAKE_CXX_STANDARD 11)


# Qt
# Set this to your Qt installation
set(CMAKE_PREFIX_PATH C:\\Qt\\Qt5.12.0\\5.12.0\\mingw73_64)


#参见 https://cmake.org/cmake/help/v3.0/variable/CMAKE_AUTOMOC.html
#When this property is set ON, CMake will scan the source files at build time and invoke moc accordingly.
set(CMAKE_AUTOMOC ON)
#参见 https://cmake.org/cmake/help/v3.0/variable/CMAKE_AUTOUIC.html
#When this property is ON, CMake will scan the source files at build time and invoke uic accordingly.
#If an #include statement like #include "ui_foo.h" is found in foo.cpp, a foo.ui file is expected next to foo.cpp,
#and uic is run on the foo.ui file.
#简而言之就是自动根据foo.ui创建，自动运行uic
set(CMAKE_AUTOUIC ON)
#参见 https://cmake.org/cmake/help/v3.0/variable/CMAKE_AUTORCC.html
#When this property is ON, CMake will handle .qrc files added as target sources at build time and invoke rcc accordingly.
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


#src 1、当.h与.cpp不在同一路径中时，需要分别包含进来（在同一目录时可省略.h） 2、.ui文件（经测试，在CLion中.ui文件需要与对应的class在相同的路径内）
set(SOURCE_FILES src/main.cpp
        src/console.cpp
        src/mainwindow.cpp src/mainwindow.ui
        src/settingsdialog.cpp src/settingsdialog.ui src/InitThread.cpp src/InitThread.h src/AppConfig.h)

#resources 1、.qrc文件 2、存放图片资源文件等
set(RESOURCE_FILES resources/res.qrc resources/release.rc)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5SerialPort REQUIRED)

include_directories(resources/images)

add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES} ${RESOURCE_FILES})#WIN32

#Qt5::Core Qt5::Quick
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::SerialPort)
