# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jhjang/Starlab/subgraph-matching-challenge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jhjang/Starlab/subgraph-matching-challenge/build

# Include any dependencies generated for this target.
include verify/CMakeFiles/verify.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include verify/CMakeFiles/verify.dir/compiler_depend.make

# Include the progress variables for this target.
include verify/CMakeFiles/verify.dir/progress.make

# Include the compile flags for this target's objects.
include verify/CMakeFiles/verify.dir/flags.make

verify/CMakeFiles/verify.dir/verify.cc.o: verify/CMakeFiles/verify.dir/flags.make
verify/CMakeFiles/verify.dir/verify.cc.o: ../verify/verify.cc
verify/CMakeFiles/verify.dir/verify.cc.o: verify/CMakeFiles/verify.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jhjang/Starlab/subgraph-matching-challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object verify/CMakeFiles/verify.dir/verify.cc.o"
	cd /home/jhjang/Starlab/subgraph-matching-challenge/build/verify && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT verify/CMakeFiles/verify.dir/verify.cc.o -MF CMakeFiles/verify.dir/verify.cc.o.d -o CMakeFiles/verify.dir/verify.cc.o -c /home/jhjang/Starlab/subgraph-matching-challenge/verify/verify.cc

verify/CMakeFiles/verify.dir/verify.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/verify.dir/verify.cc.i"
	cd /home/jhjang/Starlab/subgraph-matching-challenge/build/verify && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jhjang/Starlab/subgraph-matching-challenge/verify/verify.cc > CMakeFiles/verify.dir/verify.cc.i

verify/CMakeFiles/verify.dir/verify.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/verify.dir/verify.cc.s"
	cd /home/jhjang/Starlab/subgraph-matching-challenge/build/verify && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jhjang/Starlab/subgraph-matching-challenge/verify/verify.cc -o CMakeFiles/verify.dir/verify.cc.s

verify/CMakeFiles/verify.dir/__/src/graph.cc.o: verify/CMakeFiles/verify.dir/flags.make
verify/CMakeFiles/verify.dir/__/src/graph.cc.o: ../src/graph.cc
verify/CMakeFiles/verify.dir/__/src/graph.cc.o: verify/CMakeFiles/verify.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jhjang/Starlab/subgraph-matching-challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object verify/CMakeFiles/verify.dir/__/src/graph.cc.o"
	cd /home/jhjang/Starlab/subgraph-matching-challenge/build/verify && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT verify/CMakeFiles/verify.dir/__/src/graph.cc.o -MF CMakeFiles/verify.dir/__/src/graph.cc.o.d -o CMakeFiles/verify.dir/__/src/graph.cc.o -c /home/jhjang/Starlab/subgraph-matching-challenge/src/graph.cc

verify/CMakeFiles/verify.dir/__/src/graph.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/verify.dir/__/src/graph.cc.i"
	cd /home/jhjang/Starlab/subgraph-matching-challenge/build/verify && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jhjang/Starlab/subgraph-matching-challenge/src/graph.cc > CMakeFiles/verify.dir/__/src/graph.cc.i

verify/CMakeFiles/verify.dir/__/src/graph.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/verify.dir/__/src/graph.cc.s"
	cd /home/jhjang/Starlab/subgraph-matching-challenge/build/verify && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jhjang/Starlab/subgraph-matching-challenge/src/graph.cc -o CMakeFiles/verify.dir/__/src/graph.cc.s

# Object files for target verify
verify_OBJECTS = \
"CMakeFiles/verify.dir/verify.cc.o" \
"CMakeFiles/verify.dir/__/src/graph.cc.o"

# External object files for target verify
verify_EXTERNAL_OBJECTS =

verify/verify: verify/CMakeFiles/verify.dir/verify.cc.o
verify/verify: verify/CMakeFiles/verify.dir/__/src/graph.cc.o
verify/verify: verify/CMakeFiles/verify.dir/build.make
verify/verify: verify/CMakeFiles/verify.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jhjang/Starlab/subgraph-matching-challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable verify"
	cd /home/jhjang/Starlab/subgraph-matching-challenge/build/verify && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/verify.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
verify/CMakeFiles/verify.dir/build: verify/verify
.PHONY : verify/CMakeFiles/verify.dir/build

verify/CMakeFiles/verify.dir/clean:
	cd /home/jhjang/Starlab/subgraph-matching-challenge/build/verify && $(CMAKE_COMMAND) -P CMakeFiles/verify.dir/cmake_clean.cmake
.PHONY : verify/CMakeFiles/verify.dir/clean

verify/CMakeFiles/verify.dir/depend:
	cd /home/jhjang/Starlab/subgraph-matching-challenge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jhjang/Starlab/subgraph-matching-challenge /home/jhjang/Starlab/subgraph-matching-challenge/verify /home/jhjang/Starlab/subgraph-matching-challenge/build /home/jhjang/Starlab/subgraph-matching-challenge/build/verify /home/jhjang/Starlab/subgraph-matching-challenge/build/verify/CMakeFiles/verify.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : verify/CMakeFiles/verify.dir/depend

