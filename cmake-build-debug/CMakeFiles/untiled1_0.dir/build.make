# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Photoshop(filters)\photoshop-CS112-Assignment3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Photoshop(filters)\photoshop-CS112-Assignment3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untiled1_0.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/untiled1_0.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/untiled1_0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untiled1_0.dir/flags.make

CMakeFiles/untiled1_0.dir/FiltersBONUS.cpp.obj: CMakeFiles/untiled1_0.dir/flags.make
CMakeFiles/untiled1_0.dir/FiltersBONUS.cpp.obj: ../FiltersBONUS.cpp
CMakeFiles/untiled1_0.dir/FiltersBONUS.cpp.obj: CMakeFiles/untiled1_0.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Photoshop(filters)\photoshop-CS112-Assignment3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untiled1_0.dir/FiltersBONUS.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untiled1_0.dir/FiltersBONUS.cpp.obj -MF CMakeFiles\untiled1_0.dir\FiltersBONUS.cpp.obj.d -o CMakeFiles\untiled1_0.dir\FiltersBONUS.cpp.obj -c D:\Photoshop(filters)\photoshop-CS112-Assignment3\FiltersBONUS.cpp

CMakeFiles/untiled1_0.dir/FiltersBONUS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untiled1_0.dir/FiltersBONUS.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Photoshop(filters)\photoshop-CS112-Assignment3\FiltersBONUS.cpp > CMakeFiles\untiled1_0.dir\FiltersBONUS.cpp.i

CMakeFiles/untiled1_0.dir/FiltersBONUS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untiled1_0.dir/FiltersBONUS.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Photoshop(filters)\photoshop-CS112-Assignment3\FiltersBONUS.cpp -o CMakeFiles\untiled1_0.dir\FiltersBONUS.cpp.s

# Object files for target untiled1_0
untiled1_0_OBJECTS = \
"CMakeFiles/untiled1_0.dir/FiltersBONUS.cpp.obj"

# External object files for target untiled1_0
untiled1_0_EXTERNAL_OBJECTS =

untiled1_0.exe: CMakeFiles/untiled1_0.dir/FiltersBONUS.cpp.obj
untiled1_0.exe: CMakeFiles/untiled1_0.dir/build.make
untiled1_0.exe: CMakeFiles/untiled1_0.dir/linklibs.rsp
untiled1_0.exe: CMakeFiles/untiled1_0.dir/objects1.rsp
untiled1_0.exe: CMakeFiles/untiled1_0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Photoshop(filters)\photoshop-CS112-Assignment3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable untiled1_0.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untiled1_0.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untiled1_0.dir/build: untiled1_0.exe
.PHONY : CMakeFiles/untiled1_0.dir/build

CMakeFiles/untiled1_0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untiled1_0.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untiled1_0.dir/clean

CMakeFiles/untiled1_0.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Photoshop(filters)\photoshop-CS112-Assignment3 D:\Photoshop(filters)\photoshop-CS112-Assignment3 D:\Photoshop(filters)\photoshop-CS112-Assignment3\cmake-build-debug D:\Photoshop(filters)\photoshop-CS112-Assignment3\cmake-build-debug D:\Photoshop(filters)\photoshop-CS112-Assignment3\cmake-build-debug\CMakeFiles\untiled1_0.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untiled1_0.dir/depend

