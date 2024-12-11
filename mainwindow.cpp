#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);

	centralWidget = new QWidget(this);

	layout = new QVBoxLayout(centralWidget);
    mainView = new MainView(this);
	btnClassify = new QPushButton("Classify", this);

	setWindowTitle("Kohonen Image Classifier");

	layout->addWidget(mainView);
	layout->addWidget(btnClassify);

	setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{

}
