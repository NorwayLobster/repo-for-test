cmake_minimum_required(VERSION 3.5)
project(utilities)
set(SRC 
		src/utilities.cc
		src/configure.cc
)
add_library(${PROJECT_NAME} SHARED ${SRC})
add_library(sub::utilities ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib) 
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION include) 
