#pragma once

class MainMenu : public core::Form {
public:
	core::MenuButton file;
	core::MenuButton filter;

	core::DropdownMenu filterMenu;

	void onOpening() override;
	void onOpened() override;
	void onClosing() override;
};
