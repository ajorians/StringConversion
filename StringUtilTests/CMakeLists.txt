add_executable(
   StringUtilTests
   Tests/StringUtilTests.cpp
   Runner.cpp
   stdafx.cpp
   stdafx.h
   targetver.h
)

target_include_directories(StringUtilTests PRIVATE Includes Tests ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
   StringUtilTests
   PRIVATE StringUtil
           gtest
           gmock
)
