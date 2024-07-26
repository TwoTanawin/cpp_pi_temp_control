cmake_minimum_required(VERSION 3.10)
project(pi_temp_control)

option(ENABLE_COVERAGE "Enable coverage reporting" OFF)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(ENABLE_COVERAGE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 --coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --coverage")

  find_program(LCOV lcov REQUIRED)
  find_program(GENHTML genhtml REQUIRED)

  add_custom_target(coverage
    COMMAND ${LCOV} --directory . --capture --output-file coverage.info
    COMMAND ${LCOV} --remove coverage.info '/usr/*' --output-file coverage.info
    COMMAND ${GENHTML} --demangle-cpp -o coverage coverage.info
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating coverage report"
  )
endif()

# Add the include directory for header files
include_directories(src)

# Add the main executable
add_executable(pi_temp_control src/main.cpp src/PIController.cpp)

# Add the test executable
add_executable(test_pi_controller test/test_pi_controller.cpp src/PIController.cpp)

# Enable testing
enable_testing()
add_test(NAME test_pi_controller COMMAND test_pi_controller)
