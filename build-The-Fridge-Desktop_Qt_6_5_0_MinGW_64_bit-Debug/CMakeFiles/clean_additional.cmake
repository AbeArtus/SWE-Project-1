# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\The-Fridge_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\The-Fridge_autogen.dir\\ParseCache.txt"
  "The-Fridge_autogen"
  )
endif()
