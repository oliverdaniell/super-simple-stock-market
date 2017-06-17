set(SRC_FILES
    stocks_test.cpp
)

set(HDR_FILES
    catch.hpp
)

add_executable(
    unit-tests
    main.cpp ${SRC_FILES}
    ${HDR_FILES}
    )

#Turn on multithreaded builds and turn off secure crt warnings
if(MSVC)
	set_target_properties(unit-tests PROPERTIES COMPILE_FLAGS /MP)
	target_compile_definitions(unit-tests PRIVATE -D_SCL_SECURE_NO_WARNINGS)
endif()

set_property(TARGET unit-tests PROPERTY CXX_STANDARD 14)
set_property(TARGET unit-tests PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(unit-tests super-simple-stock-market)

add_test( unit-tests unit-tests )
