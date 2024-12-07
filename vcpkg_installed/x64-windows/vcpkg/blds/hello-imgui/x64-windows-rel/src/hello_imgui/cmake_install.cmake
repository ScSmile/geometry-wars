# Install script for directory: C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/pkgs/hello-imgui_x64-windows")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/x64-windows-rel/src/hello_imgui/hello_imgui.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/x64-windows-rel/src/hello_imgui/CMakeFiles/hello_imgui.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/hello_imgui" TYPE FILE FILES
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/app_window_params.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/backend_pointers.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/docking_params.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/dpi_aware.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/hello_imgui.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/hello_imgui_assets.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/hello_imgui_error.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/hello_imgui_font.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/hello_imgui_include_opengl.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/hello_imgui_logger.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/hello_imgui_screenshot.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/hello_imgui_theme.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/hello_imgui_widgets.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/icons_font_awesome.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/image_from_asset.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/imgui_default_settings.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/imgui_theme.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/imgui_window_params.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/renderer_backend_options.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/runner_callbacks.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/runner_params.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/screen_bounds.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/hello_imgui/internal" TYPE FILE FILES
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/borderless_movable.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/clock_seconds.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/docking_details.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/functional_utils.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/hello_imgui_ini_settings.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/image_abstract.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/image_dx11.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/image_gl_deprecated.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/image_metal.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/image_opengl.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/image_vulkan.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/imgui_global_context.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/imguial_term.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/inicpp.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/menu_statusbar.h"
    "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/src/hello_imgui/internal/pnm.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hello-imgui" TYPE DIRECTORY FILES "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/hello_imgui_cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hello-imgui" TYPE DIRECTORY FILES "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/hello_imgui_assets")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/hello-imgui" TYPE FILE FILES "C:/Users/ScSmile/source/repos/Assignment_2/vcpkg_installed/x64-windows/vcpkg/blds/hello-imgui/src/1c2e6b96bd-19c7c1ba5a.clean/README.md")
endif()

