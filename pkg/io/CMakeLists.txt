add_library(io INTERFACE)
add_library(mcp777::io ALIAS io)

target_include_directories(io INTERFACE src)

target_link_libraries(io
  INTERFACE
    compiler::settings
)
