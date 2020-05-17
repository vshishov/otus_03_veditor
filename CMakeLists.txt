cmake_minimum_required(VERSION 3.2)

IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set(VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
ELSE()  
    set(VERSION 0.0.1)
ENDIF()

project(veditor VERSION ${VERSION})

set(EXEC_NAME ${CMAKE_PROJECT_NAME})
set(TEST_NAME gtest_${CMAKE_PROJECT_NAME})

message("CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}")

find_package(GTest REQUIRED)
find_package(Threads)
find_package(Doxygen COMPONENTS dot)

set(SRC_PATH "src/")
set(TEST_PATH "test/")
include_directories("inc/")

add_executable(${EXEC_NAME} ${SRC_PATH}/main.cpp)

add_executable(${TEST_NAME} 
    ${TEST_PATH}/main_test.cpp     
)

# if(DOXYGEN_FOUND)
#   configure_file(
#     ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
#     ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
#     @ONLY)
#   add_custom_target(
#     html
#     ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../
#     COMMENT "Creating HTML documentation with Doxygen" VERBATIM)
# endif()

set_target_properties(${EXEC_NAME} ${TEST_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(${TEST_NAME}
    ${GTEST_LIBRARIES} 
    ${CMAKE_THREAD_LIBS_INIT}
)

if (MSVC)
    target_compile_options(${EXEC_NAME} PRIVATE /W4)
    target_compile_options(${TEST_NAME} PRIVATE /W4)
else ()
    target_compile_options(${EXEC_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
    target_compile_options(${TEST_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

install(TARGETS ${EXEC_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT wladimir.shishov@gmail.com)

include(CPack)

enable_testing()

add_test(${TEST_NAME} ${TEST_NAME})