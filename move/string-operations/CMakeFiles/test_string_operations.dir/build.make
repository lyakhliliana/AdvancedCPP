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
include tasks/move/string-operations/CMakeFiles/test_string_operations.dir/depend.make

# Include the progress variables for this target.
include tasks/move/string-operations/CMakeFiles/test_string_operations.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/move/string-operations/CMakeFiles/test_string_operations.dir/flags.make

tasks/move/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.o: tasks/move/string-operations/CMakeFiles/test_string_operations.dir/flags.make
tasks/move/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.o: tasks/move/string-operations/string_operations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/move/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.o"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_string_operations.dir/string_operations.cpp.o -c /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations/string_operations.cpp

tasks/move/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_string_operations.dir/string_operations.cpp.i"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations/string_operations.cpp > CMakeFiles/test_string_operations.dir/string_operations.cpp.i

tasks/move/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_string_operations.dir/string_operations.cpp.s"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations/string_operations.cpp -o CMakeFiles/test_string_operations.dir/string_operations.cpp.s

tasks/move/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o: tasks/move/string-operations/CMakeFiles/test_string_operations.dir/flags.make
tasks/move/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o: tasks/move/string-operations/string_operations_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tasks/move/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o -c /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations/string_operations_test.cpp

tasks/move/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_string_operations.dir/string_operations_test.cpp.i"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations/string_operations_test.cpp > CMakeFiles/test_string_operations.dir/string_operations_test.cpp.i

tasks/move/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_string_operations.dir/string_operations_test.cpp.s"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations/string_operations_test.cpp -o CMakeFiles/test_string_operations.dir/string_operations_test.cpp.s

# Object files for target test_string_operations
test_string_operations_OBJECTS = \
"CMakeFiles/test_string_operations.dir/string_operations.cpp.o" \
"CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o"

# External object files for target test_string_operations
test_string_operations_EXTERNAL_OBJECTS =

test_string_operations: tasks/move/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.o
test_string_operations: tasks/move/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o
test_string_operations: tasks/move/string-operations/CMakeFiles/test_string_operations.dir/build.make
test_string_operations: libcontrib_catch_main.a
test_string_operations: allocations_checker/liballocations_checker.a
test_string_operations: tasks/move/string-operations/CMakeFiles/test_string_operations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../test_string_operations"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_string_operations.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/move/string-operations/CMakeFiles/test_string_operations.dir/build: test_string_operations

.PHONY : tasks/move/string-operations/CMakeFiles/test_string_operations.dir/build

tasks/move/string-operations/CMakeFiles/test_string_operations.dir/clean:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations && $(CMAKE_COMMAND) -P CMakeFiles/test_string_operations.dir/cmake_clean.cmake
.PHONY : tasks/move/string-operations/CMakeFiles/test_string_operations.dir/clean

tasks/move/string-operations/CMakeFiles/test_string_operations.dir/depend:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/move/string-operations/CMakeFiles/test_string_operations.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/move/string-operations/CMakeFiles/test_string_operations.dir/depend

