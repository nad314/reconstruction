#include <main/main.h>

int Controller::onResize(const core::eventInfo& e) {
	parent->onResize(e);
	core::Debug::print("%d %d", parent->width, parent->height);

	GL::ortho(*parent);
	view.perspective(*parent, 45.0f, 0.1f, 100.0f);
	invalidate();
	return e;
}
