// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef DPLATFORMINTERFACE_P_H
#define DPLATFORMINTERFACE_P_H

#include "dplatforminterface.h"
#include <dobject_p.h>

DGUI_BEGIN_NAMESPACE

class DPlatformInterfacePrivate : public DCORE_NAMESPACE::DObjectPrivate
{
    D_DECLARE_PUBLIC(DPlatformInterface)
public:
    DPlatformInterfacePrivate(DPlatformInterface *qq);
    ~DPlatformInterfacePrivate();

public:
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
