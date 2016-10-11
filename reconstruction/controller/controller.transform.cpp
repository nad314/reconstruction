#include <main/main.h>

Controller& Controller::updateViewMatrix() {
	view.modelview = rotation*translation*zoom;
	return *this;
}

Controller& Controller::initTransform() {
	rotation.init();
	translation.init();
	zoom.init();
	zoom.translate(0.0f, 0.0f, -50.0f);
	return *this;
}