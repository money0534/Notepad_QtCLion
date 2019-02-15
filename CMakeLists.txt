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

set(QUA_LIB
        lib/crypt.h
        lib/ioapi.h
        lib/JlCompress.h
        lib/quaadler32.h
        lib/quachecksum32.h
        lib/quacrc32.h
        lib/quagzipfile.h
        lib/quaziodevice.h
        lib/quazip.h
        lib/quazip_global.h
        lib/quazipdir.h
        lib/quazipfile.h
        lib/quazipfileinfo.h
        lib/quazipnewinfo.h
        lib/unzip.h
        lib/zconf.h
        lib/zip.h
        lib/zlib.h
        )

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

#图片等资源文件的文件夹包含进来
include_directories(resources/images)

# WIN32
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${RESOURCE_FILES} ${QUA_LIB})# ${PROJECT_NAME} WIN32 ${SOURCE_FILES}

#Qt5::Core Qt5::Quick
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Network)


#dll debug
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/lib/quazip.dll)
#static lib debug
#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/lib/libquazip.a)
