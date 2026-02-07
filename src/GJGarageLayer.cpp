#include <Geode/Geode.hpp>
#include <Geode/modify/GJGarageLayer.hpp>

using namespace geode::prelude;

class $modify(GJGarageLayer) {
	bool init() {
		if(!GJGarageLayer::init()) return false;
		auto usernameLabel = this->getChildByID("username-label");
		auto hideOnGarage = Mod::get()->getSettingValue<bool>("hide-icon-kit");
		usernameLabel->setVisible(!hideOnGarage);
		
		return true;
	}
};
