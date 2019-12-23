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
along with Trabucco.  If not, see <http://www.gnu.org/licenses/>.

Copyright (C) 2019  Salvo "LtWorf" Tomaselli
*/

#include "lilypondrunner.h"

#include <QStringList>

LilyPondRunner::LilyPondRunner(QObject *parent) : QObject(parent)
{
}

int LilyPondRunner::addData(QString data) {
    QStringList params;
    params << "-dsafe";
    params << "-dbackend=svg";
    params << "-o" << QString::number(this->counter);
    params << "-";

    QProcess* worker = new QProcess(this);
    worker->setWorkingDirectory(tmpdir.path());

    worker->start("lilypond", params, QIODevice::WriteOnly);

    worker->write(data.toUtf8());

    //Read the data and destroy when it is done

    workers.append(worker);
    results.append("");

    return this->counter++;
}

QString LilyPondRunner::getData(int id) {
    //TODO boundary check
    return results[id];
}
