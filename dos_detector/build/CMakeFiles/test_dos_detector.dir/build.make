# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/jesus/ED/2021/i82buruj/dos_detector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jesus/ED/2021/i82buruj/dos_detector/build

# Include any dependencies generated for this target.
include CMakeFiles/test_dos_detector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_dos_detector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_dos_detector.dir/flags.make

CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o: CMakeFiles/test_dos_detector.dir/flags.make
CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o: ../test_dos_detector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jesus/ED/2021/i82buruj/dos_detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o -c /home/jesus/ED/2021/i82buruj/dos_detector/test_dos_detector.cpp

CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jesus/ED/2021/i82buruj/dos_detector/test_dos_detector.cpp > CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.i

CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jesus/ED/2021/i82buruj/dos_detector/test_dos_detector.cpp -o CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.s

CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o.requires:

.PHONY : CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o.requires

CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o.provides: CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_dos_detector.dir/build.make CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o.provides.build
.PHONY : CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o.provides

CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o.provides.build: CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o


CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o: CMakeFiles/test_dos_detector.dir/flags.make
CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o: ../dos_detector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jesus/ED/2021/i82buruj/dos_detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o -c /home/jesus/ED/2021/i82buruj/dos_detector/dos_detector.cpp

CMakeFiles/test_dos_detector.dir/dos_detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_dos_detector.dir/dos_detector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jesus/ED/2021/i82buruj/dos_detector/dos_detector.cpp > CMakeFiles/test_dos_detector.dir/dos_detector.cpp.i

CMakeFiles/test_dos_detector.dir/dos_detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_dos_detector.dir/dos_detector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jesus/ED/2021/i82buruj/dos_detector/dos_detector.cpp -o CMakeFiles/test_dos_detector.dir/dos_detector.cpp.s

CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o.requires:

.PHONY : CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o.requires

CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o.provides: CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_dos_detector.dir/build.make CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o.provides.build
.PHONY : CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o.provides

CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o.provides.build: CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o


# Object files for target test_dos_detector
test_dos_detector_OBJECTS = \
"CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o" \
"CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o"

# External object files for target test_dos_detector
test_dos_detector_EXTERNAL_OBJECTS =

test_dos_detector: CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o
test_dos_detector: CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o
test_dos_detector: CMakeFiles/test_dos_detector.dir/build.make
test_dos_detector: CMakeFiles/test_dos_detector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jesus/ED/2021/i82buruj/dos_detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test_dos_detector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_dos_detector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_dos_detector.dir/build: test_dos_detector

.PHONY : CMakeFiles/test_dos_detector.dir/build

CMakeFiles/test_dos_detector.dir/requires: CMakeFiles/test_dos_detector.dir/test_dos_detector.cpp.o.requires
CMakeFiles/test_dos_detector.dir/requires: CMakeFiles/test_dos_detector.dir/dos_detector.cpp.o.requires

.PHONY : CMakeFiles/test_dos_detector.dir/requires

CMakeFiles/test_dos_detector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_dos_detector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_dos_detector.dir/clean

CMakeFiles/test_dos_detector.dir/depend:
	cd /home/jesus/ED/2021/i82buruj/dos_detector/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jesus/ED/2021/i82buruj/dos_detector /home/jesus/ED/2021/i82buruj/dos_detector /home/jesus/ED/2021/i82buruj/dos_detector/build /home/jesus/ED/2021/i82buruj/dos_detector/build /home/jesus/ED/2021/i82buruj/dos_detector/build/CMakeFiles/test_dos_detector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_dos_detector.dir/depend

