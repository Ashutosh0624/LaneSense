cmake_minimum_required(VERSION 3.16)

project(AutoDrive VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appAutoDrive
    main.cpp
)

qt_add_qml_module(appAutoDrive
    URI AutoDrive
    VERSION 1.0
    QML_FILES
    main.qml
        SOURCES sensordatamodel.h sensordatamodel.cpp
        SOURCES adasmanager.h adasmanager.cpp
        SOURCES ISafetyStrategy.h
        SOURCES distancewarningstrategy.h distancewarningstrategy.cpp
        SOURCES laneoffsetwarning.h laneoffsetwarning.cpp
        SOURCES blindspotstrategy.h blindspotstrategy.cpp
        SOURCES trafficsignstrategy.h trafficsignstrategy.cpp
        SOURCES overspeedstrategy.h overspeedstrategy.cpp
        SOURCES combinedsafetystrategy.h combinedsafetystrategy.cpp
        SOURCES strategyfactory.h strategyfactory.cpp
        QML_FILES LiveDataDisplay.qml
        QML_FILES Speedometer.qml
        QML_FILES WarningPanel.qml
        QML_FILES TrafficSignDisplay.qml
        QML_FILES LaneOffSetDisplay.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appAutoDrive PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appAutoDrive
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appAutoDrive
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appAutoDrive
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
