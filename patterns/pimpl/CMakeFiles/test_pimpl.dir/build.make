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
include tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/depend.make

# Include the progress variables for this target.
include tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/flags.make

tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/ugly.cpp.o: tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/flags.make
tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/ugly.cpp.o: tasks/patterns/pimpl/ugly.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/ugly.cpp.o"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_pimpl.dir/ugly.cpp.o -c /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl/ugly.cpp

tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/ugly.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_pimpl.dir/ugly.cpp.i"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl/ugly.cpp > CMakeFiles/test_pimpl.dir/ugly.cpp.i

tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/ugly.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_pimpl.dir/ugly.cpp.s"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl/ugly.cpp -o CMakeFiles/test_pimpl.dir/ugly.cpp.s

tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/good.cpp.o: tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/flags.make
tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/good.cpp.o: tasks/patterns/pimpl/good.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/good.cpp.o"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_pimpl.dir/good.cpp.o -c /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl/good.cpp

tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/good.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_pimpl.dir/good.cpp.i"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl/good.cpp > CMakeFiles/test_pimpl.dir/good.cpp.i

tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/good.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_pimpl.dir/good.cpp.s"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl/good.cpp -o CMakeFiles/test_pimpl.dir/good.cpp.s

# Object files for target test_pimpl
test_pimpl_OBJECTS = \
"CMakeFiles/test_pimpl.dir/ugly.cpp.o" \
"CMakeFiles/test_pimpl.dir/good.cpp.o"

# External object files for target test_pimpl
test_pimpl_EXTERNAL_OBJECTS =

test_pimpl: tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/ugly.cpp.o
test_pimpl: tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/good.cpp.o
test_pimpl: tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/build.make
test_pimpl: libcontrib_catch_main.a
test_pimpl: tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../test_pimpl"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_pimpl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/build: test_pimpl

.PHONY : tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/build

tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/clean:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl && $(CMAKE_COMMAND) -P CMakeFiles/test_pimpl.dir/cmake_clean.cmake
.PHONY : tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/clean

tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/depend:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/patterns/pimpl/CMakeFiles/test_pimpl.dir/depend

