#include <main/main.h>

Controller* core::Getter<Controller>::getter = NULL;

Controller::Controller(core::Window& wnd, Storage& data) {
	parent = &wnd;
	lpData = &data;
	valid = 0;
	wnd.attach(this);

	view.perspective(*parent, 45.0f, 0.1f, 100.0f);
	view.modelview.init();
	rotation.init();
	translation.init();
	translation.translate(0.0f, 0.0f, -50.0f);
	updateViewMatrix();

	glGetError();
	loc[0] = glExt::getUniformLocation(lpData->shader, "modelview");
	loc[1] = glExt::getUniformLocation(lpData->shader, "projection");
	if (glGetError())
		core::Debug::log("Error: couldn't get shader matrix uniform locations\n");
}

Controller::~Controller() {
	parent->detach();
}

void Controller::drawScene() {
	if (valid) return;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	Storage& data = *lpData;
	data.shader.start();
	view.sendTo(data.shader, loc[0], loc[1]);
	data.glCloud.draw();
	data.shader.stop();
	GL::swapBuffers(*parent);
	valid = 1;
}

Controller& Controller::updateViewMatrix() {
	view.modelview = rotation*translation;
	return *this;
}
