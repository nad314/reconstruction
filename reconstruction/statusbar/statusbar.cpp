#include <main/main.h>

Statusbar* core::Getter<Statusbar>::getter = NULL;


void Statusbar::onOpening() {
	Form::onOpening();
	setSize(256, 256);
	setStyle(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
	setBackColor(core::Theme::controlBackColor);
	memset(text, 0, 256);
}

void Statusbar::onOpened() {
	Form::onOpened();
	setBackColor(Theme::FormBackColor);
	push(progBar.make(vec4i(0, 0, 200, 20), *this));
	setControlColors();
	progBar.setColor(core::Theme::formActiveBorderColor);
}

void Statusbar::onStartPaint(const core::eventInfo& e) {
	__invalidate();
	Form::onStartPaint(e);
}

void Statusbar::onEndPaint(const core::eventInfo& e) {
	Form::onEndPaint(e);
	core::Font::get().print(text, *this, 4, 4);
}

int Statusbar::onResize(const core::eventInfo& e) {
	Form::onResize(e);
	progBar.move(Rect(width - Theme::sidebarW + 3, 2, width - 3, height - 2));
	return 0;
}

void Statusbar::print(const char* s) {
	static std::mutex mutex;
	std::lock_guard<std::mutex> lock(mutex);
	strcpy(text, s);
	int n = strlen(text);
	for (int i = 0; i < n; ++i)
		if (text[i] == '\n')
			text[i] = ' ';
	invalidate();
	log(s);
}

void Statusbar::log(const char* s) {
	std::lock_guard<std::mutex> lock(iomutex);
	fprintf(output, s);
}

void Statusbar::info(const char* s) {
	std::lock_guard<std::mutex> lock(iomutex);
	fprintf(output, s);
}

void Statusbar::error(const char* s) {
	std::lock_guard<std::mutex> lock(iomutex);
	fprintf(output, s);
}

void Statusbar::prog(const float& amount) {
	static std::mutex mutex;
	std::lock_guard<std::mutex> lock(mutex);
	get().progBar.set(amount);
}

