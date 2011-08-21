project(LPC)
cmake_minimum_required(VERSION 2.8)

######## GLOBAL CONFIGURATION ##################################################

set(QT_USE_IMPORTED_TARGETS TRUE)

set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_PATCH "1")
set(VERSION_STRING ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

set(CPACK_PACKAGE_NAME nazwa_pakietu)
set(CPACK_PACKAGE_VENDOR dystrybutor_pakietu)
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
set(CPACK_PACKAGE_DESCRIPTION_FILE plik_z_opisem.txt)
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY krotki_opis_projektu)
set(CPACK_PACKAGE_FILE_NAME LPC-${VERSION_STRING})
set(CPACK_PACKAGE_INSTALL_DIRECTORY LPC)
set(CPACK_RESOURCE_FILE_LICENSE plik_z_licencja.txt)
set(CPACK_RESOURCE_FILE_README plik_readme.txt)
set(CPACK_RESOURCE_FILE_WELCOME plik_welcome.txt)
set(CPACK_MONOLITHIC_INSTALL TRUE)
set(CPACK_PACKAGE_EXECUTABLES lpc;LPC)
set(CPACK_STRIP_FILES TRUE)

include(CPack)

######## GLOBAL CONFIGURATION END ##############################################

find_package(Qt4 4.7.1 REQUIRED QtCore QtGui QtSql QtMain)

include(${QT_USE_FILE})

configure_file(config.h.in config.h)

add_subdirectory(src)

add_executable(lpc WIN32 main.cxx)
target_link_libraries(lpc LPCCore ${QT_LIBRARIES})

install(TARGETS lpc
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

set_target_properties(lpc PROPERTIES INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib
                                     BUILD_WITH_INSTALL_RPATH TRUE)