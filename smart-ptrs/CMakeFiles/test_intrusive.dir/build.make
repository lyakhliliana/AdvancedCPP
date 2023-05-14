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
include tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/depend.make

# Include the progress variables for this target.
include tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/flags.make

tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/intrusive/test.cpp.o: tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/flags.make
tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/intrusive/test.cpp.o: tasks/smart-ptrs/intrusive/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/intrusive/test.cpp.o"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/smart-ptrs && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_intrusive.dir/intrusive/test.cpp.o -c /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/smart-ptrs/intrusive/test.cpp

tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/intrusive/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_intrusive.dir/intrusive/test.cpp.i"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/smart-ptrs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/smart-ptrs/intrusive/test.cpp > CMakeFiles/test_intrusive.dir/intrusive/test.cpp.i

tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/intrusive/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_intrusive.dir/intrusive/test.cpp.s"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/smart-ptrs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/smart-ptrs/intrusive/test.cpp -o CMakeFiles/test_intrusive.dir/intrusive/test.cpp.s

# Object files for target test_intrusive
test_intrusive_OBJECTS = \
"CMakeFiles/test_intrusive.dir/intrusive/test.cpp.o"

# External object files for target test_intrusive
test_intrusive_EXTERNAL_OBJECTS =

test_intrusive: tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/intrusive/test.cpp.o
test_intrusive: tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/build.make
test_intrusive: libcontrib_catch_main.a
test_intrusive: allocations_checker/liballocations_checker.a
test_intrusive: tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../test_intrusive"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/smart-ptrs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_intrusive.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/build: test_intrusive

.PHONY : tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/build

tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/clean:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/smart-ptrs && $(CMAKE_COMMAND) -P CMakeFiles/test_intrusive.dir/cmake_clean.cmake
.PHONY : tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/clean

tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/depend:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/smart-ptrs /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/smart-ptrs /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/smart-ptrs/CMakeFiles/test_intrusive.dir/depend

