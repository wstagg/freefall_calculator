# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wesleystagg/Desktop/c++/freefall_calculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wesleystagg/Desktop/c++/freefall_calculator/build

# Include any dependencies generated for this target.
include CMakeFiles/FreeFall_calculator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FreeFall_calculator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FreeFall_calculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FreeFall_calculator.dir/flags.make

CMakeFiles/FreeFall_calculator.dir/main.cpp.o: CMakeFiles/FreeFall_calculator.dir/flags.make
CMakeFiles/FreeFall_calculator.dir/main.cpp.o: /Users/wesleystagg/Desktop/c++/freefall_calculator/main.cpp
CMakeFiles/FreeFall_calculator.dir/main.cpp.o: CMakeFiles/FreeFall_calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wesleystagg/Desktop/c++/freefall_calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FreeFall_calculator.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FreeFall_calculator.dir/main.cpp.o -MF CMakeFiles/FreeFall_calculator.dir/main.cpp.o.d -o CMakeFiles/FreeFall_calculator.dir/main.cpp.o -c /Users/wesleystagg/Desktop/c++/freefall_calculator/main.cpp

CMakeFiles/FreeFall_calculator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FreeFall_calculator.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wesleystagg/Desktop/c++/freefall_calculator/main.cpp > CMakeFiles/FreeFall_calculator.dir/main.cpp.i

CMakeFiles/FreeFall_calculator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FreeFall_calculator.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wesleystagg/Desktop/c++/freefall_calculator/main.cpp -o CMakeFiles/FreeFall_calculator.dir/main.cpp.s

CMakeFiles/FreeFall_calculator.dir/calculations.cpp.o: CMakeFiles/FreeFall_calculator.dir/flags.make
CMakeFiles/FreeFall_calculator.dir/calculations.cpp.o: /Users/wesleystagg/Desktop/c++/freefall_calculator/calculations.cpp
CMakeFiles/FreeFall_calculator.dir/calculations.cpp.o: CMakeFiles/FreeFall_calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wesleystagg/Desktop/c++/freefall_calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FreeFall_calculator.dir/calculations.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FreeFall_calculator.dir/calculations.cpp.o -MF CMakeFiles/FreeFall_calculator.dir/calculations.cpp.o.d -o CMakeFiles/FreeFall_calculator.dir/calculations.cpp.o -c /Users/wesleystagg/Desktop/c++/freefall_calculator/calculations.cpp

CMakeFiles/FreeFall_calculator.dir/calculations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FreeFall_calculator.dir/calculations.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wesleystagg/Desktop/c++/freefall_calculator/calculations.cpp > CMakeFiles/FreeFall_calculator.dir/calculations.cpp.i

CMakeFiles/FreeFall_calculator.dir/calculations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FreeFall_calculator.dir/calculations.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wesleystagg/Desktop/c++/freefall_calculator/calculations.cpp -o CMakeFiles/FreeFall_calculator.dir/calculations.cpp.s

CMakeFiles/FreeFall_calculator.dir/inputs.cpp.o: CMakeFiles/FreeFall_calculator.dir/flags.make
CMakeFiles/FreeFall_calculator.dir/inputs.cpp.o: /Users/wesleystagg/Desktop/c++/freefall_calculator/inputs.cpp
CMakeFiles/FreeFall_calculator.dir/inputs.cpp.o: CMakeFiles/FreeFall_calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wesleystagg/Desktop/c++/freefall_calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FreeFall_calculator.dir/inputs.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FreeFall_calculator.dir/inputs.cpp.o -MF CMakeFiles/FreeFall_calculator.dir/inputs.cpp.o.d -o CMakeFiles/FreeFall_calculator.dir/inputs.cpp.o -c /Users/wesleystagg/Desktop/c++/freefall_calculator/inputs.cpp

CMakeFiles/FreeFall_calculator.dir/inputs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FreeFall_calculator.dir/inputs.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wesleystagg/Desktop/c++/freefall_calculator/inputs.cpp > CMakeFiles/FreeFall_calculator.dir/inputs.cpp.i

CMakeFiles/FreeFall_calculator.dir/inputs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FreeFall_calculator.dir/inputs.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wesleystagg/Desktop/c++/freefall_calculator/inputs.cpp -o CMakeFiles/FreeFall_calculator.dir/inputs.cpp.s

# Object files for target FreeFall_calculator
FreeFall_calculator_OBJECTS = \
"CMakeFiles/FreeFall_calculator.dir/main.cpp.o" \
"CMakeFiles/FreeFall_calculator.dir/calculations.cpp.o" \
"CMakeFiles/FreeFall_calculator.dir/inputs.cpp.o"

# External object files for target FreeFall_calculator
FreeFall_calculator_EXTERNAL_OBJECTS =

FreeFall_calculator: CMakeFiles/FreeFall_calculator.dir/main.cpp.o
FreeFall_calculator: CMakeFiles/FreeFall_calculator.dir/calculations.cpp.o
FreeFall_calculator: CMakeFiles/FreeFall_calculator.dir/inputs.cpp.o
FreeFall_calculator: CMakeFiles/FreeFall_calculator.dir/build.make
FreeFall_calculator: _deps/sfml-build/lib/libsfml-graphics-d.2.5.1.dylib
FreeFall_calculator: _deps/sfml-build/lib/libsfml-window-d.2.5.1.dylib
FreeFall_calculator: _deps/sfml-build/lib/libsfml-system-d.2.5.1.dylib
FreeFall_calculator: CMakeFiles/FreeFall_calculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wesleystagg/Desktop/c++/freefall_calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable FreeFall_calculator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FreeFall_calculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FreeFall_calculator.dir/build: FreeFall_calculator
.PHONY : CMakeFiles/FreeFall_calculator.dir/build

CMakeFiles/FreeFall_calculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FreeFall_calculator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FreeFall_calculator.dir/clean

CMakeFiles/FreeFall_calculator.dir/depend:
	cd /Users/wesleystagg/Desktop/c++/freefall_calculator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wesleystagg/Desktop/c++/freefall_calculator /Users/wesleystagg/Desktop/c++/freefall_calculator /Users/wesleystagg/Desktop/c++/freefall_calculator/build /Users/wesleystagg/Desktop/c++/freefall_calculator/build /Users/wesleystagg/Desktop/c++/freefall_calculator/build/CMakeFiles/FreeFall_calculator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FreeFall_calculator.dir/depend

