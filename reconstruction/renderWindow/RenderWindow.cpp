#include <main\main.h>

void RenderWindow::onOpening() {
	setTitle("Render Form");
	setStyle(WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
	setFlags(0);
}

void RenderWindow::onOpened() {
	if (width == 0 || height == 0)
		return;
	GL::init(*this);
}
