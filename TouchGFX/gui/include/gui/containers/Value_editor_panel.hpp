#ifndef VALUE_EDITOR_PANEL_HPP
#define VALUE_EDITOR_PANEL_HPP

#include <gui_generated/containers/Value_editor_panelBase.hpp>

class Value_editor_panel : public Value_editor_panelBase
{
public:
    Value_editor_panel();
    virtual ~Value_editor_panel() {}

    virtual void initialize();
protected:
};

#endif // VALUE_EDITOR_PANEL_HPP
