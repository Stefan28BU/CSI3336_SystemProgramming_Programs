# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Stefan_Xu/Desktop/Stefan/CSI3336/hw10_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Stefan_Xu/Desktop/Stefan/CSI3336/hw10_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hw10_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw10_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw10_2.dir/flags.make

CMakeFiles/hw10_2.dir/main.c.o: CMakeFiles/hw10_2.dir/flags.make
CMakeFiles/hw10_2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Stefan_Xu/Desktop/Stefan/CSI3336/hw10_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hw10_2.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hw10_2.dir/main.c.o   -c /Users/Stefan_Xu/Desktop/Stefan/CSI3336/hw10_2/main.c

CMakeFiles/hw10_2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hw10_2.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Stefan_Xu/Desktop/Stefan/CSI3336/hw10_2/main.c > CMakeFiles/hw10_2.dir/main.c.i

CMakeFiles/hw10_2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hw10_2.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Stefan_Xu/Desktop/Stefan/CSI3336/hw10_2/main.c -o CMakeFiles/hw10_2.dir/main.c.s

CMakeFiles/hw10_2.dir/main.c.o.requires:

.PHONY : CMakeFiles/hw10_2.dir/main.c.o.requires

CMakeFiles/hw10_2.dir/main.c.o.provides: CMakeFiles/hw10_2.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/hw10_2.dir/build.make CMakeFiles/hw10_2.dir/main.c.o.provides.build
.PHONY : CMakeFiles/hw10_2.dir/main.c.o.provides

CMakeFiles/hw10_2.dir/main.c.o.provides.build: CMakeFiles/hw10_2.dir/main.c.o


# Object files for target hw10_2
hw10_2_OBJECTS = \
"CMakeFiles/hw10_2.dir/main.c.o"

# External object files for target hw10_2
hw10_2_EXTERNAL_OBJECTS =

hw10_2: CMakeFiles/hw10_2.dir/main.c.o
hw10_2: CMakeFiles/hw10_2.dir/build.make
hw10_2: CMakeFiles/hw10_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Stefan_Xu/Desktop/Stefan/CSI3336/hw10_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable hw10_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw10_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw10_2.dir/build: hw10_2

.PHONY : CMakeFiles/hw10_2.dir/build

CMakeFiles/hw10_2.dir/requires: CMakeFiles/hw10_2.dir/main.c.o.requires

.PHONY : CMakeFiles/hw10_2.dir/requires

CMakeFiles/hw10_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw10_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw10_2.dir/clean

CMakeFiles/hw10_2.dir/depend:
	cd /Users/Stefan_Xu/Desktop/Stefan/CSI3336/hw10_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Stefan_Xu/Desktop/Stefan/CSI3336/hw10_2 /Users/Stefan_Xu/Desktop/Stefan/CSI3336/hw10_2 /Users/Stefan_Xu/Desktop/Stefan/CSI3336/hw10_2/cmake-build-debug /Users/Stefan_Xu/Desktop/Stefan/CSI3336/hw10_2/cmake-build-debug /Users/Stefan_Xu/Desktop/Stefan/CSI3336/hw10_2/cmake-build-debug/CMakeFiles/hw10_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw10_2.dir/depend

