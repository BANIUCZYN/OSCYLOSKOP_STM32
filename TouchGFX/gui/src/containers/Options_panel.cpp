#include <gui/containers/Options_panel.hpp>
// #include <stdio.h>

Options_panel::Options_panel() : vep_ptr(nullptr), CH_N_val(0) {}

void Options_panel::initialize()
{
    Options_panelBase::initialize();
}

// ========================= DODANE FUNKCYJE ===========================

// ========= Obsluga przyciskow =========

void Options_panel::Toggle_channel()
{
    CH_N_val ^= 1; // bistabilny prze³acznik kana³u (tylko dwa kana³y)
    Unicode::snprintf(Channel_btnBuffer, CHANNEL_BTN_SIZE, "%d", CH_N_val+1);
    Channel_btn.invalidate();

    Update_all_disp_ch_settings();
}

void Options_panel::Toggle_ch_visib()
{
    channels[CH_N_val].toggle_bin_setting(VISIB);
    Update_btn_text(VISIB);
}

void Options_panel::Toggle_ch_type()
{
    channels[CH_N_val].toggle_bin_setting(TYPE);
    Update_btn_text(TYPE);
}

void Options_panel::Toggle_ch_trig()
{
    channels[CH_N_val].toggle_bin_setting(TRIG);
    Update_btn_text(TRIG);
}

void Options_panel::Edit_scale_val()
{
    if (vep_ptr)
    {
        vep_ptr->setVisible(true);
        vep_ptr->invalidate();
    }
    
    uint16_t val = channels[CH_N_val].get_ch_num_val(SCALE);
    vep_ptr->set_edited_val(val, SCALE);
    vep_ptr->update_edited_val_text();
}

void Options_panel::Edit_y_pos_val()
{
    if (vep_ptr)
    {
        vep_ptr->setVisible(true);
        vep_ptr->invalidate();
    }

    uint16_t val = channels[CH_N_val].get_ch_num_val(Y_POS);
    vep_ptr->set_edited_val(val, Y_POS);
    vep_ptr->update_edited_val_text();
}

void Options_panel::Edit_timebase_val()
{

}

////////////////////////////////////////////////////////////////////////////////////

void Options_panel::Update_all_disp_ch_settings()
{
    Update_btn_text(VISIB);
    Update_btn_text(TYPE);
    Update_btn_text(TRIG);
}

void Options_panel::Update_btn_text(Channel_setting_type setting)
{
    const char* text = channels[CH_N_val].get_ch_bin_text(setting);
    uint16_t val = channels[CH_N_val].get_ch_num_val(setting);

    switch (setting)
    {
    case VISIB:
        Unicode::strncpy(Ch_visib_btnBuffer, text, CH_VISIB_BTN_SIZE);
        Ch_visib_btn.invalidate();
        break;
    case TYPE:
        Unicode::strncpy(Ch_type_btnBuffer, text, CH_TYPE_BTN_SIZE);
        Ch_type_btn.invalidate();
        break;
    case TRIG:
        Unicode::strncpy(Ch_trig_btnBuffer, text, CH_TRIG_BTN_SIZE);
        Ch_trig_btn.invalidate();
        break;
    case SCALE:
        Unicode::snprintf(Ch_scale_btnBuffer, CH_SCALE_BTN_SIZE, "%d", val);
        Ch_scale_btn.invalidate();
        break;
    case Y_POS:
        Unicode::snprintf(Ch_y_pos_btnBuffer, CH_Y_POS_BTN_SIZE, "%d", val);
        Ch_y_pos_btn.invalidate();
        break;
    }
}

void Options_panel::Update_num_val(uint16_t val, Channel_setting_type setting)
{
    channels[CH_N_val].set_num_val(val, setting);
    Update_btn_text(setting);
}