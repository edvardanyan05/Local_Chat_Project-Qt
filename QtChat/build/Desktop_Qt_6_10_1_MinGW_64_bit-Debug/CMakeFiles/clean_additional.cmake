# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QtChat_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QtChat_autogen.dir\\ParseCache.txt"
  "QtChat_autogen"
  )
endif()
