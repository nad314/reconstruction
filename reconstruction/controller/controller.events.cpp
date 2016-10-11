#include <main/main.h>

int Controller::onResize(const core::eventInfo& e) {
	EventListener::onResize(e);
	GL::ortho(*parent);
	view.perspective(*parent, 45.0f, 0.1f, 100.0f);
	invalidate();
	return e;
}

int Controller::onMouseMove(const core::eventInfo& e) {
	mouse.lp = mouse.p;
	mouse.p = vec2i(e.x(), e.y());
	if (mouse.state & 1) {
		matrixf rot;
		matrixf tinv = translation;
		tinv.invert();
		rot.rotate((float)mouse.dx()*0.5f, 0.0f, 1.0f, 0.0f);
		rot.rotate((float)mouse.dy()*0.5f, 1.0f, 0.0f, 0.0f);
		rot = translation*rot*tinv;
		rotation = rotation*rot;
		updateViewMatrix();
		invalidate();
	}
	else if (mouse.state & 2) {
		translation.translate((float)mouse.dx()*0.1f, -(float)mouse.dy()*0.1f, 0.0f);
		updateViewMatrix();
		invalidate();
	}
	return 0;
}

int Controller::onLButtonDown(const core::eventInfo& e) {
	mouse.state |= 1;
	SetCapture(*parent);
	return 0;
}

int Controller::onLButtonUp(const core::eventInfo& e) {
	mouse.state &= ~1;
	ReleaseCapture();
	return 0;
}

int Controller::onRButtonDown(const core::eventInfo& e) {
	mouse.state |= 2;
	SetCapture(*parent);
	return 0;
}

int Controller::onRButtonUp(const core::eventInfo& e) {
	mouse.state &= ~2;
	ReleaseCapture();
	return 0;
}