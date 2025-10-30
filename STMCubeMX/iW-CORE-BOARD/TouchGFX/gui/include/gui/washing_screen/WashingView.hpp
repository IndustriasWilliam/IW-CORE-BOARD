#ifndef WASHINGVIEW_HPP
#define WASHINGVIEW_HPP

#include <gui_generated/washing_screen/WashingViewBase.hpp>
#include <gui/washing_screen/WashingPresenter.hpp>

class WashingView : public WashingViewBase
{
public:
    WashingView();
    virtual ~WashingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleClickEvent(const ClickEvent& event);
    virtual void handleDragEvent(const DragEvent& evt);
    virtual void handleTickEvent();


    uint16_t getSelectedProgram();
    uint16_t getWashingTime();
    void setSelectedProgram(uint16_t program);
protected:
};

#endif // WASHINGVIEW_HPP
