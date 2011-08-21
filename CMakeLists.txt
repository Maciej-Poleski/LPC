project(LPC)
cmake_minimum_required(VERSION 2.8)
set(QT_USE_IMPORTED_TARGETS TRUE)
find_package(Qt4 4.7.1 REQUIRED QtCore QtGui QtSql)

include(${QT_USE_FILE})

######## GLOBAL CONFIGURATION ##################################################

if(MSVC)
    add_definitions(-DWIN32_EXPORT="__declspec(dllexport)")
else(MSVC)
    add_definitions(-DWIN32_EXPORT="")
endif(MSVC)

######## GLOBAL CONFIGURATION END ##############################################

add_subdirectory(src)

add_executable(lpc main.cxx)
target_link_libraries(lpc LPCCore ${QT_LIBRARIES})

install(TARGETS lpc
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

set_target_properties(lpc PROPERTIES INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib
                                     BUILD_WITH_INSTALL_RPATH TRUE)