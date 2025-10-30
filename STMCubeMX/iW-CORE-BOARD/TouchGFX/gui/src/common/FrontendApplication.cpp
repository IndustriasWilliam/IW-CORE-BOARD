#include <gui/common/FrontendApplication.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{
}

void FrontendApplication::handleClickEvent(const ClickEvent& evt)
{
    FrontendApplicationBase::handleClickEvent(evt);
    // A click event has been registered so reset last click time
    model.resetScreenSaverCounter();
}

void FrontendApplication::handleDragEvent(const DragEvent& evt)
{
    FrontendApplicationBase::handleDragEvent(evt);
    // A drag event has been registered so reset last click time
    model.resetScreenSaverCounter();
}

void FrontendApplication::handleTickEvent()
{
    model.tick();
    FrontendApplicationBase::handleTickEvent();
}

int FrontendApplication::getCurrentScreen()
{
    return model.getCurrentScreen();
}

void FrontendApplication::setCurrentScreen(int screen)
{
    model.setCurrentScreen(screen);
}
