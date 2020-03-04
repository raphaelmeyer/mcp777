add_library(mcp
  src/mcp/mcp777.cc
)
add_library(mcp777::mcp ALIAS mcp)

target_include_directories(mcp PUBLIC src)

target_link_libraries(mcp
  PRIVATE
    mcp777::net
    compiler::settings
)
