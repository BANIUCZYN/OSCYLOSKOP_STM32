#ifndef OPTIONS_PANEL_HPP
#define OPTIONS_PANEL_HPP

#include <gui_generated/containers/Options_panelBase.hpp>

class Options_panel : public Options_panelBase
{
private:
    uint8_t CH_N_val;

public:
    Options_panel();
    virtual ~Options_panel() {}

    virtual void initialize();

    virtual void toggle_channel();

    /*
    void toggleDropdown();
    void updateSelectedOption(const char* newText);
    */

protected:
};

#endif // OPTIONS_PANEL_HPP
