# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/baryos/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/baryos/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/baryos/Documents/MATAM/HW8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/baryos/Documents/MATAM/HW8/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HW8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW8.dir/flags.make

CMakeFiles/HW8.dir/main.c.o: CMakeFiles/HW8.dir/flags.make
CMakeFiles/HW8.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/baryos/Documents/MATAM/HW8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/HW8.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/HW8.dir/main.c.o   -c /home/baryos/Documents/MATAM/HW8/main.c

CMakeFiles/HW8.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HW8.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/baryos/Documents/MATAM/HW8/main.c > CMakeFiles/HW8.dir/main.c.i

CMakeFiles/HW8.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HW8.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/baryos/Documents/MATAM/HW8/main.c -o CMakeFiles/HW8.dir/main.c.s

CMakeFiles/HW8.dir/Encoder.c.o: CMakeFiles/HW8.dir/flags.make
CMakeFiles/HW8.dir/Encoder.c.o: ../Encoder.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/baryos/Documents/MATAM/HW8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/HW8.dir/Encoder.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/HW8.dir/Encoder.c.o   -c /home/baryos/Documents/MATAM/HW8/Encoder.c

CMakeFiles/HW8.dir/Encoder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HW8.dir/Encoder.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/baryos/Documents/MATAM/HW8/Encoder.c > CMakeFiles/HW8.dir/Encoder.c.i

CMakeFiles/HW8.dir/Encoder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HW8.dir/Encoder.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/baryos/Documents/MATAM/HW8/Encoder.c -o CMakeFiles/HW8.dir/Encoder.c.s

CMakeFiles/HW8.dir/matam.c.o: CMakeFiles/HW8.dir/flags.make
CMakeFiles/HW8.dir/matam.c.o: ../matam.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/baryos/Documents/MATAM/HW8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/HW8.dir/matam.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/HW8.dir/matam.c.o   -c /home/baryos/Documents/MATAM/HW8/matam.c

CMakeFiles/HW8.dir/matam.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HW8.dir/matam.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/baryos/Documents/MATAM/HW8/matam.c > CMakeFiles/HW8.dir/matam.c.i

CMakeFiles/HW8.dir/matam.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HW8.dir/matam.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/baryos/Documents/MATAM/HW8/matam.c -o CMakeFiles/HW8.dir/matam.c.s

# Object files for target HW8
HW8_OBJECTS = \
"CMakeFiles/HW8.dir/main.c.o" \
"CMakeFiles/HW8.dir/Encoder.c.o" \
"CMakeFiles/HW8.dir/matam.c.o"

# External object files for target HW8
HW8_EXTERNAL_OBJECTS =

HW8: CMakeFiles/HW8.dir/main.c.o
HW8: CMakeFiles/HW8.dir/Encoder.c.o
HW8: CMakeFiles/HW8.dir/matam.c.o
HW8: CMakeFiles/HW8.dir/build.make
HW8: CMakeFiles/HW8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/baryos/Documents/MATAM/HW8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable HW8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW8.dir/build: HW8

.PHONY : CMakeFiles/HW8.dir/build

CMakeFiles/HW8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW8.dir/clean

CMakeFiles/HW8.dir/depend:
	cd /home/baryos/Documents/MATAM/HW8/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/baryos/Documents/MATAM/HW8 /home/baryos/Documents/MATAM/HW8 /home/baryos/Documents/MATAM/HW8/cmake-build-debug /home/baryos/Documents/MATAM/HW8/cmake-build-debug /home/baryos/Documents/MATAM/HW8/cmake-build-debug/CMakeFiles/HW8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW8.dir/depend

