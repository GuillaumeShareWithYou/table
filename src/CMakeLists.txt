set(BINARY ${CMAKE_PROJECT_NAME})

set(MAIN main.cpp)
# source files
set(SOURCES line.cpp page.cpp table.cpp cell.cpp)


# Build a library with all project sources
add_library(Personne-lib  ${SOURCES})
## Create an executable with the main function
add_executable(${BINARY} ${MAIN})
# link the whole project sources lib to the main function
target_link_libraries(${BINARY} PUBLIC
Personne-lib)

include_directories(${CMAKE_SOURCE_DIR}/include)