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
include tasks/unassigned/futex/CMakeFiles/test_futex.dir/depend.make

# Include the progress variables for this target.
include tasks/unassigned/futex/CMakeFiles/test_futex.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/unassigned/futex/CMakeFiles/test_futex.dir/flags.make

tasks/unassigned/futex/CMakeFiles/test_futex.dir/__/__/__/contrib/gmock_main.cc.o: tasks/unassigned/futex/CMakeFiles/test_futex.dir/flags.make
tasks/unassigned/futex/CMakeFiles/test_futex.dir/__/__/__/contrib/gmock_main.cc.o: contrib/gmock_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/unassigned/futex/CMakeFiles/test_futex.dir/__/__/__/contrib/gmock_main.cc.o"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_futex.dir/__/__/__/contrib/gmock_main.cc.o -c /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/contrib/gmock_main.cc

tasks/unassigned/futex/CMakeFiles/test_futex.dir/__/__/__/contrib/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_futex.dir/__/__/__/contrib/gmock_main.cc.i"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/contrib/gmock_main.cc > CMakeFiles/test_futex.dir/__/__/__/contrib/gmock_main.cc.i

tasks/unassigned/futex/CMakeFiles/test_futex.dir/__/__/__/contrib/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_futex.dir/__/__/__/contrib/gmock_main.cc.s"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/contrib/gmock_main.cc -o CMakeFiles/test_futex.dir/__/__/__/contrib/gmock_main.cc.s

tasks/unassigned/futex/CMakeFiles/test_futex.dir/test.cpp.o: tasks/unassigned/futex/CMakeFiles/test_futex.dir/flags.make
tasks/unassigned/futex/CMakeFiles/test_futex.dir/test.cpp.o: tasks/unassigned/futex/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tasks/unassigned/futex/CMakeFiles/test_futex.dir/test.cpp.o"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_futex.dir/test.cpp.o -c /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex/test.cpp

tasks/unassigned/futex/CMakeFiles/test_futex.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_futex.dir/test.cpp.i"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex/test.cpp > CMakeFiles/test_futex.dir/test.cpp.i

tasks/unassigned/futex/CMakeFiles/test_futex.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_futex.dir/test.cpp.s"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex/test.cpp -o CMakeFiles/test_futex.dir/test.cpp.s

# Object files for target test_futex
test_futex_OBJECTS = \
"CMakeFiles/test_futex.dir/__/__/__/contrib/gmock_main.cc.o" \
"CMakeFiles/test_futex.dir/test.cpp.o"

# External object files for target test_futex
test_futex_EXTERNAL_OBJECTS =

test_futex: tasks/unassigned/futex/CMakeFiles/test_futex.dir/__/__/__/contrib/gmock_main.cc.o
test_futex: tasks/unassigned/futex/CMakeFiles/test_futex.dir/test.cpp.o
test_futex: tasks/unassigned/futex/CMakeFiles/test_futex.dir/build.make
test_futex: libgmock.a
test_futex: tasks/unassigned/futex/CMakeFiles/test_futex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../test_futex"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_futex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/unassigned/futex/CMakeFiles/test_futex.dir/build: test_futex

.PHONY : tasks/unassigned/futex/CMakeFiles/test_futex.dir/build

tasks/unassigned/futex/CMakeFiles/test_futex.dir/clean:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex && $(CMAKE_COMMAND) -P CMakeFiles/test_futex.dir/cmake_clean.cmake
.PHONY : tasks/unassigned/futex/CMakeFiles/test_futex.dir/clean

tasks/unassigned/futex/CMakeFiles/test_futex.dir/depend:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/futex/CMakeFiles/test_futex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/unassigned/futex/CMakeFiles/test_futex.dir/depend

