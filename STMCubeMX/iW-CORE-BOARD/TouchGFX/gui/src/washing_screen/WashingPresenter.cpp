#include <gui/washing_screen/WashingView.hpp>
#include <gui/washing_screen/WashingPresenter.hpp>

WashingPresenter::WashingPresenter(WashingView& v)
    : view(v)
{

}

void WashingPresenter::activate()
{
    model->setScreenSaverEnabled(true);
    model->setCurrentScreen(Model::VIEW_WASHER);
    view.setSelectedProgram(0);
}

void WashingPresenter::deactivate()
{

}
