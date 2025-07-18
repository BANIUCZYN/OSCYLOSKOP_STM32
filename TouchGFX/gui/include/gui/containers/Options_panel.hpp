#ifndef OPTIONS_PANEL_HPP
#define OPTIONS_PANEL_HPP

#include <gui_generated/containers/Options_panelBase.hpp>
#include <gui/containers/Channel_settings.hpp>
#include <gui/containers/Value_editor_panel.hpp>
#include <gui/containers/Setting_types.hpp>

class Value_editor_panel; // to jest po to aby mo�na by�o stworzy� vep_ptr (forward declaration)

#define NUMBER_OF_CHANNELS 2

class Options_panel : public Options_panelBase
{
private:
    Value_editor_panel* vep_ptr;

    bool acquisition_status;
    uint8_t CH_N_val;
    int16_t timebase_val; // To musi by� tu, a nie jako atrybut Channel_settings bo nie zale�y od kana�u

    Channel_settings channels[NUMBER_OF_CHANNELS];

public:
    Options_panel();
    virtual ~Options_panel() {}

    virtual void initialize();

    void Update_all_disp_ch_settings();
    void Update_btn_text(Setting_type setting);

    void Update_num_val(Setting_type setting, int16_t val);

    int16_t get_curr_ch_num_val(Setting_type setting) const { return channels[CH_N_val].get_ch_num_val(setting); } // channels[CH_N_val].get_ch_num_val(setting)

    // Obsluga przeciskow
    virtual void Toggle_acquisition();
    virtual void Toggle_channel();
    virtual void Toggle_ch_visib();
    virtual void Toggle_ch_type();
    virtual void Toggle_ch_trig();
    virtual void Edit_scale_val() { Edit_val_in_VEP(CH_SCALE); }
    virtual void Edit_y_pos_val() { Edit_val_in_VEP(CH_Y_POS); }
    virtual void Edit_timebase_val() { Edit_val_in_VEP(TIMEBASE); }
    void Edit_val_in_VEP(Setting_type setting);

    void set_buttons_touchability(bool val);

    void set_VEP_ptr(Value_editor_panel* vep) { vep_ptr = vep; }

protected:
};

#endif // OPTIONS_PANEL_HPP
