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

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "lilypondrunner.h"
#include "staffdisplay.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LilyPondRunner runner;
    runner.addData("\\relative c {\\clef bass\n  \\time 4/4\n  \\key d \\minor\n  a4 r r r\n}");
    runner.addData("\\relative c {\\clef bass\n  \\time 4/4\n  \\key d \\minor\n  a4 b c d\n}");

    this->ui->staffDisplay->setTmpdir(runner.getTmpdir());
    this->ui->staffDisplay->setRows(2);
    this->ui->staffDisplay->setMax_rows(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

