#ifndef VALUE_EDITOR_PANEL_HPP
#define VALUE_EDITOR_PANEL_HPP

#include <gui_generated/containers/Value_editor_panelBase.hpp>
#include <gui/containers/Setting_types.hpp>

// #define NUMBER_OF_EDITABLE_VALS 3

class Options_panel; // to jest po to aby mo¿na by³o stworzyx op_ptr (forward declaration)

class Value_editor_panel : public Value_editor_panelBase
{
private:
    Options_panel* op_ptr;

    uint16_t edited_val;
    uint16_t edited_val_MAX[SIZE_OF_Setting_type];
    uint16_t edited_val_MIN[SIZE_OF_Setting_type];
    uint16_t digit[SIZE_OF_Setting_type]; // zrobiæ mapping na switchu bo to oszczedza 6 bajtow RAM (ale za to zabiera 36 bajtow FLASH)

    Setting_type current_setting;

    void digit_init();
    bool check_val_legality(char operation);

public:
    Value_editor_panel();
    virtual ~Value_editor_panel() {}

    virtual void Value_OK();
    virtual void Value_increment();
    virtual void Value_decrement();
    virtual void Value_x10();
    virtual void Value_x10_division();

    void set_edited_val(Setting_type setting, uint16_t val);
    void set_edited_val_limits(Setting_type setting, uint16_t max, int32_t min);
    // void edit_val(Setting_type setting); // po analizie stwierdzam ze lepiej tego nie robic bo
    // nie koniecznie uprosci dzialanie a komplikuje kod i wsumie moga byc problemy z funkcjonalnoscia

    void update_edited_val_text();

    virtual void initialize();

    void set_OP_ptr(Options_panel* op) { op_ptr = op; }
protected:
};

#endif // VALUE_EDITOR_PANEL_HPP
