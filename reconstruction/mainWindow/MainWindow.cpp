#include <main/main.h>

void MainWindow::onOpening() {
	setTitle("Surface Reconstruction Software");
	WindowForm::onOpening();
}

void MainWindow::onOpened() {
	WindowForm::onOpened();
	renderWindow.setParent(this);
	renderWindow.open();
	statusbar.setParent(this);
	statusbar.open();
	resizeChildWindows();
}

void MainWindow::onClosing() {
	statusbar.close();
	renderWindow.close();
	WindowForm::onClosing();
}

void MainWindow::onClosed() {
	WindowForm::onClosed();
}

int MainWindow::onResize(const core::eventInfo& e) {
	WindowForm::onResize(e);
	resizeChildWindows();
	return 0;
}

int MainWindow::resizeChildWindows() {
	renderWindow.move(vec4i(8, 38, width - 8, height - 26));
	statusbar.move(vec4i(2, height - 22, width - 2, height - 2));
	return 0;
}
