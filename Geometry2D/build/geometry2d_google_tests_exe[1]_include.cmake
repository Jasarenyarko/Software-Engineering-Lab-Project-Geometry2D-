if(EXISTS "/workspaces/sel-homework_9/build/geometry2d_google_tests_exe[1]_tests.cmake")
  include("/workspaces/sel-homework_9/build/geometry2d_google_tests_exe[1]_tests.cmake")
else()
  add_test(geometry2d_google_tests_exe_NOT_BUILT geometry2d_google_tests_exe_NOT_BUILT)
endif()
