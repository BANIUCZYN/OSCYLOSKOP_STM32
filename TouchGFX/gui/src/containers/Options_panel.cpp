#include <gui/containers/Options_panel.hpp>
// #include <stdio.h>

Options_panel::Options_panel() :
    vep_ptr(nullptr),
    CH_N_val(0),
    timebase_val(1000), // 1000ns = 1us na podzia�k�, czyli 10us na ekran
    channels({ Channel_settings(), Channel_settings() })
{}

void Options_panel::initialize()
{
    Options_panelBase::initialize();
}

// ========================= DODANE FUNKCYJE ===========================

// ========= Obsluga przyciskow =========

void Options_panel::Toggle_channel()
{
    CH_N_val ^= 1; // bistabilny prze�acznik kana�u (tylko dwa kana�y)
    Unicode::snprintf(Channel_btnBuffer, CHANNEL_BTN_SIZE, "%d", CH_N_val+1);
    Channel_btn.invalidate();

    Update_all_disp_ch_settings();
}

void Options_panel::Toggle_ch_visib()
{
    channels[CH_N_val].toggle_bin_setting(CH_VISIB);
    Update_btn_text(CH_VISIB);
}

void Options_panel::Toggle_ch_type()
{
    channels[CH_N_val].toggle_bin_setting(CH_TYPE);
    Update_btn_text(CH_TYPE);
}

void Options_panel::Toggle_ch_trig()
{
    channels[CH_N_val].toggle_bin_setting(CH_TRIG);
    Update_btn_text(CH_TRIG);
}

void Options_panel::Edit_scale_val()
{
    if (vep_ptr)
    {
        vep_ptr->setVisible(true);
        vep_ptr->invalidate();
    }
    
    uint16_t val = channels[CH_N_val].get_ch_num_val(CH_SCALE);
    vep_ptr->set_edited_val(val, CH_SCALE);
    vep_ptr->update_edited_val_text();
}

void Options_panel::Edit_y_pos_val()
{
    if (vep_ptr)
    {
        vep_ptr->setVisible(true);
        vep_ptr->invalidate();
    }

    uint16_t val = channels[CH_N_val].get_ch_num_val(CH_Y_POS);
    vep_ptr->set_edited_val(val, CH_Y_POS);
    vep_ptr->update_edited_val_text();
}

void Options_panel::Edit_timebase_val()
{
    if (vep_ptr)
    {
        vep_ptr->setVisible(true);
        vep_ptr->invalidate();
    }
    
    uint16_t val = timebase_val;
    vep_ptr->set_edited_val(val, TIMEBASE);
    vep_ptr->update_edited_val_text();
}

////////////////////////////////////////////////////////////////////////////////////

void Options_panel::Update_all_disp_ch_settings()
{
    Update_btn_text(CH_VISIB);
    Update_btn_text(CH_TYPE);
    Update_btn_text(CH_TRIG);
    Update_btn_text(CH_SCALE);
    Update_btn_text(CH_Y_POS);
}

void Options_panel::Update_btn_text(Setting_type setting)
{
    switch (setting)
    {
    case CH_VISIB:
        Unicode::strncpy(Ch_visib_btnBuffer, channels[CH_N_val].get_ch_bin_text(setting), CH_VISIB_BTN_SIZE);
        Ch_visib_btn.invalidate();
        break;
    case CH_TYPE:
        Unicode::strncpy(Ch_type_btnBuffer, channels[CH_N_val].get_ch_bin_text(setting), CH_TYPE_BTN_SIZE);
        Ch_type_btn.invalidate();
        break;
    case CH_TRIG:
        Unicode::strncpy(Ch_trig_btnBuffer, channels[CH_N_val].get_ch_bin_text(setting), CH_TRIG_BTN_SIZE);
        Ch_trig_btn.invalidate();
        break;
    case CH_SCALE:
        Unicode::snprintf(Ch_scale_btnBuffer, CH_SCALE_BTN_SIZE, "%d", channels[CH_N_val].get_ch_num_val(setting));
        Ch_scale_btn.invalidate();
        break;
    case CH_Y_POS:
        Unicode::snprintf(Ch_y_pos_btnBuffer, CH_Y_POS_BTN_SIZE, "%d", channels[CH_N_val].get_ch_num_val(setting));
        Ch_y_pos_btn.invalidate();
        break;
    case TIMEBASE:
        Unicode::snprintf(Timebase_btnBuffer, TIMEBASE_BTN_SIZE, "%d", timebase_val);
        Timebase_btn.invalidate();
        break;
    }
}

void Options_panel::Update_num_val(uint16_t val, Setting_type setting)
{
    switch (setting)
    {
    case TIMEBASE:
        timebase_val = val;
        break;
    default:
        channels[CH_N_val].set_num_val(val, setting);
        break;
    }

    Update_btn_text(setting);
}