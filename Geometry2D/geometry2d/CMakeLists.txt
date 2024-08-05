add_library(geometry2D 
            src/angle.cpp 
            src/geo_compare.cpp 
            src/line.cpp 
            src/point.cpp 
            src/pose.cpp)

target_link_libraries(geometry2D PUBLIC util)

target_include_directories(geometry2D PUBLIC include)

if(CODE_COVERAGE)
  target_code_coverage(geometry2D AUTO ALL)
endif()
