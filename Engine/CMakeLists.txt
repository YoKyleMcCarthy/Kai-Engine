# Engine (Shared lib)
project(Engine VERSION 0.0.1)

# get all cpp-files
file(GLOB_RECURSE SRC_FILES src/*.cpp CMAKE_CONFIGURE_DEPENDS)
add_library(${PROJECT_NAME} ${SRC_FILES})

# define symbols
add_definitions(-DKAI_EXPORT)
add_definitions(-D_DEBUG)

# MacOS
if(APPLE)
    target_link_libraries(${PROJECT_NAME} libSDL3.0.dylib libSDL3_image.0.2.0.dylib )
    target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/Mac/includes)
    target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/Mac/libs)
endif(APPLE)

# Windows Need to change for later...
if(WIN32)
    target_link_libraries(${PROJECT_NAME} SDL3 SDL3_image python313_d.lib)
    target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/Windows/includes)
    target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/Windows/libs)
endif(WIN32)



#Precompiled Headers
target_precompile_headers(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/pch.hpp)

#Add includce directory
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
