# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xulei/jungle/cworkspace/myc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xulei/jungle/cworkspace/myc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/33.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/33.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/33.dir/flags.make

CMakeFiles/33.dir/src/typedef/example5/main.c.o: CMakeFiles/33.dir/flags.make
CMakeFiles/33.dir/src/typedef/example5/main.c.o: ../src/typedef/example5/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xulei/jungle/cworkspace/myc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/33.dir/src/typedef/example5/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/33.dir/src/typedef/example5/main.c.o -c /Users/xulei/jungle/cworkspace/myc/src/typedef/example5/main.c

CMakeFiles/33.dir/src/typedef/example5/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/33.dir/src/typedef/example5/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/xulei/jungle/cworkspace/myc/src/typedef/example5/main.c > CMakeFiles/33.dir/src/typedef/example5/main.c.i

CMakeFiles/33.dir/src/typedef/example5/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/33.dir/src/typedef/example5/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/xulei/jungle/cworkspace/myc/src/typedef/example5/main.c -o CMakeFiles/33.dir/src/typedef/example5/main.c.s

CMakeFiles/33.dir/src/typedef/example5/typedef.c.o: CMakeFiles/33.dir/flags.make
CMakeFiles/33.dir/src/typedef/example5/typedef.c.o: ../src/typedef/example5/typedef.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xulei/jungle/cworkspace/myc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/33.dir/src/typedef/example5/typedef.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/33.dir/src/typedef/example5/typedef.c.o -c /Users/xulei/jungle/cworkspace/myc/src/typedef/example5/typedef.c

CMakeFiles/33.dir/src/typedef/example5/typedef.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/33.dir/src/typedef/example5/typedef.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/xulei/jungle/cworkspace/myc/src/typedef/example5/typedef.c > CMakeFiles/33.dir/src/typedef/example5/typedef.c.i

CMakeFiles/33.dir/src/typedef/example5/typedef.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/33.dir/src/typedef/example5/typedef.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/xulei/jungle/cworkspace/myc/src/typedef/example5/typedef.c -o CMakeFiles/33.dir/src/typedef/example5/typedef.c.s

# Object files for target 33
33_OBJECTS = \
"CMakeFiles/33.dir/src/typedef/example5/main.c.o" \
"CMakeFiles/33.dir/src/typedef/example5/typedef.c.o"

# External object files for target 33
33_EXTERNAL_OBJECTS =

33: CMakeFiles/33.dir/src/typedef/example5/main.c.o
33: CMakeFiles/33.dir/src/typedef/example5/typedef.c.o
33: CMakeFiles/33.dir/build.make
33: CMakeFiles/33.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xulei/jungle/cworkspace/myc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable 33"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/33.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/33.dir/build: 33
.PHONY : CMakeFiles/33.dir/build

CMakeFiles/33.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/33.dir/cmake_clean.cmake
.PHONY : CMakeFiles/33.dir/clean

CMakeFiles/33.dir/depend:
	cd /Users/xulei/jungle/cworkspace/myc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xulei/jungle/cworkspace/myc /Users/xulei/jungle/cworkspace/myc /Users/xulei/jungle/cworkspace/myc/cmake-build-debug /Users/xulei/jungle/cworkspace/myc/cmake-build-debug /Users/xulei/jungle/cworkspace/myc/cmake-build-debug/CMakeFiles/33.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/33.dir/depend

