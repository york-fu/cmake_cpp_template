cmake_minimum_required(VERSION 3.0.0)
project(timer VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(./src)
aux_source_directory(./src SRCS)
aux_source_directory(./example EXAMPLE_SRCS)

add_executable(${PROJECT_NAME}_example ${SRCS} ${EXAMPLE_SRCS})
target_link_libraries(${PROJECT_NAME}_example pthread)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
