#include <gui/screensaver_screen/ScreenSaverView.hpp>
#include <touchgfx/hal/HAL.hpp>

ScreenSaverView::ScreenSaverView() :
    particleEffect(), waitToEndScreenCounter(0)
{
    HAL::getInstance()->setFrameRateCompensation(true);
}

void ScreenSaverView::setupScreen()
{
    ScreenSaverViewBase::setupScreen();
    particleEffect.setPosition(0, 0, HAL::DISPLAY_WIDTH, HAL::DISPLAY_HEIGHT);
    particleEffect.setSnapToOrigin(true);
    particleEffect.setNumberOfParticles(180);
    particleEffect.setOrigin(particleEffect.getWidth() / 2, particleEffect.getHeight() / 2);
    particleEffect.setCenter(particleEffect.getWidth() / 2, particleEffect.getHeight() / 2);

    // Insert particleEffect behind the logo and quitButton (z-order)
    container.insert(&background, particleEffect);

}

void ScreenSaverView::tearDownScreen()
{
    ScreenSaverViewBase::tearDownScreen();
}

void ScreenSaverView::endScreenSaverAnimation()
{
    //Delay for 1200 ms (72 Ticks)
    waitToEndScreenCounter = WAITTOENDSCREEN_DURATION;

    particleEffect.spawnNewParticles(false);
    quitButton.setTouchable(false);
}

void ScreenSaverView::handleTickEvent()
{
    ScreenSaverViewBase::handleTickEvent();

    if (waitToEndScreenCounter > 0)
    {
        waitToEndScreenCounter--;

        if (waitToEndScreenCounter == 0)
        {
            //Go to Washing with no screen transition
            application().gotoWashingScreenNoTransition();
        }
    }
}
