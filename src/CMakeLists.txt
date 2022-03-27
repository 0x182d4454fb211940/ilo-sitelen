add_library(ilo-sitelen SHARED ilo-sitelen.cpp)
target_link_libraries(ilo-sitelen PRIVATE Fcitx5::Core)
set_target_properties(ilo-sitelen PROPERTIES PREFIX "")
install(TARGETS ilo-sitelen DESTINATION "${FCITX_INSTALL_LIBDIR}/fcitx5")

configure_file(ilo-sitelen-addon.conf.in ilo-sitelen-addon.conf)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/ilo-sitelen-addon.conf" RENAME ilo-sitelen.conf DESTINATION "${FCITX_INSTALL_PKGDATADIR}/addon")

install(FILES "ilo-sitelen.conf" DESTINATION "${FCITX_INSTALL_PKGDATADIR}/inputmethod")
