cmake_minimum_required(VERSION 3.19)
project(QtChat LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

set(SOURCES
    main.cpp
    mainwindow.cpp
)

set(HEADERS
    mainwindow.h
)

set(UIS
    mainwindow.ui
)

qt_add_executable(QtChat
    WIN32 MACOSX_BUNDLE
        ${SOURCES}
        ${HEADERS}
        ${UIS}

)

target_link_libraries(QtChat
    PRIVATE Qt::Core Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS QtChat
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET QtChat
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
