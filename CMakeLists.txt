cmake_minimum_required(VERSION 3.15)

project(MCP777)

add_library(settings INTERFACE)
add_library(compiler::settings ALIAS settings)
target_compile_features(settings INTERFACE cxx_std_17)
target_compile_options(settings INTERFACE -pedantic -Wall -Werror)

add_subdirectory(cmd)
add_subdirectory(pkg)
