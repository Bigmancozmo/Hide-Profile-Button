#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;
		
		auto btn = this->getChildByID("profile-menu");
		auto username = this->getChildByID("player-username");
		auto isEnabled = Mod::get()->getSettingValue<bool>("enabled");

		if (isEnabled) {
			btn->setVisible(false);
			username->setVisible(false);
		}

		return true;
	} 
};