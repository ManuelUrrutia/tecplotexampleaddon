if (UNIX)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fPIC -fno-strict-aliasing")
    add_definitions(-DLINUX)
    if (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
        add_definitions(-DLINUX64)
    endif ()
endif ()

if (WIN32)
      # Set warning level to 4 (the highest) on Windows
      set (CMAKE_CXX_WARNING_LEVEL 4)
      if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
            string (REGEX REPLACE "/W[0-4]" "/W4"
                    CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
      else ()
            set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
      endif ()
      # Enable multi-process compilation
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
endif ()
