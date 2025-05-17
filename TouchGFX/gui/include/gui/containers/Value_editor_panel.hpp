#ifndef VALUE_EDITOR_PANEL_HPP
#define VALUE_EDITOR_PANEL_HPP

#include <gui_generated/containers/Value_editor_panelBase.hpp>
#include <gui/containers/Channel_settings.hpp>

class Options_panel; // to jest po to aby mo¿na by³o stworzyæ op_ptr (forward declaration)

class Value_editor_panel : public Value_editor_panelBase
{
private:
    Options_panel* op_ptr;
    uint16_t edited_val;
    Channel_setting_type current_setting;

public:
    Value_editor_panel();
    virtual ~Value_editor_panel() {}

    virtual void Value_OK();
    virtual void Value_increment();
    virtual void Value_decrement();
    virtual void Value_x10();
    virtual void Value_x10_division();

    void set_edited_val(uint16_t val, Channel_setting_type setting) { edited_val = val; current_setting = setting; }

    void update_edited_val_text();

    virtual void initialize();

    void set_OP_ptr(Options_panel* op) { op_ptr = op; }
protected:
};

#endif // VALUE_EDITOR_PANEL_HPP
