#pragma once
class MainWindow final : public core::WindowForm {
protected:
	RenderWindow renderWindow;
public:
	void onOpening() override;
	void onClosing() override;
	void onOpened() override;
	void onClosed() override;
};
