# opencv-action

[![test](https://github.com/cvpkg/opencv-action/actions/workflows/test.yml/badge.svg)](https://github.com/cvpkg/opencv-action/actions/workflows/test.yml)

Install opencv on Github Actions, provided as re-usable "configure-build-install-export-import" steps.

## Use in workflows yml
action.yml:
```yml
- name: Install opencv
  uses: cvpkg/opencv-action@v0.1
  with:
    opencv_tag: '4.6.0' # Optional. Default is '4.6.0'. An env var 'opencv_tag' will be defined.
    BUILD_LIST: 'core,imgcodecs,imgproc' # Optional. Default is 'core,imgcodecs,imgproc'. The opencv modules(libraries, components) to be build, separated with `,` and no spaces.
    BUILD_SHARED_LIBS: 'OFF' # Optional. Default is 'OFF'. Build shared opencv librarires, should be "ON" or "OFF".
    BUILD_WITH_STATIC_CRT: 'OFF' # Optional. Default is 'OFF'. Build with static C Runtime Library?(only when MSVC), should be "ON" or "OFF"
```

## Use in CMakeLists.txt
To set the correct paths, you could add to your `CMakeLists.txt`:
```cmake
if(DEFINED ENV{GITHUB_ACTIONS} AND DEFINED ENV{GITHUB_WORKSPACE})
  set(ARTIFACTS_DIR "$ENV{GITHUB_WORKSPACE}/artifacts")
  if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(OpenCV_DIR "${ARTIFACTS_DIR}/opencv/$ENV{opencv_tag}/windows-x64")
  elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(OpenCV_DIR "${ARTIFACTS_DIR}/opencv/$ENV{opencv_tag}/linux-x64/lib/cmake/opencv4")
  elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(OpenCV_DIR "${ARTIFACTS_DIR}/opencv/$ENV{opencv_tag}/mac-x64/lib/cmake/opencv4")
  endif()
  find_package(OpenCV REQUIRED)
endif()
```

## References
- [opencv](https://github.com/opencv/opencv)
