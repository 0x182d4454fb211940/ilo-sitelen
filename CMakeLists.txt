cmake_minimum_required(VERSION 3.21)
project(fcitx-ilo-sitelen)

find_package(Fcitx5Core REQUIRED COMPONENTS)
include("${FCITX_INSTALL_CMAKECONFIG_DIR}/Fcitx5Utils/Fcitx5CompilerSettings.cmake")

add_subdirectory(src)
