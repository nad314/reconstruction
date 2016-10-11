#include <main/main.h>

Controller& Controller::updateViewMatrix() {
	view.modelview = rotation*translation;
	return *this;
}
