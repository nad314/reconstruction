#include <main/main.h>

void MainMenu::onOpening() {
	Form::onOpening();
	setStyle(WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
	if (parent) setSize(parent->width, 20);
}

void MainMenu::onOpened() {
	Form::onOpened();
	push(file.make(NULL, "File", *this));
	push(filter.make(&filterMenu, "Point Sets", *this));
	controlBorderColor = controlBackColor = backColor;
	
	filterMenu.pushVertical((new core::Button())->make(filterMenu.defRect, "Foo", filterMenu, [](core::Control& c, core::Form& f)->void {
		core::DropdownMenu& menu = dynamic_cast<core::DropdownMenu&>(f);
		menu.hide();
	}).setAlign(0));
	filterMenu.pushVertical((new core::Button())->make(filterMenu.defRect, "Bar", filterMenu, [](core::Control& c, core::Form& f)->void {
		core::DropdownMenu& menu = dynamic_cast<core::DropdownMenu&>(f);
		menu.hide();
	}).setAlign(0));
	filterMenu.pushVertical((new core::Button())->make(filterMenu.defRect, "LLS Normals", filterMenu, [](core::Control& c, core::Form& f)->void {
		core::DropdownMenu& menu = dynamic_cast<core::DropdownMenu&>(f);
		menu.hide();
	}).setAlign(0));
	filterMenu.setParent(this);

	setControlColors();
}

void MainMenu::onClosing() {
	filterMenu.close();
	Form::onClosing();
}
