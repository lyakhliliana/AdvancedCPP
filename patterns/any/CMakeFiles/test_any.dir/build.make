# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse

# Include any dependencies generated for this target.
include tasks/patterns/any/CMakeFiles/test_any.dir/depend.make

# Include the progress variables for this target.
include tasks/patterns/any/CMakeFiles/test_any.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/patterns/any/CMakeFiles/test_any.dir/flags.make

tasks/patterns/any/CMakeFiles/test_any.dir/test.cpp.o: tasks/patterns/any/CMakeFiles/test_any.dir/flags.make
tasks/patterns/any/CMakeFiles/test_any.dir/test.cpp.o: tasks/patterns/any/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/patterns/any/CMakeFiles/test_any.dir/test.cpp.o"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/any && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_any.dir/test.cpp.o -c /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/any/test.cpp

tasks/patterns/any/CMakeFiles/test_any.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_any.dir/test.cpp.i"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/any && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/any/test.cpp > CMakeFiles/test_any.dir/test.cpp.i

tasks/patterns/any/CMakeFiles/test_any.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_any.dir/test.cpp.s"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/any && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/any/test.cpp -o CMakeFiles/test_any.dir/test.cpp.s

# Object files for target test_any
test_any_OBJECTS = \
"CMakeFiles/test_any.dir/test.cpp.o"

# External object files for target test_any
test_any_EXTERNAL_OBJECTS =

test_any: tasks/patterns/any/CMakeFiles/test_any.dir/test.cpp.o
test_any: tasks/patterns/any/CMakeFiles/test_any.dir/build.make
test_any: libcontrib_catch_main.a
test_any: tasks/patterns/any/CMakeFiles/test_any.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../test_any"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/any && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_any.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/patterns/any/CMakeFiles/test_any.dir/build: test_any

.PHONY : tasks/patterns/any/CMakeFiles/test_any.dir/build

tasks/patterns/any/CMakeFiles/test_any.dir/clean:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/any && $(CMAKE_COMMAND) -P CMakeFiles/test_any.dir/cmake_clean.cmake
.PHONY : tasks/patterns/any/CMakeFiles/test_any.dir/clean

tasks/patterns/any/CMakeFiles/test_any.dir/depend:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/any /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/any /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/any/CMakeFiles/test_any.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/patterns/any/CMakeFiles/test_any.dir/depend

