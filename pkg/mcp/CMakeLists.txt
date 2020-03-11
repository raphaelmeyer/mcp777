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

# Tests
add_executable(test_mcp
  tests/test_mcp777.cc
)
add_executable(tests::mcp ALIAS test_mcp)

target_link_libraries(test_mcp
  PRIVATE
    mcp777::mcp
    doctest::doctest
    trompeloeil
    compiler::settings
    Threads::Threads
)
add_custom_target(run_mcp_tests ALL COMMAND tests::mcp)
