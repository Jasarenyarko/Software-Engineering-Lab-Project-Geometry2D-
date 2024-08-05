add_library(util src/compare.cpp)

target_include_directories(util PUBLIC include)

if(CODE_COVERAGE)
  target_code_coverage(util AUTO ALL)
endif()
