#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MiMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto spr = ButtonSprite::create("Mi boton");
        auto btn = CCMenuItemSpriteExtra::create(
            spr, this, menu_selector(MiMenuLayer::onMiBoton)
        );

        auto menu = CCMenu::create();
        menu->addChild(btn);
        menu->setPosition(
            CCDirector::get()->getWinSize().width / 2, 40.f
        );
        this->addChild(menu);

        return true;
    }

    void onMiBoton(CCObject*) {
        FLAlertLayer::create(
            "Mi mod", "Funciona! Este es mi primer mod.", "OK"
        )->show();
    }
};
