add_library(net
  src/net/udp.cc
)
add_library(mcp777::net ALIAS net)

target_include_directories(net PUBLIC src)

target_link_libraries(net
  PRIVATE compiler::settings
)
