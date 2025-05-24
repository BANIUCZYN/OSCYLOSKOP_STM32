#include <gui/containers/Value_editor_panel.hpp>
#include <gui/containers/Options_panel.hpp> // To musi byc bo w Value_editor_panel.hpp jest tylko forward declaration bez podpietego pliku zrodlowego
#include <stdlib.h>

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

    set_edited_val_limits( CH_SCALE, CH_SCALE_MAX, CH_SCALE_MIN );
    set_edited_val_limits( TIMEBASE, TIMEBASE_MAX, TIMEBASE_MIN );
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

    this->setVisible(false);
    this->invalidate();
}

void Value_editor_panel::edit_edited_val(char operation)
{
    if (!check_val_legality(operation)) { return; }

    switch (operation)
    {
    case '+':
        edited_val += digit[current_setting];
        break;
    case '-':
        edited_val -= digit[current_setting];
        break;
    case '*':
        edited_val *= 10;
        digit[current_setting] *= 10;
        break;
    case '/':
        edited_val /= 10;
        digit[current_setting] /= 10;
        break;
    }

    update_edited_val_text();
}

// =========== Inne funkcyje ============

void Value_editor_panel::set_edited_val(Setting_type setting, int16_t val)
{
    current_setting = setting; 
    edited_val = val;
    
    update_edited_val_text();
    update_dependent_limits();

    if (digit[current_setting] == 0) { digit[current_setting] = get_digit(edited_val); }
}

void Value_editor_panel::set_edited_val_limits(Setting_type setting, int16_t max, int16_t min)
{
    edited_val_MAX[setting] = max;
    edited_val_MIN[setting] = min;
}

void Value_editor_panel::update_dependent_limits()
{
    switch (current_setting)
    {
    case CH_Y_POS:
        set_edited_val_limits(CH_Y_POS, 5 * op_ptr->get_curr_ch_num_val(CH_SCALE), ~(5 * op_ptr->get_curr_ch_num_val(CH_SCALE)) + 1);
        break;
    default:
        break;
    }
}

void Value_editor_panel::update_edited_val_text()
{
    Unicode::snprintf(Val_textBuffer, VAL_TEXT_SIZE, "%d", edited_val);
    Val_text.invalidate();
}

int16_t Value_editor_panel::get_digit(int16_t val)
{
    int16_t pos_val = abs(val);
    int16_t dig = 1;
    while (pos_val >= 10)
    {
        pos_val /= 10;
        dig *= 10;
    }
    return dig;
}

bool Value_editor_panel::check_val_legality(char operation)
{
    int32_t val_copy = static_cast<int32_t>(edited_val);
    int32_t digit_copy = static_cast<int32_t>(digit[current_setting]);
    int32_t outcome;
    int32_t outcome_digit;

    switch (operation)
    {
    case '+':
        outcome = val_copy + digit_copy;
        outcome_digit = get_digit(static_cast<int32_t>(outcome));
        return outcome <= edited_val_MAX[current_setting] && outcome_digit == digit_copy;
    case '-':
        outcome = val_copy - digit_copy;
        outcome_digit = get_digit(static_cast<int32_t>(outcome));
        return outcome >= edited_val_MIN[current_setting] && outcome_digit == digit_copy;
    case '*':
        if (val_copy != 0)
        {
            outcome = val_copy * 10;
            return outcome <= edited_val_MAX[current_setting] && outcome >= edited_val_MIN[current_setting];
        }
        else { return 0; }
    case '/':
        if (val_copy >= 10 || val_copy <= -10)
        {
            outcome = val_copy / 10;
            return outcome >= edited_val_MIN[current_setting]; // tu chyba nie trza outcome <= edited_val_MAX[current_setting]
        }
        else { return 0; }
    default:
        return 0;
    }
}