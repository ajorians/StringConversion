add_library(
   StringUtil STATIC
   StringUtil.cpp
   Include/StringUtil/StringUtil.h
)

target_include_directories(StringUtil PUBLIC Include)

target_compile_definitions(StringUtil PRIVATE "STRINGUTILLIB_EXPORTS")

