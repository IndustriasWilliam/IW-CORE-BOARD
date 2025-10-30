#ifndef INSTRUCTIONSVIEW_HPP
#define INSTRUCTIONSVIEW_HPP

#include <gui_generated/instructions_screen/InstructionsViewBase.hpp>
#include <gui/instructions_screen/InstructionsPresenter.hpp>

class InstructionsView : public InstructionsViewBase
{
public:
    InstructionsView();
    virtual ~InstructionsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
    bool getVideoTexts(int frameno, TypedText& headline, TypedText& body);
    uint32_t tickCounter;
    bool playing;
    TypedText headline, body;
};

#endif // INSTRUCTIONSVIEW_HPP
