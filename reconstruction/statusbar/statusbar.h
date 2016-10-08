#pragma once

class Statusbar final : public core::Form, public core::Debugger, public core::Getter<Statusbar> {
protected:
	FILE* output;
	char text[256];
	std::mutex iomutex;
public:
	core::ProgBar progBar;
	Statusbar() :Form(), Debugger() {
		set(*this);
		core::Debug::attach(this);
		core::Debug::enable();
		core::Path::pushDir();
		core::Path::goHome();
		core::Path::cd("../data/");
		output = fopen((core::Path::getDir() + "\\log.txt").c_str(), "w");
		core::Path::popDir();
	}
	~Statusbar() { fclose(output); }
	void onOpening() override;
	void onOpened() override;

	void onStartPaint(const core::eventInfo& e) override;
	void onEndPaint(const core::eventInfo& e) override;
	int onResize(const core::eventInfo& e) override;
	void print(const char* s) override;
	void log(const char* s) override;
	void info(const char* s) override;
	void error(const char* s) override;

	static void prog(const float& amount);
};
