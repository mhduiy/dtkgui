# SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
#
# SPDX-License-Identifier: GPL-3.0-or-later

file(GLOB XCB_HEADER
  ${CMAKE_CURRENT_LIST_DIR}/*.h
)
file(GLOB XCB_SOURCE
  ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)
set(xcb_SRC 
  ${XCB_HEADER}
  ${XCB_SOURCE}
)
