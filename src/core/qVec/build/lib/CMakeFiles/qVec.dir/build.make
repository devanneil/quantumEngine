# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/devanneil/Desktop/qVec

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/devanneil/Desktop/qVec/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/qVec.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/CMakeFiles/qVec.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/qVec.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/qVec.dir/flags.make

lib/CMakeFiles/qVec.dir/qVec.cpp.o: lib/CMakeFiles/qVec.dir/flags.make
lib/CMakeFiles/qVec.dir/qVec.cpp.o: /Users/devanneil/Desktop/qVec/lib/qVec.cpp
lib/CMakeFiles/qVec.dir/qVec.cpp.o: lib/CMakeFiles/qVec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/devanneil/Desktop/qVec/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/qVec.dir/qVec.cpp.o"
	cd /Users/devanneil/Desktop/qVec/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/qVec.dir/qVec.cpp.o -MF CMakeFiles/qVec.dir/qVec.cpp.o.d -o CMakeFiles/qVec.dir/qVec.cpp.o -c /Users/devanneil/Desktop/qVec/lib/qVec.cpp

lib/CMakeFiles/qVec.dir/qVec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/qVec.dir/qVec.cpp.i"
	cd /Users/devanneil/Desktop/qVec/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/devanneil/Desktop/qVec/lib/qVec.cpp > CMakeFiles/qVec.dir/qVec.cpp.i

lib/CMakeFiles/qVec.dir/qVec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/qVec.dir/qVec.cpp.s"
	cd /Users/devanneil/Desktop/qVec/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/devanneil/Desktop/qVec/lib/qVec.cpp -o CMakeFiles/qVec.dir/qVec.cpp.s

# Object files for target qVec
qVec_OBJECTS = \
"CMakeFiles/qVec.dir/qVec.cpp.o"

# External object files for target qVec
qVec_EXTERNAL_OBJECTS =

lib/libqVec.a: lib/CMakeFiles/qVec.dir/qVec.cpp.o
lib/libqVec.a: lib/CMakeFiles/qVec.dir/build.make
lib/libqVec.a: lib/CMakeFiles/qVec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/devanneil/Desktop/qVec/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libqVec.a"
	cd /Users/devanneil/Desktop/qVec/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/qVec.dir/cmake_clean_target.cmake
	cd /Users/devanneil/Desktop/qVec/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qVec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/qVec.dir/build: lib/libqVec.a
.PHONY : lib/CMakeFiles/qVec.dir/build

lib/CMakeFiles/qVec.dir/clean:
	cd /Users/devanneil/Desktop/qVec/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/qVec.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/qVec.dir/clean

lib/CMakeFiles/qVec.dir/depend:
	cd /Users/devanneil/Desktop/qVec/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/devanneil/Desktop/qVec /Users/devanneil/Desktop/qVec/lib /Users/devanneil/Desktop/qVec/build /Users/devanneil/Desktop/qVec/build/lib /Users/devanneil/Desktop/qVec/build/lib/CMakeFiles/qVec.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/CMakeFiles/qVec.dir/depend

