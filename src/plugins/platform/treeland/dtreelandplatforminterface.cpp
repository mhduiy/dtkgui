// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "dtreelandplatforminterface.h"

#include "dplatformtheme.h"
#include "private/dplatforminterface_p.h"
#include "personalizationwaylandclientextension.h"

#include <QtWaylandClient/private/qwaylandwindow_p.h>
#include <QtWaylandClient/private/qwaylandsurface_p.h>
#include <QWindow>

DGUI_BEGIN_NAMESPACE

DTreelandPlatformInterface::DTreelandPlatformInterface(DPlatformTheme *platformTheme)
    : DPlatformInterface(platformTheme)
{
    m_manager.reset(new PersonalizationManager);
    connect(m_manager.data(), &PersonalizationManager::activeChanged, this, [this](){
        if (m_manager->isActive()) {
            initContext();
            handlePendingTasks();
        }
    });
}

void DTreelandPlatformInterface::initContext()
{
    if (m_appearanceContext.isNull()) { 
        m_appearanceContext.reset(new PersonalizationAppearanceContext(m_manager->get_appearance_context(), this));
    }
    if (m_fontContext.isNull()) {
        m_fontContext.reset(new PersonalizationFontContext(m_manager->get_font_context(), this));
    }
}

void DTreelandPlatformInterface::handlePendingTasks()
{
    while (!m_pendingTasks.isEmpty()) {
        auto handleFunc = m_pendingTasks.dequeue();
        handleFunc();
    }
}

QByteArray DTreelandPlatformInterface::iconThemeName() const
{
    return m_iconThemeName;
}

QByteArray DTreelandPlatformInterface::fontName() const
{
    return m_fontName;
}

QByteArray DTreelandPlatformInterface::monoFontName() const
{
    return m_monoFontName;
}

qreal DTreelandPlatformInterface::fontPointSize() const
{
    return m_fontPointSize;
}

QColor DTreelandPlatformInterface::activeColor() const
{
    return m_activeColor;
}

QByteArray DTreelandPlatformInterface::themeName() const
{
    return m_themeName;
}

void DTreelandPlatformInterface::setIconThemeName(const QByteArray &iconThemeName)
{
    if (m_appearanceContext) {
        m_appearanceContext->set_icon_theme(iconThemeName);
    }
}

void DTreelandPlatformInterface::setFontName(const QByteArray &fontName)
{
    if (m_fontContext) {
        m_fontContext->set_font(fontName);
    }
}

void DTreelandPlatformInterface::setMonoFontName(const QByteArray &monoFontName)
{
    if (m_fontContext) {
        m_fontContext->set_monospace_font(monoFontName);
    }
}

void DTreelandPlatformInterface::setFontPointSize(qreal fontPointSize)
{
    if (m_fontContext) {
        m_fontContext->set_font_size(fontPointSize);
    }
}

void DTreelandPlatformInterface::setActiveColor(const QColor activeColor)
{
    if (m_appearanceContext) {
        m_appearanceContext->set_active_color(activeColor.name());
    }
}

bool DTreelandPlatformInterface::setEnabledNoTitlebarForWindow(QWindow *window, bool enable)
{
    auto handleFunc = [this, window, enable](){
        auto windowContext = getWindowContext(window);
        if (!windowContext) {
            qWarning() << "windowContext is nullptr!";
            return false;
        }
        windowContext->set_titlebar(enable ? PersonalizationWindowContext::enable_mode_disable : PersonalizationWindowContext::enable_mode_enable);
        return true;
    };
    if (m_manager->isActive()) {
        return handleFunc();
    } else {
        m_pendingTasks.enqueue(handleFunc);
    }
    return true;
}

void DTreelandPlatformInterface::setEnableBlurWindowForWindow(QWindow *window, bool enable)
{
    auto handleFunc = [this, window, enable](){
        auto windowContext = getWindowContext(window);
        if (!windowContext) {
            qWarning() << "windowContext is nullptr!";
            return;
        }
        windowContext->set_blend_mode(enable ? PersonalizationWindowContext::blend_mode_blur : PersonalizationWindowContext::blend_mode_transparent);
    };
    if (m_manager->isActive()) {
        handleFunc();
    } else {
        m_pendingTasks.enqueue(handleFunc);
    }
}

PersonalizationWindowContext *DTreelandPlatformInterface::getWindowContext(QWindow *window)
{
    if (!m_manager->isSupported()) {
        return nullptr;
    }
    if (!window) {
        qWarning() << "window is nullptr!!!";
        return nullptr;
    }
    if (m_windowContexts.contains(window)) {
        return m_windowContexts.value(window);
    }
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    auto waylandWindow = window->nativeInterface<QNativeInterface::Private::QWaylandWindow>();
#else
    auto waylandWindow = dynamic_cast<QtWaylandClient::QWaylandWindow *>(window->handle());
#endif
    if (!waylandWindow) {
        qWarning() << "waylandWindow is nullptr!!!";
        return nullptr;
    }
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    auto surface = waylandWindow->surface();
#else
    auto surface = waylandWindow->waylandSurface()->object();
#endif
    if (!surface) {
        qWarning() << "waylandSurface is nullptr!!!";
        return nullptr;
    }

    auto context =  new PersonalizationWindowContext(m_manager->get_window_context(surface), this);
    connect(window, &QWindow::visibleChanged, context, [this, context, window](bool visible){
        if (!visible) {
            context->deleteLater();
            m_windowContexts.remove(window);
        }
    });

    m_windowContexts.insert(window, context);
    return context;
}

DGUI_END_NAMESPACE
