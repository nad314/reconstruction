#include <main/main.h>

int Controller::onResize(const core::eventInfo& e) {
	invalidate();
	return e;
}
