#include <gui/screensaver_screen/ScreenSaverView.hpp>
#include <gui/screensaver_screen/ScreenSaverPresenter.hpp>

ScreenSaverPresenter::ScreenSaverPresenter(ScreenSaverView& v)
    : view(v)
{

}

void ScreenSaverPresenter::activate()
{
    model->setScreenSaverEnabled(true);
    model->setCurrentScreen(Model::VIEW_SAVER);
}

void ScreenSaverPresenter::deactivate()
{

}
