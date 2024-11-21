// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
#ifndef DTREELANDPLATFORMINTERFACE_H
#define DTREELANDPLATFORMINTERFACE_H
#include "plugins/dplatforminterface.h"
DGUI_BEGIN_NAMESPACE
class DTreelandPlatformInterfacePrivate;
class DTreelandPlatformInterface : public DPlatformInterface
{
    Q_OBJECT
    D_DECLARE_PRIVATE(DTreelandPlatformInterface)
public:
    explicit DTreelandPlatformInterface(QObject *parent);
    // bool isEnabledNoTitlebar(QWindow *window) const override;
    // bool setEnabledNoTitlebar(QWindow *window, bool enable) override;
    int windowRadius() const override;
    void setWindowRadius(int windowRadius) override;
    QByteArray fontName() const override;
    void setFontName(const QByteArray &fontName) override;
    QByteArray monoFontName() const override;
    void setMonoFontName(const QByteArray &monoFontName) override;
    QByteArray iconThemeName() const override;
    void setIconThemeName(const QByteArray &iconThemeName) override;
    // QByteArray cursorThemeName() const override;
    // void setCursorThemeName(const QByteArray &cursorThemeName) override;
    QColor activeColor() const override;
    void setActiveColor(const QColor color) override;
    // int titleHeight() const override;
    // void setTitleHeight(int titleHeight) override;
    qreal fontPointSize() const override;
    void setFontPointSize(const qreal fontSize) override;
    // int scrollBarPolicy() const override;
    // void setScrollBarPolicy(const int scrollBarPolicy) override;
};
DGUI_END_NAMESPACE
#endif