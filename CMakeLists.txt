cmake_minimum_required(VERSION 3.26.4)
project(legendary-octo-sniffle CXX)

set (CMAKE_CXX_STANDARD 23)

set(wxBUILD_SHARED OFF)

find_package(ZLIB REQUIRED)
find_package(wxWidgets REQUIRED COMPONENTS net core base)
find_package(OpenCV REQUIRED COMPONENTS core imgcodecs imgproc)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp)
aux_source_directory(src SOURCES)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
        ${wxWidgets_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} ZLIB::ZLIB
        ${wxWidgets_LIBRARIES}
        ${OpenCV_LIBS}
)
