#include <gui/containers/Channel_settings.hpp>

Channel_settings::Channel_settings()
	: ch_visib_val(false),
	ch_type_val(false),
	ch_trig_val(false),
	ch_scale_val(1), // zakres na ekranie -5V do 5V
	ch_y_pos_val(0)  // 0V przesuniêcia wzglêdem osi x (0V)
{}

void Channel_settings::toggle_bin_setting(Setting_type setting)
{
	switch (setting)
	{
	case CH_VISIB:
		ch_visib_val = !ch_visib_val;
		break;
	case CH_TYPE:
		ch_type_val = !ch_type_val;
		break;
	case CH_TRIG:
		ch_trig_val = !ch_trig_val;
		break;
	default:
		break;
	}
}

void Channel_settings::set_num_val(Setting_type setting, int16_t val)
{
	switch (setting)
	{
	case CH_SCALE:
		ch_scale_val = val;
		break;
	case CH_Y_POS:
		ch_y_pos_val = val;
		break;
	default:
		break;
	}
}

const char* Channel_settings::get_ch_bin_text(Setting_type setting) const
{
	switch (setting)
	{
	case CH_VISIB:
		return ch_visib_val ? "ON" : "OFF";
	case CH_TYPE:
		return ch_type_val ? "AC" : "DC";
	case CH_TRIG:
		return ch_trig_val ? "MANUAL" : "AUTO";
	default:
		return "ERR";
	}
}

int16_t Channel_settings::get_ch_num_val(Setting_type setting) const
{
	switch (setting)
	{
	case CH_SCALE:
		return ch_scale_val;
	case CH_Y_POS:
		return ch_y_pos_val;
	default:
		return 0;
	}
}