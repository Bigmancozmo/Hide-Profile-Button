#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

class $modify(ProfilePage) {
	bool init(int accId, bool isSelf) {
		if (!ProfilePage::init(accId, isSelf)) return false;

		auto nameText = this->m_usernameLabel;

		auto hideOnProfile = Mod::get()->getSettingValue<bool>("hide-profile-page");
		auto hide = isSelf && hideOnProfile;
		nameText->setVisible(!hide);

		return true;
	}
};
