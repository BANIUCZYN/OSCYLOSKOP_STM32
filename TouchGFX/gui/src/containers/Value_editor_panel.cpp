#include <gui/containers/Value_editor_panel.hpp>
#include <gui/containers/Options_panel.hpp> // To musi byc bo w Value_editor_panel.hpp jest tylko forward declaration bez podpietego pliku zrodlowego

Value_editor_panel::Value_editor_panel() : op_ptr(nullptr), edited_val(0)
{
    this->setVisible(false);
    this->invalidate();

    for (int8_t i = 0; i < SIZE_OF_Setting_type; i++)
    {
        digit[i] = 0;
        edited_val_MAX[i] = 0;
        edited_val_MIN[i] = 0;
    }

    set_edited_val_limits(CH_SCALE, CH_SCALE_MAX, CH_SCALE_MIN);
    set_edited_val_limits(TIMEBASE, TIMEBASE_MAX, TIMEBASE_MIN);
}

void Value_editor_panel::initialize()
{
    Value_editor_panelBase::initialize();
}

// ========================= DODANE FUNKCYJE ===========================

// ========= Przyciski =========

void Value_editor_panel::Value_OK()
{
    op_ptr->Update_num_val(current_setting, edited_val);

    if (current_setting == CH_SCALE) { set_edited_val_limits(CH_Y_POS, 5 * edited_val, ~(5 * (static_cast<int32_t>(edited_val))) + 1); }

    this->setVisible(false);
    this->invalidate();
}

void Value_editor_panel::Value_increment()
{
    // bool perm = check_val_legality('+');
    // if (perm)
    // {
        edited_val += digit[current_setting];
        update_edited_val_text();
    // }
}

void Value_editor_panel::Value_decrement()
{
    edited_val -= digit[current_setting];

    update_edited_val_text();
}

void Value_editor_panel::Value_x10()
{
    if (edited_val != 0)
    {
        edited_val *= 10;
        digit[current_setting] *= 10;

        update_edited_val_text();
    }
}

void Value_editor_panel::Value_x10_division()
{
    if (edited_val >= 10)
    {
        edited_val /= 10;
        digit[current_setting] /= 10;

        update_edited_val_text();
    }
}

// =========== Inne funkcyje ============

void Value_editor_panel::set_edited_val(Setting_type setting, uint16_t val)
{
    current_setting = setting; 
    
    edited_val = val;
    update_edited_val_text();

    if (digit[current_setting] == 0) { digit_init(); }
}

void Value_editor_panel::set_edited_val_limits(Setting_type setting, uint16_t max, int32_t min)
{
    edited_val_MAX[setting] = max;
    edited_val_MIN[setting] = min;
}

void Value_editor_panel::update_edited_val_text()
{
    Unicode::snprintf(Val_textBuffer, VAL_TEXT_SIZE, "%d", edited_val);
    Val_text.invalidate();
}

void Value_editor_panel::digit_init()
{
    uint16_t val = edited_val;
    uint16_t dig = 1;
    while (val >= 10)
    {
        val /= 10;
        dig *= 10;
    }
    digit[current_setting] = dig;
}