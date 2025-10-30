#include <gui/washing_screen/WashingView.hpp>

WashingView::WashingView()
{

}

void WashingView::setupScreen()
{
    WashingViewBase::setupScreen();
}

void WashingView::tearDownScreen()
{
    WashingViewBase::tearDownScreen();
}

void WashingView::handleClickEvent(const ClickEvent& event)
{
    View::handleClickEvent(event);

    if (washerContainer.isVisible())
    {
        washerContainer.clickEvent(event);
    }
}

void WashingView::handleDragEvent(const DragEvent& event)
{
    washerContainer.handleDragEvent(event);
    WashingViewBase::handleDragEvent(event);
}

void WashingView::handleTickEvent()
{
    washerContainer.tickEvent();
}

uint16_t WashingView::getSelectedProgram()
{
    return washerContainer.getWashingProgram();
}

uint16_t WashingView::getWashingTime()
{
    return washerContainer.getWashingTime();
}

void WashingView::setSelectedProgram(uint16_t program)
{
    washerContainer.setWashingProgram(program);
}
