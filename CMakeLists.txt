cmake_minimum_required(VERSION 3.5)

project(ActivityTracker)

add_subdirectory(Test/lib/googletest-master)
include_directories(Test/lib/googletest-master/googletest/include)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

#find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        Body/Date.h
        Body/Date.cpp
        Body/ActivityTime.h
        Body/ActivityTime.cpp
        Body/Activity.h
        Body/Activity.cpp
        Body/ActivityTime.h
        Body/ActivityTime.cpp Body/ActivityList.cpp Body/ActivityList.h)

set(QT_PROJECT_SOURCES
        GUI/InsertActivityController.cpp
        GUI/InsertActivityController.h
        GUI/insertactivityController.ui
        GUI/MainWindow.cpp
        GUI/mainwindow.ui
        GUI/MainWindow.h GUI/activitytable.cpp GUI/activitytable.h GUI/activitytable.ui)

set(TEST_SOURCE_FILES Test/ActivityTimeTest.cpp Test/DateTest.cpp Test/ActivityTest.cpp Test/ActivityListTest.cpp)

add_executable(ActivityTracker main.cpp ${PROJECT_SOURCES} ${QT_PROJECT_SOURCES})

add_executable(ActivityTrackerTesting ${TEST_SOURCE_FILES} RunTests.cpp ${PROJECT_SOURCES})

target_link_libraries(ActivityTracker PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(ActivityTrackerTesting gtest gtest_main)