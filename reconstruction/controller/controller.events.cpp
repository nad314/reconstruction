#include <main/main.h>

int Controller::onResize(const core::eventInfo& e) {
	EventListener::onResize(e);
	GL::ortho(*parent);
	view.perspective(*parent, 45.0f, 0.1f, 100.0f);
	invalidate();
	return e;
}

int Controller::onMouseMove(const core::eventInfo& e) {
	return EventListener::onMouseMove(e);
}

int Controller::onLButtonDown(const core::eventInfo& e) {
	return EventListener::onLButtonDown(e);
}

int Controller::onLButtonUp(const core::eventInfo& e) {
	return EventListener::onLButtonUp(e);
}
