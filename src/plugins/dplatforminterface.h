// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef DPLATFORMINTERFACE_H
#define DPLATFORMINTERFACE_H

#include <QObject>
#include <QVariant>
#include <QWindow>

#include <DPalette>
#include <DObject>

#include "dtkgui_global.h"

DGUI_BEGIN_NAMESPACE

class DPlatformInterfacePrivate;
class DPlatformInterface : public QObject, public DCORE_NAMESPACE::DObject
{
    Q_OBJECT
    D_DECLARE_PRIVATE(DPlatformInterface)

    Q_PROPERTY(int cursorBlinkTime READ cursorBlinkTime WRITE setCursorBlinkTime NOTIFY cursorBlinkTimeChanged)
    Q_PROPERTY(int cursorBlinkTimeout READ cursorBlinkTimeout WRITE setCursorBlinkTimeout NOTIFY cursorBlinkTimeoutChanged)
    Q_PROPERTY(bool cursorBlink READ cursorBlink WRITE setCursorBlink NOTIFY cursorBlinkChanged)
    Q_PROPERTY(int doubleClickDistance READ doubleClickDistance WRITE setDoubleClickDistance NOTIFY doubleClickDistanceChanged)
    Q_PROPERTY(int doubleClickTime READ doubleClickTime WRITE setDoubleClickTime NOTIFY doubleClickTimeChanged)
    Q_PROPERTY(int dndDragThreshold READ dndDragThreshold WRITE setDndDragThreshold NOTIFY dndDragThresholdChanged)
    Q_PROPERTY(int windowRadius READ windowRadius WRITE setWindowRadius NOTIFY windowRadiusChanged)
    Q_PROPERTY(QByteArray themeName READ themeName WRITE setThemeName NOTIFY themeNameChanged)
    Q_PROPERTY(QByteArray iconThemeName READ iconThemeName WRITE setIconThemeName NOTIFY iconThemeNameChanged)
    Q_PROPERTY(QByteArray soundThemeName READ soundThemeName WRITE setSoundThemeName NOTIFY soundThemeNameChanged)
    // Font
    Q_PROPERTY(QByteArray fontName READ fontName WRITE setFontName NOTIFY fontNameChanged)
    Q_PROPERTY(QByteArray monoFontName READ monoFontName WRITE setMonoFontName NOTIFY monoFontNameChanged)
    Q_PROPERTY(qreal fontPointSize READ fontPointSize WRITE setFontPointSize NOTIFY fontPointSizeChanged)
    Q_PROPERTY(QByteArray gtkFontName READ gtkFontName WRITE setGtkFontName NOTIFY gtkFontNameChanged)

    Q_PROPERTY(QColor activeColor READ activeColor WRITE setActiveColor NOTIFY activeColorChanged)
    Q_PROPERTY(QColor darkActiveColor READ darkActiveColor WRITE setDarkActiveColor NOTIFY darkActiveColorChanged)
#if DTK_VERSION < DTK_VERSION_CHECK(6, 0, 0, 0)
    // QPalette
    Q_PROPERTY(QColor window READ window WRITE setWindow NOTIFY windowChanged)
    Q_PROPERTY(QColor windowText READ windowText WRITE setWindowText NOTIFY windowTextChanged)
    Q_PROPERTY(QColor base READ base WRITE setBase NOTIFY baseChanged)
    Q_PROPERTY(QColor alternateBase READ alternateBase WRITE setAlternateBase NOTIFY alternateBaseChanged)
    Q_PROPERTY(QColor toolTipBase READ toolTipBase WRITE setToolTipBase NOTIFY toolTipBaseChanged)
    Q_PROPERTY(QColor toolTipText READ toolTipText WRITE setToolTipText NOTIFY toolTipTextChanged)
    Q_PROPERTY(QColor text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QColor button READ button WRITE setButton NOTIFY buttonChanged)
    Q_PROPERTY(QColor buttonText READ buttonText WRITE setButtonText NOTIFY buttonTextChanged)
    Q_PROPERTY(QColor brightText READ brightText WRITE setBrightText NOTIFY brightTextChanged)
    Q_PROPERTY(QColor light READ light WRITE setLight NOTIFY lightChanged)
    Q_PROPERTY(QColor midlight READ midlight WRITE setMidlight NOTIFY midlightChanged)
    Q_PROPERTY(QColor dark READ dark WRITE setDark NOTIFY darkChanged)
    Q_PROPERTY(QColor mid READ mid WRITE setMid NOTIFY midChanged)
    Q_PROPERTY(QColor shadow READ shadow WRITE setShadow NOTIFY shadowChanged)
    Q_PROPERTY(QColor highlight READ highlight WRITE setHighlight NOTIFY highlightChanged)
    Q_PROPERTY(QColor highlightedText READ highlightedText WRITE setHighlightedText NOTIFY highlightedTextChanged)
    Q_PROPERTY(QColor link READ link WRITE setLink NOTIFY linkChanged)
    Q_PROPERTY(QColor linkVisited READ linkVisited WRITE setLinkVisited NOTIFY linkVisitedChanged)
    // DPalette
    Q_PROPERTY(QColor itemBackground READ itemBackground WRITE setItemBackground NOTIFY itemBackgroundChanged)
    Q_PROPERTY(QColor textTitle READ textTitle WRITE setTextTitle NOTIFY textTitleChanged)
    Q_PROPERTY(QColor textTips READ textTips WRITE setTextTips NOTIFY textTipsChanged)
    Q_PROPERTY(QColor textWarning READ textWarning WRITE setTextWarning NOTIFY textWarningChanged)
    Q_PROPERTY(QColor textLively READ textLively WRITE setTextLively NOTIFY textLivelyChanged)
    Q_PROPERTY(QColor lightLively READ lightLively WRITE setLightLively NOTIFY lightLivelyChanged)
    Q_PROPERTY(QColor darkLively READ darkLively WRITE setDarkLively NOTIFY darkLivelyChanged)
    Q_PROPERTY(QColor frameBorder READ frameBorder WRITE setFrameBorder NOTIFY frameBorderChanged)
#endif
    // DSizeMode
    Q_PROPERTY(int sizeMode READ sizeMode NOTIFY sizeModeChanged)
    Q_PROPERTY(int scrollBarPolicy READ scrollBarPolicy NOTIFY scrollBarPolicyChanged)

public:
    explicit DPlatformInterface(QObject *parent);
    virtual ~DPlatformInterface();

    virtual int cursorBlinkTime() const;
    virtual int cursorBlinkTimeout() const;
    virtual bool cursorBlink() const;
    virtual int doubleClickDistance() const;
    virtual int doubleClickTime() const;
    virtual int dndDragThreshold() const;
    virtual int windowRadius() const;
    virtual int windowRadius(int defaultValue) const;
    virtual QByteArray themeName() const;
    virtual QByteArray iconThemeName() const;
    virtual QByteArray soundThemeName() const;

    virtual QByteArray fontName() const;
    virtual QByteArray monoFontName() const;
    virtual qreal fontPointSize() const;
    virtual QByteArray gtkFontName() const;

    virtual QColor activeColor() const;
    virtual QColor darkActiveColor() const;

#if DTK_VERSION < DTK_VERSION_CHECK(6, 0, 0, 0)
    virtual QColor window() const;
    virtual QColor windowText() const;
    virtual QColor base() const;
    virtual QColor alternateBase() const;
    virtual QColor toolTipBase() const;
    virtual QColor toolTipText() const;
    virtual QColor text() const;
    virtual QColor button() const;
    virtual QColor buttonText() const;
    virtual QColor brightText() const;
    virtual QColor light() const;
    virtual QColor midlight() const;
    virtual QColor dark() const;
    virtual QColor mid() const;
    virtual QColor shadow() const;
    virtual QColor highlight() const;
    virtual QColor highlightedText() const;
    virtual QColor link() const;
    virtual QColor linkVisited() const;
    virtual QColor itemBackground() const;
    virtual QColor textTitle() const;
    virtual QColor textTips() const;
    virtual QColor textWarning() const;
    virtual QColor textLively() const;
    virtual QColor lightLively() const;
    virtual QColor darkLively() const;
    virtual QColor frameBorder() const;
#endif

    virtual int sizeMode() const;
    virtual int scrollBarPolicy() const;

public Q_SLOTS:
    virtual void setCursorBlinkTime(int cursorBlinkTime);
    virtual void setCursorBlinkTimeout(int cursorBlinkTimeout);
    virtual void setCursorBlink(bool cursorBlink);
    virtual void setDoubleClickDistance(int doubleClickDistance);
    virtual void setDoubleClickTime(int doubleClickTime);
    virtual void setDndDragThreshold(int dndDragThreshold);
    virtual void setThemeName(const QByteArray &themeName);
    virtual void setIconThemeName(const QByteArray &iconThemeName);
    virtual void setSoundThemeName(const QByteArray &soundThemeName);
    virtual void setFontName(const QByteArray &fontName);
    virtual void setMonoFontName(const QByteArray &monoFontName);
    virtual void setFontPointSize(qreal fontPointSize);
    virtual void setGtkFontName(const QByteArray &fontName);
    virtual void setActiveColor(const QColor activeColor);
    virtual void setDarkActiveColor(const QColor &activeColor);
#if DTK_VERSION < DTK_VERSION_CHECK(6, 0, 0, 0)
    virtual void setWindow(const QColor &window);
    virtual void setWindowText(const QColor &windowText);
    virtual void setBase(const QColor &base);
    virtual void setAlternateBase(const QColor &alternateBase);
    virtual void setToolTipBase(const QColor &toolTipBase);
    virtual void setToolTipText(const QColor &toolTipText);
    virtual void setText(const QColor &text);
    virtual void setButton(const QColor &button);
    virtual void setButtonText(const QColor &buttonText);
    virtual void setBrightText(const QColor &brightText);
    virtual void setLight(const QColor &light);
    virtual void setMidlight(const QColor &midlight);
    virtual void setDark(const QColor &dark);
    virtual void setMid(const QColor &mid);
    virtual void setShadow(const QColor &shadow);
    virtual void setHighlight(const QColor &highlight);
    virtual void setHighlightedText(const QColor &highlightedText);
    virtual void setLink(const QColor &link);
    virtual void setLinkVisited(const QColor &linkVisited);
    virtual void setItemBackground(const QColor &itemBackground);
    virtual void setTextTitle(const QColor &textTitle);
    virtual void setTextTips(const QColor &textTips);
    virtual void setTextWarning(const QColor &textWarning);
    virtual void setTextLively(const QColor &textLively);
    virtual void setLightLively(const QColor &lightLively);
    virtual void setDarkLively(const QColor &darkLively);
    virtual void setFrameBorder(const QColor &frameBorder);
#endif

    virtual int dotsPerInch(const QString &screenName = QString()) const;
    virtual void setDotsPerInch(const QString &screenName, int dpi);
    virtual void setWindowRadius(int windowRadius);

Q_SIGNALS:
    void cursorBlinkTimeChanged(int cursorBlinkTime);
    void cursorBlinkTimeoutChanged(int cursorBlinkTimeout);
    void cursorBlinkChanged(bool cursorBlink);
    void doubleClickDistanceChanged(int doubleClickDistance);
    void doubleClickTimeChanged(int doubleClickTime);
    void dndDragThresholdChanged(int dndDragThreshold);
    void themeNameChanged(QByteArray themeName);
    void iconThemeNameChanged(QByteArray iconThemeName);
    void soundThemeNameChanged(QByteArray soundThemeName);
    void fontNameChanged(QByteArray fontName);
    void monoFontNameChanged(QByteArray monoFontName);
    void fontPointSizeChanged(qreal fontPointSize);
    void gtkFontNameChanged(QByteArray fontName);
    void activeColorChanged(QColor activeColor);
    void darkActiveColorChanged(QColor activeColor);
    void paletteChanged(DPalette palette);
#if DTK_VERSION < DTK_VERSION_CHECK(6, 0, 0, 0)
    void windowChanged(QColor window);
    void windowTextChanged(QColor windowText);
    void baseChanged(QColor base);
    void alternateBaseChanged(QColor alternateBase);
    void toolTipBaseChanged(QColor toolTipBase);
    void toolTipTextChanged(QColor toolTipText);
    void textChanged(QColor text);
    void buttonChanged(QColor button);
    void buttonTextChanged(QColor buttonText);
    void brightTextChanged(QColor brightText);
    void lightChanged(QColor light);
    void midlightChanged(QColor midlight);
    void darkChanged(QColor dark);
    void midChanged(QColor mid);
    void shadowChanged(QColor shadow);
    void highlightChanged(QColor highlight);
    void highlightedTextChanged(QColor highlightedText);
    void linkChanged(QColor link);
    void linkVisitedChanged(QColor linkVisited);
    void itemBackgroundChanged(QColor itemBackground);
    void textTitleChanged(QColor textTitle);
    void textTipsChanged(QColor textTips);
    void textWarningChanged(QColor textWarning);
    void textLivelyChanged(QColor textLively);
    void lightLivelyChanged(QColor lightLively);
    void darkLivelyChanged(QColor darkLively);
    void frameBorderChanged(QColor frameBorder);
#endif
    void dotsPerInchChanged(const QString &screen, int dpi);
    void windowRadiusChanged(int r);
    void sizeModeChanged(int sizeMode);
    void scrollBarPolicyChanged(int scrollBarPolicy);

protected:
    DPlatformInterface(DPlatformInterfacePrivate &dd, QObject *parent);
};

DGUI_END_NAMESPACE
#endif
