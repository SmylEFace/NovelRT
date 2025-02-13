include(FetchContent)

FIND_PACKAGE(ZLIB REQUIRED)

FetchContent_Declare(libpng
        URL https://github.com/glennrp/libpng/archive/refs/tags/v1.6.35.zip
        URL_HASH SHA512=65df0c2befa06d0b9ec0c6395a73987fb071754610d328b94ce01a6b8f7161c71ce97ddf0e0a8e28c2e50019a103368c4b4f0b63bd8cd75e168b32f940922d96

        PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
        TMP_DIR "${CMAKE_CURRENT_BINARY_DIR}/tmp"
        STAMP_DIR "${CMAKE_CURRENT_BINARY_DIR}/stamp"
        DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/dl"
        SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/src"
        SUBBUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/build"
        BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/bin"
        INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/inst"
        LOG_DIR "${CMAKE_CURRENT_BINARY_DIR}/log"
)

if(CMAKE_APPLE_SILICON_PROCESSOR STREQUAL "arm64")
        set(PNG_ARM_NEON "off" CACHE STRING "" FORCE)
endif()

set(PNG_SHARED OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(libpng)

set_property(TARGET png_static PROPERTY POSITION_INDEPENDENT_CODE ON)
set(NOVELRT_PNG_SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/src" CACHE STRING "" FORCE)
set(NOVELRT_PNGLIBCONFG_SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/bin" CACHE STRING "" FORCE)
set(PNG_PNG_INCLUDE_DIR "${NOVELRT_PNG_SOURCE_DIR};${NOVELRT_PNGLIBCONFG_SOURCE_DIR}" CACHE STRING "Set PNG include dirs" FORCE)
set(PNG_LIBRARY "png_static" CACHE STRING "Set PNG libraries" FORCE)
