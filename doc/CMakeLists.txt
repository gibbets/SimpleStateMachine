find_package(Doxygen)

    message("Doxygen build started.")

    set(DOXYGEN_IN in.doxygen)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_SOURCE_DIR}/config.doxygen)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    add_custom_target(doc ALL
                      COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/config.doxygen
                      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                      COMMENT "Generating API documentation with Doxygen"
                      VERBATIM)