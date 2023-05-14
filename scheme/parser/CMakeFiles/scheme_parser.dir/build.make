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
include tasks/scheme/parser/CMakeFiles/scheme_parser.dir/depend.make

# Include the progress variables for this target.
include tasks/scheme/parser/CMakeFiles/scheme_parser.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/scheme/parser/CMakeFiles/scheme_parser.dir/flags.make

tasks/scheme/parser/CMakeFiles/scheme_parser.dir/tokenizer.cpp.o: tasks/scheme/parser/CMakeFiles/scheme_parser.dir/flags.make
tasks/scheme/parser/CMakeFiles/scheme_parser.dir/tokenizer.cpp.o: tasks/scheme/parser/tokenizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/scheme/parser/CMakeFiles/scheme_parser.dir/tokenizer.cpp.o"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/scheme_parser.dir/tokenizer.cpp.o -c /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser/tokenizer.cpp

tasks/scheme/parser/CMakeFiles/scheme_parser.dir/tokenizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scheme_parser.dir/tokenizer.cpp.i"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser/tokenizer.cpp > CMakeFiles/scheme_parser.dir/tokenizer.cpp.i

tasks/scheme/parser/CMakeFiles/scheme_parser.dir/tokenizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scheme_parser.dir/tokenizer.cpp.s"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser/tokenizer.cpp -o CMakeFiles/scheme_parser.dir/tokenizer.cpp.s

tasks/scheme/parser/CMakeFiles/scheme_parser.dir/parser.cpp.o: tasks/scheme/parser/CMakeFiles/scheme_parser.dir/flags.make
tasks/scheme/parser/CMakeFiles/scheme_parser.dir/parser.cpp.o: tasks/scheme/parser/parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tasks/scheme/parser/CMakeFiles/scheme_parser.dir/parser.cpp.o"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/scheme_parser.dir/parser.cpp.o -c /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser/parser.cpp

tasks/scheme/parser/CMakeFiles/scheme_parser.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scheme_parser.dir/parser.cpp.i"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser/parser.cpp > CMakeFiles/scheme_parser.dir/parser.cpp.i

tasks/scheme/parser/CMakeFiles/scheme_parser.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scheme_parser.dir/parser.cpp.s"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser/parser.cpp -o CMakeFiles/scheme_parser.dir/parser.cpp.s

# Object files for target scheme_parser
scheme_parser_OBJECTS = \
"CMakeFiles/scheme_parser.dir/tokenizer.cpp.o" \
"CMakeFiles/scheme_parser.dir/parser.cpp.o"

# External object files for target scheme_parser
scheme_parser_EXTERNAL_OBJECTS =

tasks/scheme/parser/libscheme_parser.a: tasks/scheme/parser/CMakeFiles/scheme_parser.dir/tokenizer.cpp.o
tasks/scheme/parser/libscheme_parser.a: tasks/scheme/parser/CMakeFiles/scheme_parser.dir/parser.cpp.o
tasks/scheme/parser/libscheme_parser.a: tasks/scheme/parser/CMakeFiles/scheme_parser.dir/build.make
tasks/scheme/parser/libscheme_parser.a: tasks/scheme/parser/CMakeFiles/scheme_parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libscheme_parser.a"
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser && $(CMAKE_COMMAND) -P CMakeFiles/scheme_parser.dir/cmake_clean_target.cmake
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scheme_parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/scheme/parser/CMakeFiles/scheme_parser.dir/build: tasks/scheme/parser/libscheme_parser.a

.PHONY : tasks/scheme/parser/CMakeFiles/scheme_parser.dir/build

tasks/scheme/parser/CMakeFiles/scheme_parser.dir/clean:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser && $(CMAKE_COMMAND) -P CMakeFiles/scheme_parser.dir/cmake_clean.cmake
.PHONY : tasks/scheme/parser/CMakeFiles/scheme_parser.dir/clean

tasks/scheme/parser/CMakeFiles/scheme_parser.dir/depend:
	cd /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser /mnt/d/hse/cpp_deep_learn/cpp-advanced-hse/tasks/scheme/parser/CMakeFiles/scheme_parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/scheme/parser/CMakeFiles/scheme_parser.dir/depend

