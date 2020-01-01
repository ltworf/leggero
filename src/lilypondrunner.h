/*
This file is part of Leggero.

Leggero is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Trabucco is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Leggero.  If not, see <http://www.gnu.org/licenses/>.

Copyright (C) 2019-2020  Salvo "LtWorf" Tomaselli
*/

#ifndef LILYPONDRUNNER_H
#define LILYPONDRUNNER_H

#include <QObject>
#include <QString>
#include <QList>
#include <QProcess>
#include <QTemporaryDir>

class LilyPondRunner : public QObject
{
    Q_OBJECT
public:
    explicit LilyPondRunner(QObject *parent = nullptr);
    int addData(QString data);
    Q_PROPERTY(QString tmpdir READ getTmpdir CONSTANT);
public slots:
    QString getTmpdir();
private:
    int counter = 0;
    QTemporaryDir tmpdir;
    QList<QProcess*> workers;
signals:
    void ready(int id);
};

#endif // LILYPONDRUNNER_H
