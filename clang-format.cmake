file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.hpp)

add_custom_target(
        clang-format
        COMMAND /usr/bin/clang-format
        -style=Google
        -i
        ${ALL_SOURCE_FILES}
)