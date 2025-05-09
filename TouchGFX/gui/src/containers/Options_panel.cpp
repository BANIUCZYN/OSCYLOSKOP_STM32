#include <gui/containers/Options_panel.hpp>

#include <gui/containers/Value_editor_panel.hpp>
//#include <gui/containers/Channel_button.hpp>

Options_panel::Options_panel()
{
    CH_N_val = 1; //inicjalizacja wartoœci numeru kana³u
}

void Options_panel::initialize()
{
    Options_panelBase::initialize();
}

// ========== DODANE FUNKCYJE ==========

void Options_panel::toggle_channel()
{
    CH_N_val ^= 3;
    Unicode::snprintf(Channel_buttonBuffer, 2, "%d", CH_N_val); // zamieniæ 2 na CHANNEL_BUTTON_SIZE
    // Unicode::snprintf(Channel_buttonBuffer, 2, "%s", TypedText(T_CH_BTN_WC).getText());
    //Channel_button.invalidate();
    //usleep(500000); //opóŸnienie na 0.5s po wciœniêciu przycisku
}

/*
void Options_panel::toggleDropdown()
{
    Channel_list.setVisible(!Channel_list.isVisible());
    Channel_list.invalidate(); // Odswiezanie widoku
}


void Options_panel::updateSelectedOption(const char* newText)
{
    Channel_button.setLabelText(newText);
    Channel_button.invalidate();
}
*/