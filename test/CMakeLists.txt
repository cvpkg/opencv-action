cmake_minimum_required(VERSION 3.15)
project(use_opencv_example)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

if(DEFINED ENV{GITHUB_ACTIONS} AND DEFINED ENV{GITHUB_WORKSPACE})
  set(ARTIFACTS_DIR "$ENV{GITHUB_WORKSPACE}/artifacts")
  if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(OpenCV_DIR "${ARTIFACTS_DIR}/opencv/$ENV{opencv_tag}/windows-x64")
  elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(OpenCV_DIR "${ARTIFACTS_DIR}/opencv/$ENV{opencv_tag}/linux-x64/lib/cmake/opencv4")
  elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(OpenCV_DIR "${ARTIFACTS_DIR}/opencv/$ENV{opencv_tag}/mac-x64/lib/cmake/opencv4")
  endif()
  message(STATUS ">>> ENV{GITHUB_ACTIONS} is: $ENV{GITHUB_ACTIONS}")
  message(STATUS ">>> ENV{GITHUB_WORKSPACE} is: $ENV{GITHUB_WORKSPACE}")
  message(STATUS ">>> ARTIFACTS_DIR is: ${ARTIFACTS_DIR}")
  message(STATUS ">>> OpenCV_DIR is: ${OpenCV_DIR}")
  if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "!! MSVC_VERSION: ${MSVC_VERSION}")
  endif()
  find_package(OpenCV REQUIRED)
endif()

add_executable(testbed testbed.cpp)
target_link_libraries(testbed
  ${OpenCV_LIBS}
)

