//
// Created by Shinelon on 2019/2/22.
//

#include "ProgressDialog.h"
#include <stdio.h>
#include <iostream>

using namespace std;

ProgressDialog::ProgressDialog(const QUrl &url, QWidget *parent)
        : QProgressDialog(parent) {
    setWindowTitle(tr("Download Progress"));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setLabelText(tr("Downloading %1.").arg(url.toDisplayString()));
    setMinimum(0);
    setValue(0);
    setMinimumDuration(0);
    setMinimumSize(QSize(400, 75));
}

void ProgressDialog::networkReplyProgress(qint64 bytesRead, qint64 totalBytes) {
    setMaximum(totalBytes);
    setValue(bytesRead);
}