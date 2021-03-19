file(REMOVE_RECURSE
  "../unit_tests.exe"
  "../unit_tests.exe.manifest"
  "../unit_tests.pdb"
  "libunit_tests.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/unit_tests.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
