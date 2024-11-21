// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
#include "dtreelandplatforminterface.h"
#include "dtreelandplatforminterface_p.h"
#include "personalizationwaylandclientextension.h"
#include "plugins/dplatforminterface.h"
#include <qnamespace.h>
DGUI_BEGIN_NAMESPACE
DTreelandPlatformInterfacePrivate::DTreelandPlatformInterfacePrivate(DTreelandPlatformInterface *qq)
    : DPlatformInterfacePrivate(qq)
{
}
void DTreelandPlatformInterfacePrivate::initContext()
{
    if (m_appearanceContext.isNull()) { 
        m_appearanceContext.reset(new PersonalizationAppearanceContext(manager->get_appearance_context(), this));
    }
    if (m_cursorContext.isNull()) {
        m_cursorContext.reset(new PersonalizationCursorContext(manager->get_cursor_context(), this));
    }
    if (m_fontContext.isNull()) {
        m_fontContext.reset(new PersonalizationFontContext(manager->get_font_context(), this));
    }
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

int DTreelandPlatformInterface::windowRadius() const
{
    D_D(const DTreelandPlatformInterface);
    return d->m_windowRadius;
}

void DTreelandPlatformInterface::setWindowRadius(int windowRadius)
{
    D_D(DTreelandPlatformInterface);
    d->m_appearanceContext->set_round_corner_radius(windowRadius);
}

QByteArray DTreelandPlatformInterface::fontName() const
{
    D_D(const DTreelandPlatformInterface);
    return d->m_fontName;
}

void DTreelandPlatformInterface::setFontName(const QByteArray &fontName)
{
    D_D(DTreelandPlatformInterface);
    d->m_fontContext->set_font(fontName);
}

QByteArray DTreelandPlatformInterface::monoFontName() const
{
    D_D(const DTreelandPlatformInterface);
    return d->m_monoFontName;
}

void DTreelandPlatformInterface::setMonoFontName(const QByteArray &monoFontName)
{
    D_D(DTreelandPlatformInterface);
    d->m_fontContext->set_monospace_font(monoFontName);
}

QByteArray DTreelandPlatformInterface::iconThemeName() const
{
    D_D(const DTreelandPlatformInterface);
    return d->m_iconThemeName;
}

void DTreelandPlatformInterface::setIconThemeName(const QByteArray &iconThemeName)
{
    D_D(DTreelandPlatformInterface);
    d->m_appearanceContext->set_icon_theme(iconThemeName);
}

// QByteArray DTreelandPlatformInterface::cursorThemeName() const
// {
//     D_D(const DTreelandPlatformInterface);
//     return d->m_cursorThemeName;
// }
// void DTreelandPlatformInterface::setCursorThemeName(const QByteArray &cursorThemeName)
// {
//     D_D(DTreelandPlatformInterface);
//     d->m_cursorContext->set_theme(cursorThemeName);
// }

QColor DTreelandPlatformInterface::activeColor() const
{
    D_D(const DTreelandPlatformInterface);
    return d->m_activeColor;
}

void DTreelandPlatformInterface::setActiveColor(const QColor color)
{
    D_D(DTreelandPlatformInterface);
    d->m_appearanceContext->set_active_color(color.name());
}

// int DTreelandPlatformInterface::titleHeight() const
// {
//     D_D(const DTreelandPlatformInterface);
//     return d->m_titleHeight;
// }
// void DTreelandPlatformInterface::setTitleHeight(int titleHeight)
// {
//     D_D(DTreelandPlatformInterface);
//     d->m_appearanceContext->set_window_titlebar_height(titleHeight);
// }

qreal DTreelandPlatformInterface::fontPointSize() const
{
    D_D(const DTreelandPlatformInterface);
    return d->m_fontPointSize;
}

void DTreelandPlatformInterface::setFontPointSize(const qreal fontSize)
{
    D_D(DTreelandPlatformInterface);
    d->m_fontContext->set_font_size(fontSize);
}

// int DTreelandPlatformInterface::scrollBarPolicy() const
// {
//     D_D(const DTreelandPlatformInterface);
//     return d->m_scrollBarPolicy;
// }
// void DTreelandPlatformInterface::setScrollBarPolicy(const int scrollBarPolicy)
// {
//     D_D(DTreelandPlatformInterface);
//     d->m_appearanceContext->set
// }

DGUI_END_NAMESPACE