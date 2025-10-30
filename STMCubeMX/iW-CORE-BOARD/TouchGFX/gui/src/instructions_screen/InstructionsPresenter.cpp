#include <gui/instructions_screen/InstructionsView.hpp>
#include <gui/instructions_screen/InstructionsPresenter.hpp>

InstructionsPresenter::InstructionsPresenter(InstructionsView& v)
    : view(v)
{

}

void InstructionsPresenter::activate()
{
    model->setScreenSaverEnabled(false);
}

void InstructionsPresenter::deactivate()
{

}
