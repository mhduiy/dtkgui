// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef DTREELANDPLATFORMINTERFACE_P_H
#define DTREELANDPLATFORMINTERFACE_P_H

#include "dtreelandplatforminterface.h"
#include "private/dplatforminterface_p.h"
#include "personalizationwaylandclientextension.h"

DGUI_BEGIN_NAMESPACE

class DTreelandPlatformInterfacePrivate : public DPlatformInterfacePrivate
{
public:
    D_DECLARE_PUBLIC(DTreelandPlatformInterface)
    DTreelandPlatformInterfacePrivate(DTreelandPlatformInterface *qq);

public slots:
    void initContext();

public:

    PersonalizationManager *manager;
    QScopedPointer<PersonalizationAppearanceContext> m_appearanceContext;
    QScopedPointer<PersonalizationCursorContext> m_cursorContext;
    QScopedPointer<PersonalizationFontContext> m_fontContext;

    QColor m_activeColor;
    int m_titleHeight;
    QByteArray m_fontName;
    QByteArray m_monoFontName;
    QByteArray m_iconThemeName;
    QByteArray m_cursorThemeName;
    qreal m_fontPointSize;
    int m_windowRadius;
    int m_scrollBarPolicy;
};

DGUI_END_NAMESPACE

#endif // DNATIVESETTINGS_P_H
