# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gg/Bureau/projet/rush-hour

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gg/Bureau/projet/rush-hour/build

# Include any dependencies generated for this target.
include game/game/CMakeFiles/test_game.dir/depend.make

# Include the progress variables for this target.
include game/game/CMakeFiles/test_game.dir/progress.make

# Include the compile flags for this target's objects.
include game/game/CMakeFiles/test_game.dir/flags.make

game/game/CMakeFiles/test_game.dir/test_game1.c.o: game/game/CMakeFiles/test_game.dir/flags.make
game/game/CMakeFiles/test_game.dir/test_game1.c.o: ../game/game/test_game1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gg/Bureau/projet/rush-hour/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object game/game/CMakeFiles/test_game.dir/test_game1.c.o"
	cd /home/gg/Bureau/projet/rush-hour/build/game/game && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_game.dir/test_game1.c.o   -c /home/gg/Bureau/projet/rush-hour/game/game/test_game1.c

game/game/CMakeFiles/test_game.dir/test_game1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_game.dir/test_game1.c.i"
	cd /home/gg/Bureau/projet/rush-hour/build/game/game && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gg/Bureau/projet/rush-hour/game/game/test_game1.c > CMakeFiles/test_game.dir/test_game1.c.i

game/game/CMakeFiles/test_game.dir/test_game1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_game.dir/test_game1.c.s"
	cd /home/gg/Bureau/projet/rush-hour/build/game/game && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gg/Bureau/projet/rush-hour/game/game/test_game1.c -o CMakeFiles/test_game.dir/test_game1.c.s

game/game/CMakeFiles/test_game.dir/test_game1.c.o.requires:

.PHONY : game/game/CMakeFiles/test_game.dir/test_game1.c.o.requires

game/game/CMakeFiles/test_game.dir/test_game1.c.o.provides: game/game/CMakeFiles/test_game.dir/test_game1.c.o.requires
	$(MAKE) -f game/game/CMakeFiles/test_game.dir/build.make game/game/CMakeFiles/test_game.dir/test_game1.c.o.provides.build
.PHONY : game/game/CMakeFiles/test_game.dir/test_game1.c.o.provides

game/game/CMakeFiles/test_game.dir/test_game1.c.o.provides.build: game/game/CMakeFiles/test_game.dir/test_game1.c.o


game/game/CMakeFiles/test_game.dir/game.c.o: game/game/CMakeFiles/test_game.dir/flags.make
game/game/CMakeFiles/test_game.dir/game.c.o: ../game/game/game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gg/Bureau/projet/rush-hour/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object game/game/CMakeFiles/test_game.dir/game.c.o"
	cd /home/gg/Bureau/projet/rush-hour/build/game/game && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_game.dir/game.c.o   -c /home/gg/Bureau/projet/rush-hour/game/game/game.c

game/game/CMakeFiles/test_game.dir/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_game.dir/game.c.i"
	cd /home/gg/Bureau/projet/rush-hour/build/game/game && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gg/Bureau/projet/rush-hour/game/game/game.c > CMakeFiles/test_game.dir/game.c.i

game/game/CMakeFiles/test_game.dir/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_game.dir/game.c.s"
	cd /home/gg/Bureau/projet/rush-hour/build/game/game && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gg/Bureau/projet/rush-hour/game/game/game.c -o CMakeFiles/test_game.dir/game.c.s

game/game/CMakeFiles/test_game.dir/game.c.o.requires:

.PHONY : game/game/CMakeFiles/test_game.dir/game.c.o.requires

game/game/CMakeFiles/test_game.dir/game.c.o.provides: game/game/CMakeFiles/test_game.dir/game.c.o.requires
	$(MAKE) -f game/game/CMakeFiles/test_game.dir/build.make game/game/CMakeFiles/test_game.dir/game.c.o.provides.build
.PHONY : game/game/CMakeFiles/test_game.dir/game.c.o.provides

game/game/CMakeFiles/test_game.dir/game.c.o.provides.build: game/game/CMakeFiles/test_game.dir/game.c.o


# Object files for target test_game
test_game_OBJECTS = \
"CMakeFiles/test_game.dir/test_game1.c.o" \
"CMakeFiles/test_game.dir/game.c.o"

# External object files for target test_game
test_game_EXTERNAL_OBJECTS =

game/game/test_game: game/game/CMakeFiles/test_game.dir/test_game1.c.o
game/game/test_game: game/game/CMakeFiles/test_game.dir/game.c.o
game/game/test_game: game/game/CMakeFiles/test_game.dir/build.make
game/game/test_game: game/libgame.a
game/game/test_game: game/game/CMakeFiles/test_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gg/Bureau/projet/rush-hour/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable test_game"
	cd /home/gg/Bureau/projet/rush-hour/build/game/game && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
game/game/CMakeFiles/test_game.dir/build: game/game/test_game

.PHONY : game/game/CMakeFiles/test_game.dir/build

game/game/CMakeFiles/test_game.dir/requires: game/game/CMakeFiles/test_game.dir/test_game1.c.o.requires
game/game/CMakeFiles/test_game.dir/requires: game/game/CMakeFiles/test_game.dir/game.c.o.requires

.PHONY : game/game/CMakeFiles/test_game.dir/requires

game/game/CMakeFiles/test_game.dir/clean:
	cd /home/gg/Bureau/projet/rush-hour/build/game/game && $(CMAKE_COMMAND) -P CMakeFiles/test_game.dir/cmake_clean.cmake
.PHONY : game/game/CMakeFiles/test_game.dir/clean

game/game/CMakeFiles/test_game.dir/depend:
	cd /home/gg/Bureau/projet/rush-hour/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gg/Bureau/projet/rush-hour /home/gg/Bureau/projet/rush-hour/game/game /home/gg/Bureau/projet/rush-hour/build /home/gg/Bureau/projet/rush-hour/build/game/game /home/gg/Bureau/projet/rush-hour/build/game/game/CMakeFiles/test_game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : game/game/CMakeFiles/test_game.dir/depend

