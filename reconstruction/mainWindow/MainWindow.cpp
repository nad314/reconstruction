#include <main/main.h>

void MainWindow::onOpening() {
	setTitle("Surface Reconstruction Software");
	WindowForm::onOpening();
}

void MainWindow::onOpened() {
	WindowForm::onOpened();
	renderWindow.setParent(this);
	renderWindow.open();
	renderWindow.move(vec4i(8, 38, width - 8, height - 8));

}

void MainWindow::onClosing() {
	renderWindow.close();
	WindowForm::onClosing();
}

void MainWindow::onClosed() {
	WindowForm::onClosed();
}

int MainWindow::onResize(const core::eventInfo& e) {
	WindowForm::onResize(e);
	renderWindow.move(vec4i(8, 38, width - 8, height - 8));
	return 0;
}
