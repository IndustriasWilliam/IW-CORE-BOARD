#include <gui/instructions_screen/InstructionsView.hpp>
#include <Bitmapdatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/hal/HAL.hpp>


InstructionsView::InstructionsView() : tickCounter(0), playing(true), headline(T_VIDEOSTEP1), body(T_VIDEOTEXT1)
{

}

void InstructionsView::setupScreen()
{
    InstructionsViewBase::setupScreen();
}

void InstructionsView::tearDownScreen()
{
    InstructionsViewBase::tearDownScreen();
}

void InstructionsView::handleTickEvent()
{
    if (playing)
    {
        ++tickCounter;
        if (tickCounter & 0x01 && playing)
        {
            if (getVideoTexts(washerVideo.getCurrentFrameNumber(), headline, body))
            {
                instructionsStepNr.setTypedText(headline);
                instructionsStepNr.invalidate();
                instructionsText.setTypedText(body);
                instructionsText.invalidate();
            }
        }
    }
}

bool InstructionsView::getVideoTexts(int frameno, TypedText& headline, TypedText& body)
{
    switch (frameno)
    {
    case 1:
        headline = TypedText(T_VIDEOSTEP1);
        body = TypedText(T_VIDEOTEXT1);
        return true;
    case 110:
        headline = TypedText(T_VIDEOSTEP2);
        body = TypedText(T_VIDEOTEXT2);
        return true;
    case 215:
        headline = TypedText(T_VIDEOSTEP3);
        body = TypedText(T_VIDEOTEXT3);
        return true;
    case 310:
        headline = TypedText(T_VIDEOSTEP4);
        body = TypedText(T_VIDEOTEXT4);
        return true;
    default:
        return false;
    }
}
