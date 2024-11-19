// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef DPLATFORMINTERFACE_H
#define DPLATFORMINTERFACE_H

#include <QObject>
#include <QVariant>
#include <QWindow>

#include "dtkgui_global.h"
#include <dobject.h>
#include <qcolor.h>
#include <qglobal.h>
#include <qobjectdefs.h>

DGUI_BEGIN_NAMESPACE

class DPlatformInterfacePrivate;
class DPlatformInterface : public QObject, public DCORE_NAMESPACE::DObject
{
    Q_OBJECT
    D_DECLARE_PRIVATE(DPlatformInterface)
public:
    explicit DPlatformInterface(QObject *parent);
    virtual ~DPlatformInterface();

    virtual bool isEnabledNoTitlebar(QWindow *window) const;
    virtual bool setEnabledNoTitlebar(QWindow *window, bool enable);

    virtual int windowRadius() const;
    virtual void setWindowRadius(int windowRadius);

    virtual QByteArray fontName() const;
    virtual void setFontName(const QByteArray &fontName);

    virtual QByteArray monoFontName() const;
    virtual void setMonoFontName(const QByteArray &monoFontName);

    virtual QByteArray iconThemeName() const;
    virtual void setIconThemeName(const QByteArray &iconThemeName);

    virtual QByteArray cursorThemeName() const;
    virtual void setCursorThemeName(const QByteArray &cursorThemeName);

    virtual QColor activeColor() const;
    virtual void setActiveColor(const QColor &color);

    virtual int titleHeight() const;
    virtual void setTitleHeight(const int titleHeight);

    virtual qreal fontPointSize() const;
    virtual void setFontSize(const qreal fontSize);

    virtual int scrollBarPolicy() const;
    virtual void setScrollBarPolicy(const int scrollBarPolicy);

    static DPlatformInterface* self(QObject *parent);

signals:
    void activeColorChanged(const QColor &color);
    void titleHeightChanged(int height);
    void fontNameChanged(const QByteArray &name);
    void monoFontNameChanged(const QByteArray &name);
    void iconThemeNameChanged(const QByteArray &name);
    void cursorThemeNameChanged(const QByteArray &name);
    void fontPointSizeChanged(qreal fontPointSize);
    void windowRadiusChanged(int r);
    void scrollBarPolicyChanged(int scrollBarPolicy);

protected:
    DPlatformInterface(DPlatformInterfacePrivate &dd, QObject *parent);
};

DGUI_END_NAMESPACE
#endif
