set(BINARY ${CMAKE_PROJECT_NAME}_tst)

# tests to be run
file(GLOB UNIT_TESTS
    "*.cpp"
)
# create a test executable with test sources files
add_executable(${BINARY} ${UNIT_TESTS})
# link the test exec to the project lib
target_link_libraries(${BINARY} PUBLIC
Personne-lib
gtest
gtest_main)

include_directories(${CMAKE_SOURCE_DIR}/include)
enable_testing()
add_test(All ${BINARY})