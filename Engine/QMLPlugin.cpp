/*
    OpenSR - opensource multi-genre game based upon "Space Rangers 2: Dominators"
    Copyright (C) 2015 Kosyak <ObKo@mail.ru>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "QMLPlugin.h"

#include "QMLHelper.h"

#include <OpenSR/QM/QM.h>

#include <OpenSR/Engine.h>
#include <OpenSR/ResourceManager.h>
#include <OpenSR/Sound.h>
#include <OpenSR/GAIAnimatedImage.h>
#include <OpenSR/QMLQuestPlayer.h>
#include <OpenSR/TexturedPolyline.h>
#include <OpenSR/Music.h>

#include <QtQml>
#include <QVariant>

static QObject* engineSingletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    OpenSR::Engine *e = qobject_cast<OpenSR::Engine*>(qApp);
    QQmlEngine::setObjectOwnership(e, QQmlEngine::CppOwnership);
    return e;
}

static QObject* osrSingletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    return new OpenSR::QML::QMLHelper(engine);
}

void OpenSRPlugin::registerTypes(const char* uri)
{
    using namespace OpenSR;
    qmlRegisterSingletonType<Engine>(uri, 1, 0, "Engine", engineSingletonProvider);
    qmlRegisterSingletonType<OpenSR::QML::QMLHelper>(uri, 1, 0, "OSR", osrSingletonProvider);
    qmlRegisterType<Sound>(uri, 1, 0, "Sound");
    qmlRegisterType<GAIAnimatedImage>(uri, 1, 0, "GAIAnimatedImage");
    qmlRegisterType<QMLQuestPlayer>(uri, 1, 0, "QuestPlayer");
    qmlRegisterType<Music>(uri, 1, 0, "Music");
    qmlRegisterType<TexturedPolyline>(uri, 1, 0, "TexturedPolyline");
}

