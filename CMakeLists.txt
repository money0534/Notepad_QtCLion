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
set(SOURCE_FILES
#        src/main.cpp
        libmsc/main.c
        src/thread.h
        src/Logger.cpp src/Logger.h
        src/Task.cpp src/Task.h
        src/ProgressDialog.cpp src/ProgressDialog.h
        src/maindialog.cpp src/maindialog.h src/maindialog.ui
        src/mainwindow.cpp src/mainwindow.h src/mainwindow.ui
        src/PlayAudio.h)
#resources 1、.qrc文件 2、存放图片资源文件等
set(RESOURCE_FILES resources/notepad.qrc resources/release.rc)

#quazip lib
set(QUA_LIB
        libzip/crypt.h
        libzip/ioapi.h
        libzip/JlCompress.h
        libzip/quaadler32.h
        libzip/quachecksum32.h
        libzip/quacrc32.h
        libzip/quagzipfile.h
        libzip/quaziodevice.h
        libzip/quazip.h
        libzip/quazip_global.h
        libzip/quazipdir.h
        libzip/quazipfile.h
        libzip/quazipfileinfo.h
        libzip/quazipnewinfo.h
        libzip/unzip.h
        libzip/zconf.h
        libzip/zip.h
        libzip/zlib.h)

#科大讯飞 语音合成库
set(MSC_LIB
        libmsc/qtts.h
        libmsc/msp_types.h
        libmsc/msp_errors.h
        libmsc/msp_cmn.h)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Multimedia REQUIRED)

#图片等资源文件的文件夹包含进来
include_directories(resources/images)

# WIN32
# 增加下载失败提示
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${RESOURCE_FILES} ${QUA_LIB} ${MSC_LIB})# ${PROJECT_NAME} WIN32 ${SOURCE_FILES}

#Qt5::Core Qt5::Quick
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Network Qt5::Multimedia)


#confusing???
#if dll name is quazipd.dll then executable looks for quaziprelease.dll,
#while if dll name is quazipd.dll then executable looks for quazipd.dll
#it depends on the dll name you compiled in QtCreator,so it explains the strange phenomenon above

#dll debug https://cmake.org/cmake/help/v3.0/command/target_link_libraries.html
target_link_libraries(${PROJECT_NAME} debug ${PROJECT_SOURCE_DIR}/libzip/Debug/quazipd.dll)

#-L声明路径？解决错误：x86_64-w64-mingw32/bin/ld.exe: cannot find -llibzip/Release/quazip.dll
#general:for all configs;debug: debug;optimized: dll builds except debug
target_link_libraries(${PROJECT_NAME} optimized ${PROJECT_SOURCE_DIR}/libzip/Release/quazip.dll)

#讯飞语音
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libmsc/msc_x64.dll)


#拷贝讯飞dll库
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD        # Adds a post-build event to ${PROJECT_NAME}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${PROJECT_SOURCE_DIR}/libmsc/msc_x64.dll"      # <--this is in-file
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)                 # <--this is out-file path

#拷贝 /libmsc/msc文件夹到可执行文件路径（输出路径）
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD        # Adds a post-build event to ${PROJECT_NAME}
        COMMAND ${CMAKE_COMMAND} -E copy_directory  # which executes "cmake - E copy_if_different..."
        "${PROJECT_SOURCE_DIR}/libmsc/jets"      # <--this is in-file
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)

#参考 https://cmake.org/cmake/help/v3.0/manual/cmake-generator-expressions.7.html
#查看预定义变量<VAR>
#根据配置Debug/Release配置 选择拷贝quazip dll库
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/libzip/$<CONFIG>"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)

message("${PROJECT_NAME} build succeed.")