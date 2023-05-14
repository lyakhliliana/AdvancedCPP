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
include tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/depend.make

# Include the progress variables for this target.
include tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/flags.make

tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/__/__/__/contrib/gmock_main.cc.o: tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/flags.make
tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/__/__/__/contrib/gmock_main.cc.o: contrib/gmock_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/__/__/__/contrib/gmock_main.cc.o"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_fast_queue.dir/__/__/__/contrib/gmock_main.cc.o -c /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/contrib/gmock_main.cc

tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/__/__/__/contrib/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_fast_queue.dir/__/__/__/contrib/gmock_main.cc.i"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/contrib/gmock_main.cc > CMakeFiles/test_fast_queue.dir/__/__/__/contrib/gmock_main.cc.i

tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/__/__/__/contrib/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_fast_queue.dir/__/__/__/contrib/gmock_main.cc.s"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/contrib/gmock_main.cc -o CMakeFiles/test_fast_queue.dir/__/__/__/contrib/gmock_main.cc.s

tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/test.cpp.o: tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/flags.make
tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/test.cpp.o: tasks/unassigned/fast-queue/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/test.cpp.o"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_fast_queue.dir/test.cpp.o -c /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue/test.cpp

tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_fast_queue.dir/test.cpp.i"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue/test.cpp > CMakeFiles/test_fast_queue.dir/test.cpp.i

tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_fast_queue.dir/test.cpp.s"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue/test.cpp -o CMakeFiles/test_fast_queue.dir/test.cpp.s

# Object files for target test_fast_queue
test_fast_queue_OBJECTS = \
"CMakeFiles/test_fast_queue.dir/__/__/__/contrib/gmock_main.cc.o" \
"CMakeFiles/test_fast_queue.dir/test.cpp.o"

# External object files for target test_fast_queue
test_fast_queue_EXTERNAL_OBJECTS =

test_fast_queue: tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/__/__/__/contrib/gmock_main.cc.o
test_fast_queue: tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/test.cpp.o
test_fast_queue: tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/build.make
test_fast_queue: libgmock.a
test_fast_queue: tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../test_fast_queue"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_fast_queue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/build: test_fast_queue

.PHONY : tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/build

tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/clean:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue && $(CMAKE_COMMAND) -P CMakeFiles/test_fast_queue.dir/cmake_clean.cmake
.PHONY : tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/clean

tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/depend:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/unassigned/fast-queue/CMakeFiles/test_fast_queue.dir/depend
