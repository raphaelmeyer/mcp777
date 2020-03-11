include(FetchContent)

FetchContent_Declare(
  doctest
  GIT_REPOSITORY  https://github.com/onqtam/doctest.git
  GIT_TAG         2.3.7
)

FetchContent_MakeAvailable(doctest)

FetchContent_Declare(
  trompeloeil
  GIT_REPOSITORY  https://github.com/rollbear/trompeloeil.git
  GIT_TAG         37
)

FetchContent_MakeAvailable(trompeloeil)
