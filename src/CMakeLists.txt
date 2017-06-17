set(SRC_FILES
    "stocks.cpp"
)

set(HDR_FILES
    "include/stocks.h"
)

add_library(
    super-simple-stock-market
    ${HDR_FILES}
    ${SRC_FILES})
    
target_include_directories(super-simple-stock-market PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)