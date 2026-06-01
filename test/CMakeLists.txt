include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include)
include_directories(${${PROJECT_NAME}_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}.test
  AllTests.cpp
  tests.cpp)
target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME} gtest)
target_compile_definitions(${PROJECT_NAME}.test 
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}/test")

install(TARGETS ${PROJECT_NAME}.test
        DESTINATION "${tool_dest}")
