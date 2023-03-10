# CMakeList.txt: proyecto de CMake para EasyDump, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

# Agregue un origen al ejecutable de este proyecto.
add_executable (EasyDump "dump.cpp" "dump.h" "component.h" "component.cpp" "separator.h" "separator.cpp" "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EasyDump PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
