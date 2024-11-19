// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "dtreelandplatforminterface.h"
#include "dtreelandplatforminterface_p.h"
#include "personalizationwaylandclientextension.h"
#include <qnamespace.h>

DGUI_BEGIN_NAMESPACE
DTreelandPlatformInterfacePrivate::DTreelandPlatformInterfacePrivate(DTreelandPlatformInterface *qq)
    : DPlatformInterfacePrivate(qq)
{
}

void DTreelandPlatformInterfacePrivate::initContext()
{
    if (m_appearanceContext.isNull()) { 
        m_appearanceContext.reset(new PersonalizationAppearanceContext(manager->get_appearance_context()));
    }
    // if (m_cursorContext.isNull()) {
    //     m_cursorContext.reset(new PersonalizationCursorContext(m_personalizationManager->get_cursor_context()));
    // }
    // if (m_fontContext.isNull()) {
    //     m_fontContext.reset(new PersonalizationFontContext(m_personalizationManager->get_font_context()));
    // }
}

DTreelandPlatformInterface::DTreelandPlatformInterface(QObject *parent)
    : DPlatformInterface(*new DTreelandPlatformInterfacePrivate(this), parent)
{
    D_D(DTreelandPlatformInterface);
    d->manager = PersonalizationManager::instance();
    connect(d->manager, &PersonalizationManager::activeChanged, this, [d](){
        d->initContext();
    });
}

// bool DTreelandPlatformInterface::isEnabledNoTitlebar(QWindow *window) const
// {
//     return PersonalizationManager::instance()->isEnabledNoTitlebar(window);
// }

// bool DTreelandPlatformInterface::setEnabledNoTitlebar(QWindow *window, bool enable)
// {
//     return PersonalizationManager::instance()->setEnabledNoTitlebar(window, enable);
// }

// int DTreelandPlatformInterface::windowRadius() const
// {
//     return PersonalizationManager::instance()->windowRadius();
// }

// void DTreelandPlatformInterface::setWindowRadius(int windowRadius)
// {
//     PersonalizationManager::instance()->setWindowRadius(windowRadius);
// }

// QByteArray DTreelandPlatformInterface::fontName() const
// {
//     return PersonalizationManager::instance()->fontName().toUtf8();
// }

// void DTreelandPlatformInterface::setFontName(const QByteArray &fontName)
// {
//     PersonalizationManager::instance()->setFontName(fontName);
// }

// QByteArray DTreelandPlatformInterface::monoFontName() const
// {
//     return PersonalizationManager::instance()->monoFontName().toUtf8();
// }

// void DTreelandPlatformInterface::setMonoFontName(const QByteArray &monoFontName)
// {
//     PersonalizationManager::instance()->setMonoFontName(monoFontName);
// }

// QByteArray DTreelandPlatformInterface::iconThemeName() const
// {
//     return PersonalizationManager::instance()->iconThemeName().toUtf8();
// }

// void DTreelandPlatformInterface::setIconThemeName(const QByteArray &iconThemeName)
// {
//     PersonalizationManager::instance()->setIconThemeName(iconThemeName);
// }

// QByteArray DTreelandPlatformInterface::cursorThemeName() const
// {
//     return PersonalizationManager::instance()->cursorThemeName().toUtf8();
// }

// void DTreelandPlatformInterface::setCursorThemeName(const QByteArray &cursorThemeName)
// {
//     PersonalizationManager::instance()->setCursorThemeName(cursorThemeName);
// }

QColor DTreelandPlatformInterface::activeColor() const
{
    D_D(const DTreelandPlatformInterface);
    if (d->m_appearanceContext) {
        return d->m_appearanceContext->activeColor();
    }
    return {};
}

void DTreelandPlatformInterface::setActiveColor(const QColor &color)
{
    
}

DGUI_END_NAMESPACE
