# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.18

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Lenovo\Desktop\sem4lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Lenovo\Desktop\sem4lab1\build

# Include any dependencies generated for this target.
include CMakeFiles/mysorts.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mysorts.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mysorts.dir/flags.make

CMakeFiles/mysorts.dir/mysorts.cpp.obj: CMakeFiles/mysorts.dir/flags.make
CMakeFiles/mysorts.dir/mysorts.cpp.obj: ../mysorts.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Lenovo\Desktop\sem4lab1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mysorts.dir/mysorts.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mysorts.dir\mysorts.cpp.obj -c C:\Users\Lenovo\Desktop\sem4lab1\mysorts.cpp

CMakeFiles/mysorts.dir/mysorts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mysorts.dir/mysorts.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Lenovo\Desktop\sem4lab1\mysorts.cpp > CMakeFiles\mysorts.dir\mysorts.cpp.i

CMakeFiles/mysorts.dir/mysorts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mysorts.dir/mysorts.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Lenovo\Desktop\sem4lab1\mysorts.cpp -o CMakeFiles\mysorts.dir\mysorts.cpp.s

# Object files for target mysorts
mysorts_OBJECTS = \
"CMakeFiles/mysorts.dir/mysorts.cpp.obj"

# External object files for target mysorts
mysorts_EXTERNAL_OBJECTS =

libmysorts.a: CMakeFiles/mysorts.dir/mysorts.cpp.obj
libmysorts.a: CMakeFiles/mysorts.dir/build.make
libmysorts.a: CMakeFiles/mysorts.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Lenovo\Desktop\sem4lab1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmysorts.a"
	$(CMAKE_COMMAND) -P CMakeFiles\mysorts.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mysorts.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mysorts.dir/build: libmysorts.a

.PHONY : CMakeFiles/mysorts.dir/build

CMakeFiles/mysorts.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mysorts.dir\cmake_clean.cmake
.PHONY : CMakeFiles/mysorts.dir/clean

CMakeFiles/mysorts.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Lenovo\Desktop\sem4lab1 C:\Users\Lenovo\Desktop\sem4lab1 C:\Users\Lenovo\Desktop\sem4lab1\build C:\Users\Lenovo\Desktop\sem4lab1\build C:\Users\Lenovo\Desktop\sem4lab1\build\CMakeFiles\mysorts.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mysorts.dir/depend

