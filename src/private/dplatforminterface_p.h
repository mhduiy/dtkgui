// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef DPLATFORMINTERFACE_P_H
#define DPLATFORMINTERFACE_P_H

#include <DObjectPrivate>
#include "plugins/dplatforminterface.h"

DGUI_BEGIN_NAMESPACE

class DPlatformInterface;
class DPlatformInterfacePrivate : public DCORE_NAMESPACE::DObjectPrivate
{
    D_DECLARE_PUBLIC(DPlatformInterface)
public:
    DPlatformInterfacePrivate(DPlatformInterface *qq);
    ~DPlatformInterfacePrivate();
};

DGUI_END_NAMESPACE

#endif // DNATIVESETTINGS_P_H
