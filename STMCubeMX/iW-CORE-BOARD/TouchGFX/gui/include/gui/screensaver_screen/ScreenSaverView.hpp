#ifndef SCREENSAVERVIEW_HPP
#define SCREENSAVERVIEW_HPP

#include <gui_generated/screensaver_screen/ScreenSaverViewBase.hpp>
#include <gui/screensaver_screen/ScreenSaverPresenter.hpp>
#include <gui/screensaver_screen/ParticleEffect.hpp>

class ScreenSaverView : public ScreenSaverViewBase
{
public:
    ScreenSaverView();
    virtual ~ScreenSaverView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

protected:
    ParticleEffect particleEffect;
    static const uint16_t WAITTOENDSCREEN_DURATION = 72;
    uint16_t waitToEndScreenCounter;

    virtual void endScreenSaverAnimation();
};

#endif // SCREENSAVERVIEW_HPP
