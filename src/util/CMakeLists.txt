include_directories("../")

set(UTIL_SRC
  "base.cc"
  "benchmark.cc"
  "i2pcontrol_client.cc"
  "i2pcontrol.cc"
  "main.cc"
  "routerinfo.cc"
  "su3file.cc")

if(WITH_FUZZ_TESTS)
  include_directories("${Fuzzer_INCLUDE_DIR}")
  list(APPEND UTIL_SRC
    "../../tests/fuzz_tests/eddsa25519.cc"
<<<<<<< 950a652de5e6c88ffab24aa4cbe093cf6be7ae9f
    "../../tests/fuzz_tests/i2pcontrol.cc"
=======
    "../../tests/fuzz_tests/http.cc"
>>>>>>> kovri-util: fuzz tests add HTTPMessage
    "../../tests/fuzz_tests/lease_set.cc"
    "../../tests/fuzz_tests/routerinfo.cc"
    "../../tests/fuzz_tests/su3.cc"
    "../../tests/fuzz_tests/zip.cc"
    "fuzz.cc")
endif()

if(WITH_BINARY)
  ConfigureBinary(${UTIL_NAME} "${UTIL_SRC}" ${UTIL_NAME})
  if(WITH_FUZZ_TESTS)
    target_link_libraries(${UTIL_NAME} ${Fuzzer_LIBRARIES})
  endif()
endif()

# vim: noai:ts=2:sw=2
