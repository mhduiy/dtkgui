# SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
#
# SPDX-License-Identifier: GPL-3.0-or-later

file(GLOB TREELAND_HEADER
    ${CMAKE_CURRENT_LIST_DIR}/*.h
)
file(GLOB TREELAND_SOURCE
    ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)
set(treeland_SRC 
    ${TREELAND_HEADER}
    ${TREELAND_SOURCE}
)
