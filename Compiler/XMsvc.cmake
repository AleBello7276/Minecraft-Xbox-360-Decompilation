# @AleBello7276
# CMake toolchain file for the Xbox 360 MSVC compiler
# Makes CMake able to use the Xbox 360 MSVC compiler

# a lot of this is based on:
# https://github.com/billynothingelse/cmake-xenon-toolchain


set(XDK_TOOLS ${CMAKE_CURRENT_SOURCE_DIR}/Compiler/bin/win32)


set(CMAKE_SYSTEM_NAME Xbox360)
set(CMAKE_CROSSCOMPILING OFF)
set(XENON true)


# XDK includes and libs
set(XBOX360_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/Compiler/include/xbox")
set(XBOX360_LIBRARY_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/Compiler/lib/xbox")
#set(XBOX360_CRT_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/Compiler/crt")
include_directories(BEFORE ${XBOX360_INCLUDE_DIRS})
#include_directories(${XBOX360_CRT_DIRS})

set(CMAKE_EXECUTABLE_SUFFIX ".xex")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_SUFFIX ".lib")
set(CMAKE_SHARED_LIBRARY_SUFFIX ".dll")


set(CMAKE_LINK_LIBRARY_FLAG "")
set(CMAKE_LINK_LIBRARY_SUFFIX ".lib")
set(CMAKE_LINK_LIBRARY_FILE "<LIBRARY>")
set(CMAKE_C_COMPILE_OBJECT "<CMAKE_C_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -c <SOURCE> /Fo<OBJECT>")
set(CMAKE_CXX_COMPILE_OBJECT "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -c <SOURCE> /Fo<OBJECT>")
set(CMAKE_CXX_LINK_EXECUTABLE "<CMAKE_LINKER> <LINK_FLAGS> <OBJECTS> /OUT:<TARGET> <LINK_LIBRARIES>")



set(CMAKE_C_COMPILER ${XDK_TOOLS}/cl.exe)
set(CMAKE_CXX_COMPILER ${XDK_TOOLS}/cl.exe)
set(CMAKE_ASM_COMPILER ${XDK_TOOLS}/ml.exe)
set(CMAKE_LINKER ${XDK_TOOLS}/link.exe)
message(STATUS "------------")
message(STATUS "Using Xbox 360 MSVC compiler")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "Assembler: ${CMAKE_ASM_COMPILER}")
message(STATUS "Linker: ${CMAKE_LINKER}")
message(STATUS "------------")


set(CMAKE_C_COMPILER_ID "Xbox360MSVC")
set(CMAKE_CXX_COMPILER_ID "Xbox360MSVC")

# Skip compiler detection info
set(CMAKE_C_COMPILER_FORCED true)
set(CMAKE_CXX_COMPILER_FORCED true)
set(CMAKE_ASM_COMPILER_FORCED true)

# Make the Xbox 360 XDK our only focus
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CXX_COMMON_FLAGS
    /W3             # Set warning level to 3
    /wd4996         # Ignore deprecation warnings
    /GF             # Enable read-only string pooling
    /GS-			# Enable buffer security checks
    /Gm             # Enable minimal rebuild
    /fp:fast		# Fast floating point (less predictable)
    /Os				# Favour small code
    /Gy             # Enable function level linking
    /Zc:wchar_t-    # Set wchar_t as an interal type
    /Zi             # Enable debug info
)
string(REPLACE ";" " " CXX_COMMON_FLAGS "${CXX_COMMON_FLAGS}")

set(CMAKE_CXX_FLAGS "${CXX_COMMON_FLAGS}" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG "${CXX_COMMON_FLAGS} /MTd" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "${CXX_COMMON_FLAGS} /MT /Ox" CACHE STRING "" FORCE)

# MSVC Common linker flags
# fix this i guess later
set(MSVC_LINKER_FLAGS "/NOLOGO /INCREMENTAL /manifest:no /LIBPATH:${XBOX360_LIBRARY_DIRS}")

set(CMAKE_STATIC_LINKER_FLAGS "${MSVC_LINKER_FLAGS}")
set(CMAKE_MODULE_LINKER_FLAGS "${MSVC_LINKER_FLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS "${MSVC_LINKER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${MSVC_LINKER_FLAGS}")


set(XBOX360_DEFINITIONS
	-D_XBOX
	-DXBOX
	-D_MBCS
)
add_definitions(${XBOX360_DEFINITIONS})


set(CMAKE_CXX_STANDARD_LIBRARIES "")


# will it work, idk lol
#
#function(Xcustom_compiler_flags flags)
#   set(CMAKE_CXX_FLAGS ${flags})
#endfunction()
#
#function(Xcustom_linker_flags flags)
#    set(CMAKE_STATIC_LINKER_FLAGS "${flags}")
#    set(CMAKE_MODULE_LINKER_FLAGS "${flags}")
#    set(CMAKE_SHARED_LINKER_FLAGS "${flags}")
#    set(CMAKE_EXE_LINKER_FLAGS "${flags}")
#endfunction()