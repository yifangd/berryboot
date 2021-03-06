/* Berryboot -- OS image export dialog
 *
 * Copyright (c) 2012, Floris Bos
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "exportdialog.h"
#include "ui_exportdialog.h"

ExportDialog::ExportDialog(bool allowSingleImage, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportDialog)
{
    ui->setupUi(this);

    if (!allowSingleImage)
    {
        ui->origRadio->setEnabled(false);
        ui->dataRadio->setEnabled(false);
    }
}

ExportDialog::~ExportDialog()
{
    delete ui;
}

bool ExportDialog::exportData() const
{
    return ui->dataRadio->isChecked();
}

bool ExportDialog::backupEverything() const
{
    return ui->backupRadio->isChecked();
}

QStringList ExportDialog::excludeList() const
{
    QString txt = ui->excludeEdit->toPlainText();
    txt.replace("\r", "");

    return txt.split("\n", QString::SkipEmptyParts);
}

void ExportDialog::on_dataRadio_toggled(bool checked)
{
    ui->excludeGroupbox->setEnabled(checked);
}
