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
        Model/Date.h
        Model/Date.cpp
        Model/ActivityTime.h
        Model/ActivityTime.cpp
        Model/Activity.h
        Model/Activity.cpp
        Model/ActivityVector.cpp
        Model/ActivityVector.h
        Model/ActivityTime.h
        Model/ActivityTime.cpp)

set(TEST_SOURCE_FILES Test/ActivityTimeTest.cpp Test/DateTest.cpp Test/ActivityVectorTest.cpp)

add_executable(ActivityTracker main.cpp ${PROJECT_SOURCES}
        View/MainWindowView.cpp
        View/MainWindowView.h
        View/MainWindowView.h
        ShowActivitiesController.cpp
        ShowActivitiesController.h
        showactivities.ui

        Controller/insertactivitycontroller.cpp
        Controller/insertactivitycontroller.h
        Controller/insertactivitycontroller.ui
        Controller/mainwindow.cpp
        Controller/mainwindow.ui
        Controller/mainwindow.h)

add_executable(ActivityTrackerTesting ${TEST_SOURCE_FILES} RunTests.cpp ${PROJECT_SOURCES})

target_link_libraries(ActivityTracker PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(ActivityTrackerTesting gtest gtest_main)