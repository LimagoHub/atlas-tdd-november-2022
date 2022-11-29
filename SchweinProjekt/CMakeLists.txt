cmake_minimum_required (VERSION 3.12)

project(SchweinProject)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)


add_executable(
	SchweinProject 
	source/main.cpp  
 "source/schwein.h" "source/stapel.h" "source/calculator.h" "source/clac_client.h" "source/calculator_impl.h")


# Add tests
add_subdirectory(tests)

