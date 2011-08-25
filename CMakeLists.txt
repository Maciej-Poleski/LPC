project(LPC)
cmake_minimum_required(VERSION 2.8.5 FATAL_ERROR)

######## GLOBAL CONFIGURATION ##################################################

set(QT_USE_IMPORTED_TARGETS TRUE)

set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_PATCH "2")
set(VERSION_STRING ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

include(GNUInstallDirs)
include(InstallRequiredSystemLibraries)

######## GLOBAL CONFIGURATION END ##############################################

find_package(Qt4 4.7.1 REQUIRED QtCore QtGui QtSql QtMain)

include(${QT_USE_FILE})
include_directories(${CMAKE_BINARY_DIR})

configure_file(config.h.in config.h)

add_subdirectory(src)

add_executable(lpc WIN32 main.cxx)
target_link_libraries(lpc LPCCore ${QT_LIBRARIES})

install(TARGETS lpc
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

set_target_properties(lpc PROPERTIES INSTALL_RPATH ${CMAKE_INSTALL_FULL_LIBDIR}
                                     BUILD_WITH_INSTALL_RPATH TRUE)

