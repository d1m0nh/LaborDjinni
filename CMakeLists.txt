cmake_minimum_required(VERSION 3.1)
project(GreeterLib)

#
# Setup the directories
#
set(CPP_INCLUDE_DIR include)
set(CPP_SRC_DIR android/Greeter/app/src/main/cpp)
set(DJINNI_DIR deps/djinni)
set(DJINNI_SUPPORT_DIR ${DJINNI_DIR}/support-lib)
set(DJINNI_SUPPORT_JNI_DIR ${DJINNI_SUPPORT_DIR}/jni)
set(GENERATED_SRC_DIR ${CPP_SRC_DIR}/djinni)
set(GENERATED_SRC_CPP_DIR ${GENERATED_SRC_DIR})
set(GENERATED_SRC_JNI_DIR ${GENERATED_SRC_DIR}/jni)

#
# Setup the source and include directories for the ${PROJECT_NAME} lib
#
set(INCLUDE_DIRS
    ${CPP_INCLUDE_DIR}
    ${GENERATED_SRC_CPP_DIR}
    ${DJINNI_SUPPORT_DIR}
    )
 
set(SRC_FILES "")

#
# Recursively aggregate the C++ sources
#
file(GLOB_RECURSE CPP_HEADERS
    ${CPP_INCLUDE_DIR}/*.hpp
    ${CPP_INCLUDE_DIR}/*.h
    ${CPP_SRC_DIR}/*.hpp
    ${CPP_SRC_DIR}/*.h
)
file(GLOB_RECURSE CPP_SRC
    ${CPP_SRC_DIR}/*.cpp
)
file(GLOB_RECURSE CPP_GENERATED_HEADERS
    ${GENERATED_SRC_CPP_DIR}/*.hpp
    ${GENERATED_SRC_CPP_DIR}/*.h
)
file(GLOB_RECURSE CPP_GENERATED_SRC
    ${GENERATED_SRC_CPP_DIR}/*.cpp
)

#
# Append C++ sources to the library's source files
#
list(APPEND SRC_FILES
    ${CPP_HEADERS}
    ${CPP_SRC}
    ${CPP_GENERATED_HEADERS}
    ${CPP_GENERATED_SRC}
)

#
# For Android we're doing something a little different. We're going to be
# adding the java generated source files separated using Gradle, but use
# CMake to link against the JNI C++ source files.
#
if (ANDROID)
    file(GLOB_RECURSE JNI_GENERATED_HEADERS
        ${GENERATED_SRC_JNI_DIR}/*.h
        ${GENERATED_SRC_JNI_DIR}/*.hpp
    )
    file(GLOB_RECURSE JNI_GENERATED_SRC
        ${GENERATED_SRC_JNI_DIR}/*.cpp
    )
    list(APPEND SRC_FILES ${JNI_GENERATED_SRC})
    list(APPEND INCLUDE_DIRS ${DJINNI_SUPPORT_JNI_DIR} ${GENERATED_SRC_JNI_DIR})
endif(ANDROID)

#
# For both iOS and Android we're going to generate a shared library. On iOS
# this will be the resulting binary inside the ${PROJECT_NAME}.framework. On
# Android this will create a lib${PROJECT_NAME}.so shared library.
#
add_library(${PROJECT_NAME} SHARED ${SRC_FILES})

#
# We're going to link the ${PROJECT_NAME} library against the djinni support
# library to make sure we're not missing any symbols.
#
add_subdirectory(${DJINNI_DIR})
target_link_libraries(${PROJECT_NAME} djinni)

#
# Now let's add the include directories list we've been appending to to CMake's
# list of include directories.
#
include_directories(${INCLUDE_DIRS})
