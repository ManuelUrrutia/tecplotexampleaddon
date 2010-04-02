if (MSVC)
    # Set up a default .user file that contains the debugging setup
    set (SYSTEM_NAME $ENV{USERDOMAIN})
    set (USER_NAME $ENV{USERNAME})

    # Only do this if one doesn't already exist
    set (USER_FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.vcproj.${SYSTEM_NAME}.${USER_NAME}.user)
    if (NOT EXISTS "${USER_FILE}")
        message (STATUS "Creating ${USER_FILE} with default debug settings")
        # These are the configuration variables
        if (CMAKE_GENERATOR MATCHES "Win64")
            set (USERFILE_PLATFORM "x64")
        else ()
            set (USERFILE_PLATFORM "Win32")
        endif ()
        find_program (USERFILE_DEBUG_COMMAND tec360.exe
                      HINTS "${TECPLOT_INSTALL_DIR}"
                      PATH_SUFFIXES bin
                      NO_DEFAULT_PATH)

        set (USER_FILE ${PROJECT_NAME}.vcproj.${SYSTEM_NAME}.${USER_NAME}.user)
        configure_file (cmake/User2005.in ${CMAKE_CURRENT_BINARY_DIR}/${USER_FILE})
    endif ()
endif ()