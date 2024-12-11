#include "events.h"


Events::Events()
{
}

Events::~Events()
{
}

MainView::MainView(QWidget* parent) : QGraphicsView(parent)
{
	scene = new QGraphicsScene(this);
	setAcceptDrops(true);
	setAlignment(Qt::AlignCenter | Qt::AlignTop);
	setScene(scene);
}

MainView::~MainView()
{
}

void MainView::dragEnterEvent(QDragEnterEvent *event)
{
	if (event->mimeData()->hasUrls()) {
		event->acceptProposedAction();
	}
	else {
		event->ignore();
	}
}

void MainView::dragLeaveEvent(QDragLeaveEvent* event)
{
}	


void MainView::dragMoveEvent(QDragMoveEvent* event)
{
}	

void MainView::dropEvent(QDropEvent* event) {
	const QMimeData* mimeData = event->mimeData();
	if (mimeData->hasUrls()) {
		QUrl url = mimeData->urls().at(0);
		if (!url.isEmpty()) {
			QString filename = url.toLocalFile();
			QFileInfo fileinfo(filename);

			if (fileinfo.suffix().toLower().contains("png") ||
				fileinfo.suffix().toLower().contains("img") ||
					fileinfo.suffix().toLower().contains("jpeg") ||
						fileinfo.suffix().toLower().contains("gif")) {
				QPixmap pixmap(filename);
				if (!pixmap.isNull()) {
					QGraphicsPixmapItem* item = new QGraphicsPixmapItem(pixmap);
					scene->addItem(item);
				}
			}
		}
	}
}