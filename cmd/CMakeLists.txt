
add_executable(mcp777 mcp777/main.cc)

target_link_libraries(mcp777
  PRIVATE
    mcp777::mcp
    compiler::settings
)
