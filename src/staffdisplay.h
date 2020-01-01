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

#ifndef STAFFDISPLAY_H
#define STAFFDISPLAY_H

#include <QWidget>
#include <QString>
#include <QSvgWidget>
#include <QList>

namespace Ui {
class StaffDisplay;
}

class StaffDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit StaffDisplay(QWidget *parent = nullptr);
    ~StaffDisplay();
    Q_PROPERTY(int rows WRITE setRows READ getRows NOTIFY rowsChanged);
    Q_PROPERTY(int max_rows WRITE setMax_rows READ getMax_rows NOTIFY max_rowsChanged);
    Q_PROPERTY(int bpm WRITE setBpm READ getBpm NOTIFY bpmChanged);
    Q_PROPERTY(int bpb WRITE setBpb READ getBpb NOTIFY bpbChanged);
    Q_PROPERTY(QString tmpdir WRITE setTmpdir READ getTmpdir NOTIFY tmpdirChanged);
public slots:
    void setRows(int);
    int getRows();
    void setMax_rows(int);
    int getMax_rows();
    void setBpm(int);
    int getBpm();
    void setBpb(int);
    int getBpb();
    void setTmpdir(QString);
    QString getTmpdir();

signals:
    void rowsChanged(int);
    void max_rowsChanged(int);
    void bpmChanged(int);
    void bpbChanged(int);
    void tmpdirChanged(QString);

private:
    Ui::StaffDisplay *ui;
    QString tmpdir;
    int rows; // Rows to display
    int max_rows; // Rows that exist
    int bpm; //Beats per minute
    int bpb; //Beats per bar
    QList<QSvgWidget*> widgets;
};

#endif // STAFFDISPLAY_H
