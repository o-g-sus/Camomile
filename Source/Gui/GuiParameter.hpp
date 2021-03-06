/*
 // Copyright (c) 2015 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#ifndef __CAMOMILE_GUI_PARAMETER__
#define __CAMOMILE_GUI_PARAMETER__

#include "../InstanceProcessor.hpp"

// ==================================================================================== //
//                                      GUI PARAMETER                                   //
// ==================================================================================== //

class GuiParameter : public virtual Component, private Timer
{
public:
    GuiParameter(InstanceProcessor& processor, pd::Gui const& gui);
    ~GuiParameter();
    
    pd::Gui::Type getType() const noexcept;
    float getMaximum() const noexcept;
    float getMinimum() const noexcept;
    float getValue() const noexcept;
    float getValueNormalized() const noexcept;
    
protected:
    
    void startEdition() noexcept;
    void stopEdition() noexcept;
    void setValue(float value, bool redraw = true);
    void setValueNormalized(float value, bool redraw = true);
private:
    void timerCallback() final;
    
    InstanceProcessor&  m_processor;
    const pd::Gui::Type m_type;
    const float         m_minimum;
    const float         m_maximum;
    const size_t        m_index;
    float               m_value;
    bool                m_edited;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GuiParameter)
};


#endif
