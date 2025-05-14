#ifndef VALUE_EDITOR_PANEL_HPP
#define VALUE_EDITOR_PANEL_HPP

#include <gui_generated/containers/Value_editor_panelBase.hpp>

class Value_editor_panel : public Value_editor_panelBase
{
public:
    Value_editor_panel();
    virtual ~Value_editor_panel() {}

    virtual void Value_OK();
    virtual void Value_increment();
    virtual void Value_decrement();
    virtual void Value_x10();
    virtual void Value_x10_division();

    virtual void initialize();
protected:
};

#endif // VALUE_EDITOR_PANEL_HPP
