cmake_minimum_required(VERSION 3.0.0)
project(template VERSION 0.1.0)

option(EXAMPLE "build example" ON)

include(CTest)
enable_testing()

include_directories(./)
aux_source_directory(./ SRCS)

add_library(${PROJECT_NAME} ${SRCS})
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ./include)

if(EXAMPLE)
  add_subdirectory(example)
endif(EXAMPLE)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
