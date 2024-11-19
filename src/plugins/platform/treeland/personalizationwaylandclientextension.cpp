// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "personalizationwaylandclientextension.h"

#include <qglobal.h>
#include <qobjectdefs.h>
#include <qtimer.h>
#include <qwaylandclientextension.h>
#include <QtWaylandClient/private/qwaylandsurface_p.h>
#include <QtWaylandClient/private/qwaylandwindow_p.h>
#include <QGuiApplication>
#include <private/qguiapplication_p.h>
#include <private/qwaylandintegration_p.h>
#include "dtreelandplatforminterface_p.h"

DGUI_BEGIN_NAMESPACE

class PersonalizationManager_: public PersonalizationManager {};
Q_GLOBAL_STATIC(PersonalizationManager_, personalizationManager)

PersonalizationManager::PersonalizationManager()
    : QWaylandClientExtensionTemplate<PersonalizationManager>(1)
{
    if (QGuiApplication::platformName() == QLatin1String("wayland")) {
        QtWaylandClient::QWaylandIntegration *waylandIntegration = static_cast<QtWaylandClient::QWaylandIntegration *>(QGuiApplicationPrivate::platformIntegration());
        if (!waylandIntegration) {
            qWarning() << "waylandIntegration is nullptr!!!";
            return;
        }
        m_waylandDisplay = waylandIntegration->display();
        if (m_waylandDisplay == nullptr) {
            qWarning() << "waylandDisplay is nullptr!!!";
            return;
        }
        addListener();
    }
}

PersonalizationManager *PersonalizationManager::instance()
{
    return personalizationManager;
}

// PersonalizationWindowContext *PersonalizationManager::getWindowContext(QWindow *window)
// {
    // if (!window) {
    //     qWarning() << "window is nullptr!!!";
    //     return nullptr;
    // }
    // auto waylandWindow = dynamic_cast<QtWaylandClient::QWaylandWindow *>(window->handle());
    // if (!waylandWindow) {
    //     qWarning() << "waylandWindow is nullptr!!!";
    //     return nullptr;
    // }
    // auto surface = waylandWindow->waylandSurface()->object();
    // if (!surface) {
    //     qWarning() << "waylandSurface is nullptr!!!";
    //     return nullptr;
    // }
    // auto context = get_window_context(surface);
    // if (m_windowContext.isNull()) {
    //     m_windowContext.reset(new PersonalizationWindowContext(context));
    // }
    // return m_windowContext.data();
// }

void PersonalizationManager::addListener()
{
    m_waylandDisplay->addRegistryListener(&handleListenerGlobal, this);
}

void PersonalizationManager::removeListener()
{
    m_waylandDisplay->removeListener(&handleListenerGlobal, this);
}

void PersonalizationManager::handleListenerGlobal(void *data, wl_registry *registry, uint32_t id, const QString &interface, uint32_t version)
{
    if (interface == treeland_personalization_manager_v1_interface.name) {
        PersonalizationManager *integration = static_cast<PersonalizationManager *>(data);
        if (!integration) {
            qWarning() << "integration is nullptr!!!";
            return;
        }

        integration->init(registry, id, version);
    }
}

PersonalizationWindowContext::PersonalizationWindowContext(struct ::treeland_personalization_window_context_v1 *context, DTreelandPlatformInterfacePrivate *interface)
    : QWaylandClientExtensionTemplate<PersonalizationWindowContext>(1)
    , QtWayland::treeland_personalization_window_context_v1(context)
    , m_interface(interface)
{
}


PersonalizationAppearanceContext::PersonalizationAppearanceContext(struct ::treeland_personalization_appearance_context_v1 *context, DTreelandPlatformInterfacePrivate *interface)
    : QWaylandClientExtensionTemplate<PersonalizationAppearanceContext>(1)
    , QtWayland::treeland_personalization_appearance_context_v1(context)
    , m_interface(interface)
{
    get_round_corner_radius();
    get_icon_theme();
    get_active_color();
    get_window_opacity();
    get_window_theme_type();
    get_window_titlebar_height();

    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, this, [this](){
        get_active_color();
        get_window_titlebar_height();
    });
    timer->start(1000);
}

void PersonalizationAppearanceContext::treeland_personalization_appearance_context_v1_round_corner_radius(int32_t radius)
{
    m_interface->m_windowRadius = radius;
    emit m_interface->q_func()->windowRadiusChanged(radius);
}

void PersonalizationAppearanceContext::treeland_personalization_appearance_context_v1_icon_theme(const QString &theme_name)
{
    m_interface->m_iconThemeName = theme_name.toUtf8();
    emit m_interface->q_func()->iconThemeNameChanged(theme_name.toUtf8());
}

void PersonalizationAppearanceContext::treeland_personalization_appearance_context_v1_active_color(const QString &active_color)
{
    m_interface->m_activeColor = active_color;
    emit m_interface->q_func()->activeColorChanged(active_color);
}

void PersonalizationAppearanceContext::treeland_personalization_appearance_context_v1_window_opacity(uint32_t opacity)
{
    
}

void PersonalizationAppearanceContext::treeland_personalization_appearance_context_v1_window_theme_type(uint32_t type)
{

}

void PersonalizationAppearanceContext::treeland_personalization_appearance_context_v1_window_titlebar_height(uint32_t height)
{
    m_interface->m_titleHeight = height;
    emit m_interface->q_func()->titleHeightChanged(height);
}

PersonalizationCursorContext::PersonalizationCursorContext(struct ::treeland_personalization_cursor_context_v1 *context, DTreelandPlatformInterfacePrivate *interface)
    : QWaylandClientExtensionTemplate<PersonalizationCursorContext>(1)
    , QtWayland::treeland_personalization_cursor_context_v1(context)
    , m_interface(interface)
{
    get_theme();
}

void PersonalizationCursorContext::treeland_personalization_cursor_context_v1_theme(const QString &name)
{
    m_interface->m_cursorThemeName = name.toUtf8();
    emit m_interface->q_func()->cursorThemeNameChanged(name.toUtf8());
}

PersonalizationFontContext::PersonalizationFontContext(struct ::treeland_personalization_font_context_v1 *context, DTreelandPlatformInterfacePrivate *interface)
    : QWaylandClientExtensionTemplate<PersonalizationFontContext>(1)
    , QtWayland::treeland_personalization_font_context_v1(context)
    , m_interface(interface)
{
    get_font();
    get_monospace_font();
    get_font_size();
}

void PersonalizationFontContext::treeland_personalization_font_context_v1_font(const QString &font_name)
{
    m_interface->m_fontName = font_name.toUtf8();
    emit m_interface->q_func()->fontNameChanged(font_name.toUtf8());
}

void PersonalizationFontContext::treeland_personalization_font_context_v1_monospace_font(const QString &font_name)
{
    m_interface->m_monoFontName = font_name.toUtf8();
    emit m_interface->q_func()->monoFontNameChanged(font_name.toUtf8());
}

void PersonalizationFontContext::treeland_personalization_font_context_v1_font_size(uint32_t font_size)
{
    constexpr qreal scaleFactor = 96.0 / 72.0;
    qreal pointSize = font_size * scaleFactor + 0.5;
    m_interface->m_fontPointSize = pointSize;
    emit m_interface->q_func()->fontPointSizeChanged(pointSize);
}

DGUI_END_NAMESPACE
