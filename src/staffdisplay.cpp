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

#include "staffdisplay.h"
#include "ui_staffdisplay.h"

StaffDisplay::StaffDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StaffDisplay)
{
    ui->setupUi(this);
}

StaffDisplay::~StaffDisplay()
{
    delete ui;
}

void StaffDisplay::setRows(int val) {
    if (val == this->rows)
        return;
    this->rows = val;
    emit this->rowsChanged(val);
}
int StaffDisplay::getRows() {
    return this->rows;
}
void StaffDisplay::setMax_rows(int val) {
    if (val == this->max_rows)
        return;
    this->max_rows = val;
    emit this->max_rowsChanged(val);

    for (int i=0; i< this->widgets.size(); i++) {
        delete widgets[i];
    }
    widgets.clear();

    for (int i = 0; i < val; i++) {
        QSvgWidget* w = new QSvgWidget(
                    this->tmpdir + "/" + QString::number(i) + ".svg",
                    this);
        this->widgets.append(w);
        this->ui->verticalLayout->addWidget(w);
    }
}
int StaffDisplay::getMax_rows() {
    return this->max_rows;
}
void StaffDisplay::setBpm(int val) {
    if (val == this->bpm)
        return;
    this->bpm = val;
    emit this->bpmChanged(val);
}
int StaffDisplay::getBpm() {
    return this->bpm;
}
void StaffDisplay::setBpb(int val) {
    if (val == this->bpb)
        return;
    this->bpb = val;
    emit this->bpbChanged(val);
}
int StaffDisplay::getBpb() {
    return this->bpb;
}
void StaffDisplay::setTmpdir(QString t) {
    if (t == this->tmpdir)
        return;
    this->tmpdir = t;
    emit this->tmpdirChanged(t);
}
QString StaffDisplay::getTmpdir() {
    return this->tmpdir;
}
