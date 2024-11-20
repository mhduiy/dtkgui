// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef DTREELANDPLATFORMINTERFACE_H
#define DTREELANDPLATFORMINTERFACE_H

#include "plugins/dplatforminterface.h"

DGUI_BEGIN_NAMESPACE

class DTreelandPlatformInterfacePrivate;
class DTreelandPlatformInterface : public DPlatformInterface
{
    Q_OBJECT
    D_DECLARE_PRIVATE(DTreelandPlatformInterface)
public:
    explicit DTreelandPlatformInterface(QObject *parent);
};

DGUI_END_NAMESPACE
#endif
