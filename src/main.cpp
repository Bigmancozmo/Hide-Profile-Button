#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/modify/GJGarageLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;
		
		auto btn = this->getChildByID("profile-menu");
		auto username = this->getChildByID("player-username");
		auto hideButton = Mod::get()->getSettingValue<bool>("hide-button");
		auto hideName = Mod::get()->getSettingValue<bool>("hide-name");

		btn->setVisible(!hideButton);
		username->setVisible(!hideName);

		return true;
	} 
};

class $modify(ProfilePage) {
	bool init(int accId, bool isSelf) {
		if (!ProfilePage::init(accId, isSelf)) return false;
		auto hideOnProfile = Mod::get()->getSettingValue<bool>("hide-profile-page");
		auto visible = !(isSelf && hideOnProfile);
		auto menu = this->getChildByType<CCLayer>(0);
		auto nameMenu = menu->getChildByID("username-menu");
		auto nameText = nameMenu->getChildByID("username-label");
		nameText->setVisible(visible);

		return true;
	}
};

class $modify(GJGarageLayer) {
	bool init() {
		if(!GJGarageLayer::init()) return false;
		auto usernameLabel = this->getChildByID("username-label");
		auto hideOnGarage = Mod::get()->getSettingValue<bool>("hide-icon-kit");
		usernameLabel->setVisible(!hideOnGarage);
		
		return true;
	}
};
