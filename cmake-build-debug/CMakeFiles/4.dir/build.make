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
include CMakeFiles/4.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/4.dir/flags.make

CMakeFiles/4.dir/src/mysql/example1/main.c.o: CMakeFiles/4.dir/flags.make
CMakeFiles/4.dir/src/mysql/example1/main.c.o: ../src/mysql/example1/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xulei/jungle/cworkspace/myc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/4.dir/src/mysql/example1/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/4.dir/src/mysql/example1/main.c.o -c /Users/xulei/jungle/cworkspace/myc/src/mysql/example1/main.c

CMakeFiles/4.dir/src/mysql/example1/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/4.dir/src/mysql/example1/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/xulei/jungle/cworkspace/myc/src/mysql/example1/main.c > CMakeFiles/4.dir/src/mysql/example1/main.c.i

CMakeFiles/4.dir/src/mysql/example1/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/4.dir/src/mysql/example1/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/xulei/jungle/cworkspace/myc/src/mysql/example1/main.c -o CMakeFiles/4.dir/src/mysql/example1/main.c.s

CMakeFiles/4.dir/src/mysql/example1/mysql1.c.o: CMakeFiles/4.dir/flags.make
CMakeFiles/4.dir/src/mysql/example1/mysql1.c.o: ../src/mysql/example1/mysql1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xulei/jungle/cworkspace/myc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/4.dir/src/mysql/example1/mysql1.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/4.dir/src/mysql/example1/mysql1.c.o -c /Users/xulei/jungle/cworkspace/myc/src/mysql/example1/mysql1.c

CMakeFiles/4.dir/src/mysql/example1/mysql1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/4.dir/src/mysql/example1/mysql1.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/xulei/jungle/cworkspace/myc/src/mysql/example1/mysql1.c > CMakeFiles/4.dir/src/mysql/example1/mysql1.c.i

CMakeFiles/4.dir/src/mysql/example1/mysql1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/4.dir/src/mysql/example1/mysql1.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/xulei/jungle/cworkspace/myc/src/mysql/example1/mysql1.c -o CMakeFiles/4.dir/src/mysql/example1/mysql1.c.s

# Object files for target 4
4_OBJECTS = \
"CMakeFiles/4.dir/src/mysql/example1/main.c.o" \
"CMakeFiles/4.dir/src/mysql/example1/mysql1.c.o"

# External object files for target 4
4_EXTERNAL_OBJECTS =

4 : CMakeFiles/4.dir/src/mysql/example1/main.c.o
4 : CMakeFiles/4.dir/src/mysql/example1/mysql1.c.o
4 : CMakeFiles/4.dir/build.make
4 : CMakeFiles/4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xulei/jungle/cworkspace/myc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable 4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/4.dir/build: 4
.PHONY : CMakeFiles/4.dir/build

CMakeFiles/4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/4.dir/clean

CMakeFiles/4.dir/depend:
	cd /Users/xulei/jungle/cworkspace/myc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xulei/jungle/cworkspace/myc /Users/xulei/jungle/cworkspace/myc /Users/xulei/jungle/cworkspace/myc/cmake-build-debug /Users/xulei/jungle/cworkspace/myc/cmake-build-debug /Users/xulei/jungle/cworkspace/myc/cmake-build-debug/CMakeFiles/4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/4.dir/depend

