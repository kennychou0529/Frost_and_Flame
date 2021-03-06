cmake_minimum_required(VERSION 2.8.7)
project ("Frost and Flame")

set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -Wextra -Wunused -Wshadow -Woverloaded-virtual -Wunreachable-code -Wconversion ${CMAKE_CXX_FLAGS}")

Include(FindPkgConfig)

PKG_SEARCH_MODULE(GLFW3 REQUIRED glfw3)
If (NOT GLFW3_FOUND)
    Message (ERROR "Couldn't find GLFW3 development files. On Debian-based systems you should install the 'glfw3-dev' package.")
Else (NOT GLFW3_FOUND)
    INCLUDE_DIRECTORIES(${GLFW3_INCLUDE_DIRS})
EndIf (NOT GLFW3_FOUND)

find_package(PhysFS REQUIRED)
if (PHYSFS_FOUND)
  INCLUDE_DIRECTORIES(${PHYSFS_INCLUDE_DIR})
  link_directories(${PHYSFS_LIBRARY})
Else (PHYSFS_FOUND)
   Message (FATAL_ERROR "Couldn't find libphysfs development files. On Debian-based systems you should install the 'libphysfs-dev' package.")
endif (PHYSFS_FOUND)

find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
  INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
  link_directories(${OPENGL_LIBRARIES})
Else (OPENGL_FOUND)
  Message (FATAL_ERROR "Couldn't find OpenGl development files. On Debian-based systems you should install the OpenGL development package.")
endif (OPENGL_FOUND)

PKG_SEARCH_MODULE(GLEW REQUIRED glew)
If (NOT GLEW_FOUND)
    Message (ERROR "Couldn't find glew development files. On Debian-based systems you should install the 'libglew-dev' package.")
Else (NOT GLEW_FOUND)
    INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIRS})
    #link_directories(${GLEW_LIBRARIES})
EndIf (NOT GLEW_FOUND)

include_directories(/usr/include)

include_directories(common)

file(GLOB FNF_S "source/*.cpp")
file(GLOB FNF_S_GAME "source/game/*.cpp")
file(GLOB FNF_S_RE "source/RoboEngine/*.cpp")
file(GLOB FNF_S_RE_A "source/RoboEngine/audio/*.cpp")
file(GLOB FNF_S_RE_C "source/RoboEngine/core/*.cpp")
file(GLOB FNF_S_RE_E "source/RoboEngine/entity/*.cpp")
file(GLOB FNF_S_RE_G "source/RoboEngine/graphics/*.cpp")
file(GLOB FNF_S_RE_P "source/RoboEngine/physics/*.cpp")
file(GLOB FNF_S_RE_R "source/RoboEngine/resource/*.cpp")
file(GLOB FNF_S_RE_S "source/RoboEngine/system/*.cpp")

add_executable(frost_and_flame ${FNF_S} ${FNF_S_GAME} ${FNF_S_RE} ${FNF_S_RE_A} ${FNF_S_RE_C} ${FNF_S_RE_E} ${FNF_S_RE_G} ${FNF_S_RE_P} ${FNF_S_RE_R} ${FNF_S_RE_S} )

link_directories( /path/to/PHYSFSlibs/)

target_Link_Libraries (frost_and_flame ${PHYSFS_LIBRARY} ${GLFW3_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})


