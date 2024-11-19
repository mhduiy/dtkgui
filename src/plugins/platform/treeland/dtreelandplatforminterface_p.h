// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef DTREELANDPLATFORMINTERFACE_P_H
#define DTREELANDPLATFORMINTERFACE_P_H

#include "dtreelandplatforminterface.h"
#include "plugins/dplatforminterface_p.h"
#include "personalizationwaylandclientextension.h"

DGUI_BEGIN_NAMESPACE

class DTreelandPlatformInterfacePrivate : public DPlatformInterfacePrivate
{
    D_DECLARE_PUBLIC(DTreelandPlatformInterface)
public:
    DTreelandPlatformInterfacePrivate(DTreelandPlatformInterface *qq);

public slots:
    void initContext();

private:
    PersonalizationManager *manager;
    QScopedPointer<PersonalizationAppearanceContext> m_appearanceContext;
    QScopedPointer<PersonalizationCursorContext> m_cursorContext;
    QScopedPointer<PersonalizationFontContext> m_fontContext;
};

DGUI_END_NAMESPACE

#endif // DNATIVESETTINGS_P_H
