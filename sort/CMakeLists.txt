SET(CMAKE_C_COMPILER clang)
SET(CMAKE_CXX_COMPILER clang++)
project(practice)

add_executable(bubbleSort ./BubbleSort.cpp)
add_executable(selectionSort ./SelectionSort.cpp)
add_executable(insertionSort ./InsertionSort.cpp)
add_executable(shellSort ./ShellSort.cpp)

