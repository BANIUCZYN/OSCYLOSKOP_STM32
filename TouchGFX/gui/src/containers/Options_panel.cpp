#include <gui/containers/Options_panel.hpp>
// #include <stdio.h>

Options_panel::Options_panel()
{
    CH_N_val = 0; //inicjalizacja wartoœci numeru kana³u
}

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
    Update_btn_text(&Ch_visib_btn, Ch_visib_btnBuffer, CH_VISIB_BTN_SIZE, VISIB);
}

void Options_panel::Toggle_ch_type()
{
    channels[CH_N_val].toggle_bin_setting(TYPE);
    Update_btn_text(&Ch_type_btn, Ch_type_btnBuffer, CH_TYPE_BTN_SIZE, TYPE);
}

void Options_panel::Toggle_ch_trig()
{
    channels[CH_N_val].toggle_bin_setting(TRIG);
    Update_btn_text(&Ch_trig_btn, Ch_trig_btnBuffer, CH_TRIG_BTN_SIZE, TRIG);
}

void Options_panel::Edit_scale_val()
{
    /*
    VEP.setVisible(true);
    VEP.invalidate();
    */
    if (vep_ptr)
    {
        vep_ptr->setVisible(true);
        vep_ptr->invalidate();
    }
}

void Options_panel::Edit_y_pos_val()
{

}

void Options_panel::Edit_timebase_val()
{

}

////////////////////////////////////////////////////////////////////////////////////

void Options_panel::Update_all_disp_ch_settings()
{
    Update_btn_text(&Ch_visib_btn, Ch_visib_btnBuffer, CH_VISIB_BTN_SIZE, VISIB);
    Update_btn_text(&Ch_type_btn, Ch_type_btnBuffer, CH_TYPE_BTN_SIZE, TYPE);
    Update_btn_text(&Ch_trig_btn, Ch_trig_btnBuffer, CH_TRIG_BTN_SIZE, TRIG);
}

void Options_panel::Update_btn_text(touchgfx::WildcardTextButtonStyle<touchgfx::BoxWithBorderButtonStyle<touchgfx::ClickButtonTrigger>>* btn_ptr,
    touchgfx::Unicode::UnicodeChar* buffer,
    const uint16_t BUFFER_SIZE,
    Channel_setting_type setting)
{
    const char* text = channels[CH_N_val].get_ch_text(setting);
    Unicode::strncpy(buffer, text, BUFFER_SIZE);
    btn_ptr->invalidate();
}

/// Potencjalnie do wywalenia

/* void Options_panel::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &Ch_visib_btn)
    {
        channels[CH_N_val].toggle_bin_val(1);
        const char* TEXT = channels[CH_N_val].get_ch_visib_text();
        Unicode::snprintf(Ch_visib_btnBuffer, CH_VISIB_BTN_SIZE, "%s", TEXT);
    }
    if (&src == &Ch_type_btn)
    {
        channels[CH_N_val].toggle_bin_val(2);
        const char* TEXT = channels[CH_N_val].get_ch_type_text();
        Unicode::snprintf(Ch_type_btnBuffer, CH_TYPE_BTN_SIZE, "%s", TEXT);
    }
    if (&src == &Ch_trig_btn)
    {
        channels[CH_N_val].toggle_bin_val(3);
        const char* TEXT = channels[CH_N_val].get_ch_trig_text();
        Unicode::snprintf(Ch_trig_btnBuffer, CH_TRIG_BTN_SIZE, "%s", TEXT);
    }
    if (&src == &Ch_scale_btn) {  
    }
    if (&src == &Ch_y_pos_btn) { 
    }
} */