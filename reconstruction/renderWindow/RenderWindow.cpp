#include <main\main.h>

void RenderWindow::onOpening() {
	setTitle("Render Form");
	setClass("RenderForm");
	setStyle(WS_CHILD | WS_VISIBLE);
	setFlags(0);
}

void RenderWindow::onOpened() {
	if (width == 0 || height == 0)
		return;
}
