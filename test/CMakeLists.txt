# Tests need to be added as executables first
add_executable(FixedWidthIntegersTest
			   fixed_width_integers_test.cpp
			   ${CMAKE_SOURCE_DIR}/include/fixed_width_integers/fixed_width_integers.hpp)

# I'm using C++17 in the test
target_compile_features(FixedWidthIntegersTest PRIVATE cxx_std_11)
set_target_properties(FixedWidthIntegersTest PROPERTIES CXX_EXTENSIONS OFF)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(FixedWidthIntegersTest PRIVATE FixedWidthIntegers doctest)

if(MSVC)
	list(APPEND CompilerFlags 
			/W4
			/w14265
			/w14287
			/we4289
			/w14296
			/w14311
			/w14545
			/w14546
			/w14547
			/w14549
			/w14555
			/w14619
			/w14640
			/w14826
			/w14928
			/w44061
			/w44062
			/wd4514
			/wd4710
			/wd4711
			/wd4571
			/wd4820)
else()
	list(APPEND CompilerFlags
			-W
			-Wall
			-Wcast-align
			-Wconversion
			-Wdouble-promotion
			-Werror
			-Wextra
			-Wno-unknown-pragmas
			-Wnon-virtual-dtor
			-Wold-style-cast
			-Woverloaded-virtual
			-Wpedantic
			-Wshadow
			-Wsign-conversion
			-Wunused)

	if(CMAKE_CXX_COMPILER_ID MATCHES Clang )
		if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "8.0.0")
			list(APPEND CompilerFlags -Wnull-dereference)
		endif()
	else()
		list(APPEND CompilerFlags -Wuseless-cast)
							
		if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "6.0.0")
			list(APPEND CompilerFlags -Wduplicated-cond -Wnull-dereference)
		endif()

		if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "7.0.0")
			list(APPEND CompilerFlags -Wduplicated-branches)
		endif()
	endif()
endif()

target_compile_options(FixedWidthIntegersTest PRIVATE ${CompilerFlags})

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME FixedWidthIntegersTest COMMAND FixedWidthIntegersTest) # Command can be a target
