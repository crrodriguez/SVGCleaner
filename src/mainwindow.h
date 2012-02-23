#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QTime>
#include <QSettings>

#include "arguments.h"
#include "cleanerthread.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    float compressMax;
    float compressMin;
    float timeFull;
    float inputSize;
    float outputSize;
    int position;
    int timeMax;
    int timeMin;
    QComboBox *cmbSort;
    QList<CleanerThread *> cleanerList;
    QList<SVGInfo> itemList;
    QSettings *settings;
    QTime time;
    ToThread arguments;

    void createStatistics();
    void deleteThreads();
    void enableButtons(bool value);
    void removeThumbs();
    void startNext();

private slots:
    void cleaningFinished();
    void errorHandler(const QString &text);
    void on_actionCompareView_triggered();
    void on_actionInfo_triggered();
    void on_actionPause_triggered();
    void on_actionStart_triggered();
    void on_actionStop_triggered();
    void on_actionWizard_triggered();
    void on_itemScroll_valueChanged(int value);
    void prepareStart();
    void progress(SVGInfo);
    void sortingChanged(int value);

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void closeEvent(QCloseEvent *);
    void resizeEvent(QResizeEvent *);
};

#endif // MAINWINDOW_H
