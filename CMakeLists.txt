cmake_minimum_required(VERSION 3.21)
project(FreeFall_calculator LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(FreeFall_calculator main.cpp calculations.cpp inputs.cpp Freefall_object.cpp User_input_text.cpp Menu.cpp)
target_link_libraries(FreeFall_calculator PRIVATE sfml-graphics sfml-window)
target_compile_features(FreeFall_calculator PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET CMakeSFMLProject POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:CMakeSFMLProject> $<TARGET_FILE_DIR:CMakeSFMLProject> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS FreeFall_calculator)