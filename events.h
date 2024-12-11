#ifndef EVENTS_H
#define EVENTS_H
#pragma once
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QWidget>
#include <QMimeData>
#include <QUrl>
#include <QFileInfo>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QVBoxLayout>

class Events {
public:
	Events();
	~Events();
};

class MainView : public QGraphicsView {
	Q_OBJECT

public:
	explicit MainView(QWidget* parent = nullptr);
protected:
	~MainView();
	void dragEnterEvent(QDragEnterEvent* event);
	void dragMoveEvent(QDragMoveEvent* event);
	void dragLeaveEvent(QDragLeaveEvent* event);
	void dropEvent(QDropEvent* event);

private:
	QGraphicsScene* scene;
};

#endif // EVENTS_H