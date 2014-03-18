#include "externalbrowse.h"
#include <QGridLayout>
#include <QLayout>

ExternalBrowse::ExternalBrowse(qint32 lid, QWidget *parent) :
    QMdiSubWindow(parent)
{
    setAttribute(Qt::WA_QuitOnClose, false);
    this->setWindowTitle(tr("NixNote"));
    setWindowIcon(QIcon(":windowIcon.png"));

    browser = new NBrowserWindow(this);
    setWidget(browser);

    browser->setContent(lid);
}


// We don't really close the window, we just hide it.  This
// solves problems later on if the user wants to re-open the same
// note in an external window.
void ExternalBrowse::closeEvent(QCloseEvent *closeEvent) {
    if (this->browser->editor->isDirty)
        this->browser->saveNoteContent();
    this->setVisible(false);
    closeEvent->ignore();
}