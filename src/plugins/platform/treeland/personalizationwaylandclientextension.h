// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once
#include <QtWaylandClient/QWaylandClientExtension>
#include <QWindow>
#include "plugins/platform/treeland/dtreelandplatforminterface.h"
#include "qwayland-treeland-personalization-manager-v1.h"
#include <dtkgui_global.h>
#include <qcolor.h>
#include <qhash.h>
#include <qobjectdefs.h>
#include <qscopedpointer.h>
#include <qwaylandclientextension.h>
#include <private/qwaylanddisplay_p.h>
#include <QWaylandClientExtensionTemplate>
DGUI_BEGIN_NAMESPACE
class PersonalizationAppearanceContext;
class PersonalizationCursorContext;
class PersonalizationFontContext;
class DTreelandPlatformInterfacePrivate;
class PersonalizationManager: public QWaylandClientExtensionTemplate<PersonalizationManager>,
                              public QtWayland::treeland_personalization_manager_v1
{
    Q_OBJECT
public:
    static PersonalizationManager *instance();
protected:
    explicit PersonalizationManager();
private:
    void addListener();
    void removeListener();
    static void handleListenerGlobal(void *data, wl_registry *registry, uint32_t id, const QString &interface, uint32_t version);
private:
    QtWaylandClient::QWaylandDisplay *m_waylandDisplay;
};
class PersonalizationWindowContext : public QWaylandClientExtensionTemplate<PersonalizationWindowContext>,
                                     public QtWayland::treeland_personalization_window_context_v1
{
    Q_OBJECT
public:
    explicit PersonalizationWindowContext(struct ::treeland_personalization_window_context_v1 *context, DTreelandPlatformInterfacePrivate *inteface);
    bool noTitlebar() const; 
    void setNoTitlebar(bool enable);
    int windowRadius();
    void setWindowRadius(int radius);
private:
    DTreelandPlatformInterfacePrivate *m_interface;
};
class PersonalizationAppearanceContext : public QWaylandClientExtensionTemplate<PersonalizationAppearanceContext>,
                                         public QtWayland::treeland_personalization_appearance_context_v1
{
    Q_OBJECT
public:
    explicit PersonalizationAppearanceContext(struct ::treeland_personalization_appearance_context_v1 *context, DTreelandPlatformInterfacePrivate *interface);
protected:
    void treeland_personalization_appearance_context_v1_round_corner_radius(int32_t radius) override;
    void treeland_personalization_appearance_context_v1_icon_theme(const QString &theme_name) override;
    void treeland_personalization_appearance_context_v1_active_color(const QString &active_color) override;
    void treeland_personalization_appearance_context_v1_window_opacity(uint32_t opacity) override;
    void treeland_personalization_appearance_context_v1_window_theme_type(uint32_t type) override;
    void treeland_personalization_appearance_context_v1_window_titlebar_height(uint32_t height) override;
private:
    DTreelandPlatformInterfacePrivate *m_interface;
};
class PersonalizationCursorContext : public QWaylandClientExtensionTemplate<PersonalizationCursorContext>,
                                     public QtWayland::treeland_personalization_cursor_context_v1
{
    Q_OBJECT
public:
    explicit PersonalizationCursorContext(struct ::treeland_personalization_cursor_context_v1 *context, DTreelandPlatformInterfacePrivate *interface);
protected:
    void treeland_personalization_cursor_context_v1_theme(const QString &name) override;
private:
    DTreelandPlatformInterfacePrivate *m_interface;
};
class PersonalizationFontContext : public QWaylandClientExtensionTemplate<PersonalizationFontContext>,
                                   public QtWayland::treeland_personalization_font_context_v1
{
    Q_OBJECT
public:
    explicit PersonalizationFontContext(struct ::treeland_personalization_font_context_v1 *context, DTreelandPlatformInterfacePrivate *interface);
protected:
    void treeland_personalization_font_context_v1_font(const QString &font_name) override;
    void treeland_personalization_font_context_v1_monospace_font(const QString &font_name) override;
    void treeland_personalization_font_context_v1_font_size(uint32_t font_size) override;
private:
    DTreelandPlatformInterfacePrivate *m_interface;
};
DGUI_END_NAMESPACE
