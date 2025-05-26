#ifndef VALUE_EDITOR_PANEL_HPP
#define VALUE_EDITOR_PANEL_HPP

#include <gui_generated/containers/Value_editor_panelBase.hpp>
#include <gui/containers/Setting_types.hpp>

class Options_panel; // to jest po to aby mo¿na by³o stworzyx op_ptr (forward declaration)

class Value_editor_panel : public Value_editor_panelBase
{
private:
    Options_panel* op_ptr;

    int16_t edited_val;
    int16_t edited_val_MAX[SIZE_OF_Setting_type];
    int16_t edited_val_MIN[SIZE_OF_Setting_type];
    int16_t digit[SIZE_OF_Setting_type]; // zrobiæ mapping na switchu bo to oszczedza 6 bajtow RAM (ale za to zabiera 36 bajtow FLASH)

    Setting_type current_setting;

    int16_t get_digit(int16_t val);
    bool check_val_legality(char operation);
    void update_dependent_limits();

    void edit_edited_val(char operation);

    void set_other_panels_touchability(bool val);

public:
    Value_editor_panel();
    virtual ~Value_editor_panel() {}

    virtual void Value_OK();
    virtual void Value_increment() { edit_edited_val('+'); }
    virtual void Value_decrement() { edit_edited_val('-'); }
    virtual void Value_x10() { edit_edited_val('*'); }
    virtual void Value_x10_division() { edit_edited_val('/'); }

    void set_edited_val(Setting_type setting, int16_t val);
    void set_edited_val_limits(Setting_type setting, int16_t max, int16_t min);
    // void edit_val(Setting_type setting); // po analizie stwierdzam ze lepiej tego nie robic bo
    // nie koniecznie uprosci dzialanie a komplikuje kod i wsumie moga byc problemy z funkcjonalnoscia

    void update_edited_val_text();

    virtual void initialize();

    void set_OP_ptr(Options_panel* op) { op_ptr = op; }
protected:
};

#endif // VALUE_EDITOR_PANEL_HPP
