#include <main/main.h>

Controller* core::Getter<Controller>::getter = NULL;

Controller::Controller(core::Window& wnd, Storage& data) {
	parent = &wnd;
	lpData = &data;
	valid = 0;
	wnd.attach(this);
}

Controller::~Controller() {
	parent->detach();
}

void Controller::drawScene() {
	if (valid) return;
	glClear(GL_COLOR_BUFFER_BIT);
	GL::swapBuffers(*parent);
	valid = 1;
}