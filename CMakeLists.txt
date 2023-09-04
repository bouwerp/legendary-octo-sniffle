cmake_minimum_required(VERSION 3.26.4)

set (CMAKE_CXX_STANDARD 23)

project(legendary-octo-sniffle CXX)

set(wxBUILD_SHARED OFF)

find_package(ZLIB REQUIRED)
find_package(wxWidgets REQUIRED COMPONENTS net core base)
find_package(OpenCV REQUIRED COMPONENTS core imgcodecs imgproc)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/MyFrame.cpp  ${PROJECT_SOURCE_DIR}/src/MyApp.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${wxWidgets_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} ZLIB::ZLIB
        ${wxWidgets_LIBRARIES}
        ${OpenCV_LIBS}
)
