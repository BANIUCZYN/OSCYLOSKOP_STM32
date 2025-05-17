#ifndef OPTIONS_PANEL_HPP
#define OPTIONS_PANEL_HPP

#include <gui_generated/containers/Options_panelBase.hpp>
#include <gui/containers/Channel_settings.hpp>
#include <gui/containers/Value_editor_panel.hpp>
#include <gui/containers/Setting_types.hpp>

class Value_editor_panel; // to jest po to aby mo¿na by³o stworzyæ vep_ptr (forward declaration)

#define NUMBER_OF_CHANNELS 2

class Options_panel : public Options_panelBase
{
private:
    Value_editor_panel* vep_ptr;

    uint8_t CH_N_val;
    uint16_t timebase_val; // To musi byæ tu, a nie jako atrybut Channel_settings bo nie zale¿y od kana³u

    Channel_settings channels[NUMBER_OF_CHANNELS];

public:
    Options_panel();
    virtual ~Options_panel() {}

    virtual void initialize();

    void Update_all_disp_ch_settings();
    void Update_btn_text(Setting_type setting);

    void Update_num_val(uint16_t val, Setting_type setting);

    // Obsluga przeciskow
    virtual void Toggle_channel();
    virtual void Toggle_ch_visib();
    virtual void Toggle_ch_type();
    virtual void Toggle_ch_trig();
    virtual void Edit_scale_val();
    virtual void Edit_y_pos_val();
    virtual void Edit_timebase_val();

    void set_VEP_ptr(Value_editor_panel* vep) { vep_ptr = vep; }

protected:
};

#endif // OPTIONS_PANEL_HPP
