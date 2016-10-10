#include <main/main.h>

int Program::onLoad() {
	core::Theme::formActiveBorderColor = Color(236, 226, 198, 255);
	return 0;
}

int Program::onDispose() {
	return 0;
}

int Program::onStart() {
	if (!wnd.open())
		return 1;
	glExt::init();
	lpData = new Storage;
	controller = new Controller(wnd.renderWindow, *lpData);
	return 0;
}

int Program::onStop() {
	delete controller;
	delete lpData;
	wnd.close();
	return 0;
}

int Program::main() {
	bool done(0);
	while (!done) {
		if (wnd.peekMessageAsync(done))
			continue;
		controller->drawScene();
		Sleep(1);
	}
	return 0;
}
