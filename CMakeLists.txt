cmake_minimum_required(VERSION 3.15)

project(SmallGameEngine LANGUAGES CXX)

# Set options
set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
set(SFML_STATIC_LIBRARIES FALSE CACHE BOOL "Choose whether SFML is linked statically or not.")
set(SMALLGAMEENGINE_STATIC_STD_LIBS FALSE CACHE BOOL "Use statically linked standard/runtime libraries? This option must match the one used for SFML.")

# SmallGameEngine uses C++17 features
set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Tell CMake to build a executable
add_executable(SmallGameEngine 
	src/main.cpp
	src/Application.hpp
	src/Application.cpp
	src/State.hpp
	src/State.cpp
	src/StateMachine.hpp
	src/StateMachine.cpp
	src/IntroState.hpp
	src/IntroState.cpp
	src/MenuState.hpp
	src/MenuState.cpp
	src/PlayState.hpp
	src/PlayState.cpp
)

# Make sure that the runtime library gets linked statically
if(SMALLGAMEENGINE_STATIC_STD_LIBS)
	if(NOT SFML_STATIC_LIBRARIES)
		message("\n-> If you check SMALLGAMEENGINE_STATIC_STD_LIBS, you also need to check SFML_STATIC_LIBRARIES.")
		message("-> It would lead to multiple runtime environments which results in undefined behavior.\n")
	elseif(WIN32 AND MSVC)
		set_property(TARGET SmallGameEngine PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
	elseif(CMAKE_COMPILER_IS_GNUCXX)
		# Note: Doesn't work for TDM compiler, since it's compiling the runtime libs statically by default
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
	endif()
endif()

# Link SFML
target_link_libraries(SmallGameEngine sfml-graphics)

# Install executable
install(TARGETS SmallGameEngine
		RUNTIME DESTINATION .)

# Install game data
install(DIRECTORY bin/img
		DESTINATION .)