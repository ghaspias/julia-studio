/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2012 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: http://www.qt-project.org/
**
**
** GNU Lesser General Public License Usage
**
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** Other Usage
**
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**************************************************************************/

#ifndef ADDTOOLCHAINOPERATION_H
#define ADDTOOLCHAINOPERATION_H

#include "operation.h"

#include <QString>

class AddToolChainOperation : public Operation
{
public:
    QString name() const;
    QString helpText() const;
    QString argumentsHelpText() const;

    bool setArguments(const QStringList &args);

    int execute() const;

#ifdef WITH_TESTS
    bool test() const;
#endif

    static QVariantMap addToolChain(const QVariantMap &map,
                                    const QString &id, const QString &displayName,
                                    const QString &path, const QString &abi,
                                    const QString &supportedAbis,
                                    const KeyValuePairList &extra);

    static QVariantMap initializeToolChains();

private:
    QString m_id;
    QString m_displayName;
    QString m_path;
    QString m_targetAbi;
    QString m_supportedAbis;
    KeyValuePairList m_extra;
};

#endif // ADDTOOLCHAINOPERATION_H