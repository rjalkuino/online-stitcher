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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.5.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.5.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mcandres/sandbox/optonaut/online-stitcher

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mcandres/sandbox/optonaut/online-stitcher/build

# Include any dependencies generated for this target.
include src/test/CMakeFiles/stat-test.dir/depend.make

# Include the progress variables for this target.
include src/test/CMakeFiles/stat-test.dir/progress.make

# Include the compile flags for this target's objects.
include src/test/CMakeFiles/stat-test.dir/flags.make

src/test/CMakeFiles/stat-test.dir/statTest.cpp.o: src/test/CMakeFiles/stat-test.dir/flags.make
src/test/CMakeFiles/stat-test.dir/statTest.cpp.o: ../src/test/statTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mcandres/sandbox/optonaut/online-stitcher/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/test/CMakeFiles/stat-test.dir/statTest.cpp.o"
	cd /Users/mcandres/sandbox/optonaut/online-stitcher/build/src/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stat-test.dir/statTest.cpp.o -c /Users/mcandres/sandbox/optonaut/online-stitcher/src/test/statTest.cpp

src/test/CMakeFiles/stat-test.dir/statTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stat-test.dir/statTest.cpp.i"
	cd /Users/mcandres/sandbox/optonaut/online-stitcher/build/src/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mcandres/sandbox/optonaut/online-stitcher/src/test/statTest.cpp > CMakeFiles/stat-test.dir/statTest.cpp.i

src/test/CMakeFiles/stat-test.dir/statTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stat-test.dir/statTest.cpp.s"
	cd /Users/mcandres/sandbox/optonaut/online-stitcher/build/src/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mcandres/sandbox/optonaut/online-stitcher/src/test/statTest.cpp -o CMakeFiles/stat-test.dir/statTest.cpp.s

src/test/CMakeFiles/stat-test.dir/statTest.cpp.o.requires:

.PHONY : src/test/CMakeFiles/stat-test.dir/statTest.cpp.o.requires

src/test/CMakeFiles/stat-test.dir/statTest.cpp.o.provides: src/test/CMakeFiles/stat-test.dir/statTest.cpp.o.requires
	$(MAKE) -f src/test/CMakeFiles/stat-test.dir/build.make src/test/CMakeFiles/stat-test.dir/statTest.cpp.o.provides.build
.PHONY : src/test/CMakeFiles/stat-test.dir/statTest.cpp.o.provides

src/test/CMakeFiles/stat-test.dir/statTest.cpp.o.provides.build: src/test/CMakeFiles/stat-test.dir/statTest.cpp.o


# Object files for target stat-test
stat__test_OBJECTS = \
"CMakeFiles/stat-test.dir/statTest.cpp.o"

# External object files for target stat-test
stat__test_EXTERNAL_OBJECTS =

src/test/stat-test: src/test/CMakeFiles/stat-test.dir/statTest.cpp.o
src/test/stat-test: src/test/CMakeFiles/stat-test.dir/build.make
src/test/stat-test: src/liboptonaut-lib.a
src/test/stat-test: /usr/local/lib/libopencv_xphoto.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_ximgproc.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_tracking.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_surface_matching.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_saliency.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_rgbd.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_reg.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_optflow.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_line_descriptor.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_latentsvm.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_datasets.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_text.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_face.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_ccalib.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_bioinspired.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_bgsegm.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_adas.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_xobjdetect.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_videostab.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_superres.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_stitching.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_xfeatures2d.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_shape.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_video.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_photo.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_objdetect.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_calib3d.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_features2d.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_ml.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_highgui.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_videoio.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_imgcodecs.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_imgproc.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_flann.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_core.3.0.0.dylib
src/test/stat-test: /usr/local/lib/libopencv_hal.a
src/test/stat-test: /usr/local/share/OpenCV/3rdparty/lib/libippicv.a
src/test/stat-test: src/test/CMakeFiles/stat-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mcandres/sandbox/optonaut/online-stitcher/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stat-test"
	cd /Users/mcandres/sandbox/optonaut/online-stitcher/build/src/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stat-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/test/CMakeFiles/stat-test.dir/build: src/test/stat-test

.PHONY : src/test/CMakeFiles/stat-test.dir/build

src/test/CMakeFiles/stat-test.dir/requires: src/test/CMakeFiles/stat-test.dir/statTest.cpp.o.requires

.PHONY : src/test/CMakeFiles/stat-test.dir/requires

src/test/CMakeFiles/stat-test.dir/clean:
	cd /Users/mcandres/sandbox/optonaut/online-stitcher/build/src/test && $(CMAKE_COMMAND) -P CMakeFiles/stat-test.dir/cmake_clean.cmake
.PHONY : src/test/CMakeFiles/stat-test.dir/clean

src/test/CMakeFiles/stat-test.dir/depend:
	cd /Users/mcandres/sandbox/optonaut/online-stitcher/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mcandres/sandbox/optonaut/online-stitcher /Users/mcandres/sandbox/optonaut/online-stitcher/src/test /Users/mcandres/sandbox/optonaut/online-stitcher/build /Users/mcandres/sandbox/optonaut/online-stitcher/build/src/test /Users/mcandres/sandbox/optonaut/online-stitcher/build/src/test/CMakeFiles/stat-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/test/CMakeFiles/stat-test.dir/depend

