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

    void Update_displayed_settings();

    virtual void Toggle_channel();
    virtual void Toggle_ch_visib();
    virtual void Toggle_ch_type();
    virtual void Toggle_ch_trig();

    //virtual void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

protected:
};

#endif // OPTIONS_PANEL_HPP
