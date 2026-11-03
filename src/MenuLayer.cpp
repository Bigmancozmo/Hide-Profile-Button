#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;
		
		auto btn = this->m_profileButton;
		auto username = this->m_profileLabel;

		auto hideButton = Mod::get()->getSettingValue<bool>("hide-button");
		auto hideName = Mod::get()->getSettingValue<bool>("hide-name");

		btn->setVisible(!hideButton);
		username->setVisible(!hideName);

		return true;
	} 
};
