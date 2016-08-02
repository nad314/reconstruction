#pragma once
class MainWindow final : public core::WindowForm {
protected:
public:
	void onOpening() override;
	void onClosing() override;
	void onOpened() override;
	void onClosed() override;
};
