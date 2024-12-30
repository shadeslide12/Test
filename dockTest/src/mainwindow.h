#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSettings>
#include <QCloseEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        resize(800, 600);
        setWindowTitle("DockLayout");
        
        // 创建一个空的中央部件
        QWidget* centralWidget = new QWidget();
        centralWidget->setStyleSheet("background-color: white;");
        setCentralWidget(centralWidget);
        
        // 创建左侧面板
        QDockWidget *leftDock = new QDockWidget(this);
        leftDock->setAllowedAreas(Qt::LeftDockWidgetArea);
        leftDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
        QWidget* leftWidget = new QWidget();
        leftWidget->setStyleSheet("background-color: #4B6EAF;");
        leftDock->setWidget(leftWidget);
        leftDock->setFixedWidth(300);
        leftDock->setTitleBarWidget(new QWidget()); // 移除标题栏
        
        // 创建底部控制台
        QDockWidget *bottomDock = new QDockWidget("Console", this);
        
        // 允许在底部和右侧停靠
        bottomDock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::RightDockWidgetArea);
        bottomDock->setFeatures(
            QDockWidget::DockWidgetMovable | 
            QDockWidget::DockWidgetFloatable
        );
        
        QWidget* bottomWidget = new QWidget();
        bottomWidget->setStyleSheet("background-color: #FFB800;");
        bottomDock->setWidget(bottomWidget);
        bottomDock->setMinimumHeight(200);
        bottomDock->setMinimumWidth(200);
        
        // 添加 dock widgets
        addDockWidget(Qt::LeftDockWidgetArea, leftDock);
        addDockWidget(Qt::BottomDockWidgetArea, bottomDock);
        
        // 设置 dock 区域策略
        setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
        setCorner(Qt::BottomRightCorner, Qt::BottomDockWidgetArea);
        
        // 禁用 tabbing
        setDockOptions(dockOptions() & ~QMainWindow::AllowTabbedDocks);
        
        // 确保 dock 可见
        leftDock->show();
        bottomDock->show();
        
        // 恢复上次的布局状态
        QSettings settings("DockDemo", "DockLayout");
        if (settings.contains("mainWindowState")) {
            restoreState(settings.value("mainWindowState").toByteArray());
        }
    }

protected:
    void closeEvent(QCloseEvent *event) override
    {
        QSettings settings("DockDemo", "DockLayout");
        settings.setValue("mainWindowState", saveState());
        QMainWindow::closeEvent(event);
    }
};

#endif // MAINWINDOW_H