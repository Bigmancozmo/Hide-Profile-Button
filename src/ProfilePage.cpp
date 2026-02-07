#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

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
