cmake_minimum_required(VERSION 3.17)

set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS VERSION)
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" PROJECT_VERSION)
project(wagh VERSION ${PROJECT_VERSION} LANGUAGES CXX)

include(GNUInstallDirs)


add_library(wagh)

set(VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(VERSION_PATCH ${PROJECT_VERSION_PATCH})
configure_file(include/wagh/version.hpp.in 
               include/wagh/version.hpp)

target_include_directories(wagh PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)

target_sources(wagh PRIVATE
    src/exception.cpp
    src/decoding_error.cpp
    src/instruction_iterator.cpp
)

if(BUILD_SHARED_LIBS)
    set_target_properties(wagh PROPERTIES C_VISIBILITY_PRESET hidden)
    target_compile_definitions(wagh
        INTERFACE WAGH_USE_DYNAMIC=1
        PRIVATE WAGH_BUILD_DYNAMIC=1
    )
endif()


target_include_directories(wagh PUBLIC
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
install(
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
              "${CMAKE_CURRENT_BINARY_DIR}/include/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    PATTERN "**/*.in" EXCLUDE
)
install(TARGETS wagh EXPORT wagh)
install(EXPORT wagh
    DESTINATION "${CMAKE_INSTALL_DATADIR}/wagh"
    NAMESPACE wagh::
    FILE wagh-config.cmake
)
export(EXPORT wagh
    NAMESPACE wagh::
    FILE wagh-config.cmake
)

