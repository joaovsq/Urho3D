project(UrhoEditor)

# Find Urho3D library
find_package (Urho3D REQUIRED)
include_directories (${URHO3D_INCLUDE_DIRS})

# Find QT
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

if (WIN32)
    add_definitions(-DURHO3D_WIN32_CONSOLE)
endif()

# Define source files
include(Sources.cmake)

add_executable(UrhoEditor ${EDITOR_SOURCE_FILES})
target_link_libraries(UrhoEditor Urho3D Qt5::Core Qt5::Widgets Qt5::Gui)

