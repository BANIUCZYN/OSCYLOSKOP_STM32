#include <gui/containers/Value_editor_panel.hpp>

Value_editor_panel::Value_editor_panel() : op_ptr(nullptr), edited_val(0)
{
    this->setVisible(false);
    this->invalidate();
}

void Value_editor_panel::initialize()
{
    Value_editor_panelBase::initialize();
}

// DODANE FUNKCYJE

// Przyciski

void Value_editor_panel::Value_OK()
{
    //set_num_val(edited_val, current_setting); // zastanowiæ siê czy tu dawaæ wartoœæ od razu do Channel_settings, czy przez Options_panel

    this->setVisible(false);
    this->invalidate();
}

void Value_editor_panel::Value_increment()
{
    // edited_val

    update_edited_val_text();
}

void Value_editor_panel::Value_decrement()
{
    // edited_val

    update_edited_val_text();
}

void Value_editor_panel::Value_x10()
{
    edited_val *= 10;

    update_edited_val_text();
}

void Value_editor_panel::Value_x10_division()
{
    edited_val /= 10;

    update_edited_val_text();
}

// Inne funkcje

void Value_editor_panel::update_edited_val_text()
{
    Unicode::snprintf(Val_textBuffer, VAL_TEXT_SIZE, "%d", edited_val);
    Val_text.invalidate();
}