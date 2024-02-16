#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;
		
		auto btn = this->getChildByID("profile-menu");
		auto username = this->getChildByID("player-username");
		auto isEnabled = Mod::get()->getSettingValue<bool>("enabled");
		auto nameOnly = Mod::get()->getSettingValue<bool>("name-only");
		
		if(isEnabled){
			btn->setVisible(nameOnly);
			username->setVisible(false);
		}

		return true;
	} 
};
