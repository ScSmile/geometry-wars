# Install script for directory: C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/pkgs/hello-imgui_x64-windows/debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "OFF")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/x64-windows-dbg/src/hello_imgui/stb_hello_imgui.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/x64-windows-dbg/src/hello_imgui/hello_imgui.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/hello_imgui/hello-imgui-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/hello_imgui/hello-imgui-targets.cmake"
         "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/x64-windows-dbg/CMakeFiles/Export/844c881eb850aabe7fae11c73f879059/hello-imgui-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/hello_imgui/hello-imgui-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/hello_imgui/hello-imgui-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/hello_imgui" TYPE FILE FILES "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/x64-windows-dbg/CMakeFiles/Export/844c881eb850aabe7fae11c73f879059/hello-imgui-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/hello_imgui" TYPE FILE FILES "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/x64-windows-dbg/CMakeFiles/Export/844c881eb850aabe7fae11c73f879059/hello-imgui-targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/hello_imgui" TYPE FILE FILES
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/hello_imgui_cmake/hello-imguiConfig.cmake"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/x64-windows-dbg/hello-imguiConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/x64-windows-dbg/src/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/x64-windows-dbg/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
