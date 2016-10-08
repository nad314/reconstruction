#pragma once
class MainWindow final : public core::WindowForm {
public:
	RenderWindow renderWindow;
	Statusbar statusbar;
public:
	void onOpening() override;
	void onClosing() override;
	void onOpened() override;
	void onClosed() override;

	int onResize(const core::eventInfo& e) override;
	int resizeChildWindows();
};
