project(GladeTest)

cmake_minimum_required(VERSION 2.6)


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(GTKMM gtkmm-3.0)



add_definitions(${GTK3_CFLAGS_OTHER})

link_directories(${GTK3_LIBRARY_DIRS} ${GTKMM_LIBRARY_DIRS})


include_directories(gladeTest  ${GTK3_INCLUDE_DIRS}  ${GTKMM_INCLUDE_DIRS})
add_executable(gladeTest main.cpp)

target_link_libraries(gladeTest ${GTK3_LIBRARIES} ${GTKMM_LIBRARY_DIRS})
