cmake_minimum_required(VERSION 3.1)

project(SmallGameEngine)

# Set options
set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
set(SFML_STATIC_LIBRARIES FALSE CACHE BOOL "Choose whether SFML is linked statically or not.")
set(SMALLGAMEENGINE_STATIC_STD_LIBS FALSE CACHE BOOL "Use statically linked standard/runtime libraries? This option must match the one used for SFML.")

# Make sure that the runtime library gets link statically
if(SMALLGAMEENGINE_STATIC_STD_LIBS)
	if(NOT SFML_STATIC_LIBRARIES)
		message("\n-> If you check SMALLGAMEENGINE_STATIC_STD_LIBS, you also need to check SFML_STATIC_LIBRARIES.")
		message("-> It would lead to multiple runtime environments which result in undefined behavior.\n")
	elseif(WIN32 AND MSVC)
		# Change all MSVC compiler flags to /MT
		foreach(flag CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE)
			if(${flag} MATCHES "/MD")
			string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
			endif()
		endforeach()
	elseif(CMAKE_COMPILER_IS_GNUCXX)
		# Note: Doesn't work for TDM compiler, since it's compiling the runtime libs statically by default
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
	endif()
endif()

# SmallGameEngine uses C++17 features
set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Output an error if SFML wasn't found
if(NOT SFML_FOUND)
	message("\n-> SFML libraries were not found. Set SFML_DIR to SFML's CMake Config path (generally located in \"lib/cmake/SFML\").")
	message("-> Make sure the SFML libraries with the same configuration (Release/Debug, Static/Dynamic) exist.\n")
endif()

# Add the source files
set(SOURCES
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

# Tell CMake to build a executable
add_executable(SmallGameEngine ${SOURCES})

# Link SFML
target_link_libraries(SmallGameEngine sfml-graphics)

# Install executable
install(TARGETS SmallGameEngine
		RUNTIME DESTINATION .)

# Install game data
install(DIRECTORY bin/img
		DESTINATION .)
