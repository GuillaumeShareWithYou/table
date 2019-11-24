set(BINARY ${CMAKE_PROJECT_NAME}_tst)

# tests to be run
file(GLOB UNIT_TESTS
    "*.cpp"
)

set(TEST_TO_RUN pageTest.cpp)
# create a test executable with test sources files
set(ALL_TEST 0)

if(${ALL_TEST})
	add_executable(${BINARY} ${UNIT_TESTS})
else()
	add_executable(${BINARY} ${TEST_TO_RUN})
endif()
# link the test exec to the project lib
target_link_libraries(${BINARY} PUBLIC
Personne-lib
gtest
gtest_main)

include_directories(${CMAKE_SOURCE_DIR}/include)
enable_testing()
add_test(All ${BINARY})