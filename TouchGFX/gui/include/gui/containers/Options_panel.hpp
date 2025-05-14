#ifndef OPTIONS_PANEL_HPP
#define OPTIONS_PANEL_HPP

#include <gui_generated/containers/Options_panelBase.hpp>
#include <gui/containers/Channel_settings.hpp>
#include <gui/containers/Value_editor_panel.hpp>

#define NUMBER_OF_CHANNELS 2

class Options_panel : public Options_panelBase
{
private:
    uint8_t CH_N_val;
    Channel_settings channels[NUMBER_OF_CHANNELS] = { Channel_settings(), Channel_settings() };

public:
    Options_panel();
    virtual ~Options_panel() {}

    virtual void initialize();

    void Update_all_disp_ch_settings();
    void Update_btn_text(touchgfx::WildcardTextButtonStyle<touchgfx::BoxWithBorderButtonStyle<touchgfx::ClickButtonTrigger>>* btn,
        touchgfx::Unicode::UnicodeChar* buffer,
        const uint16_t buffer_size,
        Channel_setting_type setting);

    // Obsluga przeciskow
    virtual void Toggle_channel();
    virtual void Toggle_ch_visib();
    virtual void Toggle_ch_type();
    virtual void Toggle_ch_trig();
    virtual void Edit_scale_val();
    virtual void Edit_y_pos_val();
    virtual void Edit_timebase_val();

    //virtual void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

protected:
};

#endif // OPTIONS_PANEL_HPP
