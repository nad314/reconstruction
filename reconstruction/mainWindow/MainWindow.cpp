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
	menu.setParent(this);
	menu.open();
	resizeChildWindows();
}

void MainWindow::onClosing() {
	menu.close();
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
	menu.move(vec4i(8, 30, width - 8, 50));
	renderWindow.move(vec4i(8, 54, width - 8, height - 26));
	statusbar.move(vec4i(2, height - 22, width - 2, height - 2));
	return 0;
}
