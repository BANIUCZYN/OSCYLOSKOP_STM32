#include <gui/containers/Options_panel.hpp>
// #include <stdio.h>

Options_panel::Options_panel()
{
    CH_N_val = 0; //inicjalizacja wartoœci numeru kana³u

    // Ch_visib_btn.setAction(flexButtonCallback);
    // Ch_type_btn.setAction(flexButtonCallback);
    // Ch_trig_btn.setAction(flexButtonCallback);
}

void Options_panel::initialize()
{
    Options_panelBase::initialize();
}

// ========== DODANE FUNKCYJE ==========

void Options_panel::Toggle_channel()
{
    CH_N_val ^= 1; // bistabilny prze³acznik kana³u (tylko dwa kana³y)
    Unicode::snprintf(Channel_btnBuffer, CHANNEL_BTN_SIZE, "%d", CH_N_val+1);

    Update_displayed_settings();

    // printf("%d\n", CHANNEL_BTN_SIZE);
}

void Options_panel::Toggle_ch_visib()
{
    channels[CH_N_val].toggle_bin_setting(1);
    const char* text = channels[CH_N_val].get_ch_visib_text();
    Unicode::strncpy(Ch_visib_btnBuffer, text, CH_VISIB_BTN_SIZE);
    // Visib_txt.invalidate();
    
    //const touchgfx::Unicode::UnicodeChar* TEXT = channels[CH_N_val].get_ch_visib_text(CH_VISIB_BTN_SIZE);
    //Unicode::snprintf(Ch_visib_btnBuffer, CH_VISIB_BTN_SIZE, "%s", TEXT);
}

void Options_panel::Toggle_ch_type()
{
    channels[CH_N_val].toggle_bin_setting(2);
    const char* text = channels[CH_N_val].get_ch_type_text();
    Unicode::strncpy(Ch_type_btnBuffer, text, CH_TYPE_BTN_SIZE);
    // Type_txt.invalidate();
    
    //const touchgfx::Unicode::UnicodeChar* TEXT = channels[CH_N_val].get_ch_type_text(CH_TYPE_BTN_SIZE);
    //Unicode::snprintf(Ch_type_btnBuffer, CH_TYPE_BTN_SIZE, "%s", TEXT);
}

void Options_panel::Toggle_ch_trig()
{
    channels[CH_N_val].toggle_bin_setting(3);
    const char* text = channels[CH_N_val].get_ch_trig_text();
    Unicode::strncpy(Ch_trig_btnBuffer, text, CH_TRIG_BTN_SIZE);
    // Trig_txt.invalidate();
     
    //const touchgfx::Unicode::UnicodeChar* TEXT = channels[CH_N_val].get_ch_trig_text(CH_TRIG_BTN_SIZE);
    //Unicode::snprintf(Ch_trig_btnBuffer, CH_TRIG_BTN_SIZE, "%s", TEXT);
}

void Options_panel::Update_displayed_settings()
{
    Visib_txt.invalidate();
    Type_txt.invalidate();
    Trig_txt.invalidate();
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