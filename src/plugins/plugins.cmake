# SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
#
# SPDX-License-Identifier: GPL-3.0-or-later

option(DTK_DISABLE_XCB "Disable XCB Protocols" OFF)

# force disable, because we don't support Treeland
option(DTK_DISABLE_TREELAND "Disable Treeland Protocols" OFF)

file(GLOB PLATFORM_INTERFACE_HEADER
    ${CMAKE_CURRENT_LIST_DIR}/*.h
)
file(GLOB PLATFORM_INTERFACE_SOURCE
    ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)

set(platform_interface_SRC 
    ${PLATFORM_INTERFACE_HEADER}
    ${PLATFORM_INTERFACE_SOURCE}
)
target_sources(${LIB_NAME} PRIVATE
    ${platform_interface_SRC}
)

if("${QT_VERSION_MAJOR}" STREQUAL "6")
    find_package(Qt6 REQUIRED COMPONENTS WaylandClient)
else()
    find_package(Qt5 REQUIRED COMPONENTS WaylandClient)
endif()

set(PRIVATE_HEADER_FILES plugins/dplatforminterface.h)
set(PRIVATE_INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_INCLUDEDIR}/dtk${PROJECT_VERSION_MAJOR}/DGui/Private")

# XCB
if(NOT DTK_DISABLE_XCB)
    message("Support XCB!")
    include(plugins/platform/xcb/xcb.cmake)
    target_sources(${LIB_NAME} PRIVATE
        ${xcb_SRC}
    )
    list(APPEND PRIVATE_HEADER_FILES "plugins/platform/xcb/dxcbplatforminterface.h")
else()
    target_compile_definitions(${LIB_NAME} PRIVATE DTK_DISABLE_XCB)
endif()

# Treeland
find_package(TreelandProtocols)
set(TreelandProtocols_FOUND ${TreelandProtocols_FOUND})

if(NOT DTK_DISABLE_TREELAND AND TreelandProtocols_FOUND)
    message("Support Treeland!")
    if("${QT_VERSION_MAJOR}" STREQUAL "6")
        qt6_generate_wayland_protocol_client_sources(${LIB_NAME} FILES
        ${TREELAND_PROTOCOLS_DATA_DIR}/treeland-personalization-manager-v1.xml
    )
    else()
        # ECM setup
        include(FeatureSummary)
        find_package(ECM REQUIRED NO_MODULE)
        set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${ECM_MODULE_PATH}")
        find_package(QtWaylandScanner)
        ecm_add_qtwayland_client_protocol(CLIENT_LIB_SRCS
            PROTOCOL ${TREELAND_PROTOCOLS_DATA_DIR}/treeland-personalization-manager-v1.xml
            BASENAME treeland-personalization-manager-v1
        )
        target_sources(${LIB_NAME} PRIVATE
            ${CLIENT_LIB_SRCS}
        )
    endif()

    include(plugins/platform/treeland/treeland.cmake)
    target_sources(${LIB_NAME} PRIVATE
        ${treeland_SRC}
    )
    list(APPEND PRIVATE_HEADER_FILES "plugins/platform/treeland/dtreelandplatforminterface.h")
else()
    target_compile_definitions(${LIB_NAME} PRIVATE DTK_DISABLE_TREELAND)
endif()

message(${PRIVATE_HEADER_FILES})
install(FILES ${PRIVATE_HEADER_FILES} DESTINATION "${PRIVATE_INCLUDE_INSTALL_DIR}")
