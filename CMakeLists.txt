project(LPC)
cmake_minimum_required(VERSION 2.8)
set(QT_USE_IMPORTED_TARGETS TRUE)
find_package(Qt4 4.7.1 REQUIRED QtCore QtGui QtSql)

include(${QT_USE_FILE})

add_subdirectory(src)

add_executable(lpc main.cxx)
target_link_libraries(lpc LPCCore ${QT_LIBRARIES})

install(TARGETS lpc
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
)