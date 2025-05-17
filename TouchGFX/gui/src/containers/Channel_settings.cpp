#include <gui/containers/Channel_settings.hpp>

Channel_settings::Channel_settings()
	: ch_visib_val(false),
	ch_type_val(false),
	ch_trig_val(false),
	ch_scale_val(1),
	ch_y_pos_val(1)
{}

void Channel_settings::toggle_bin_setting(Channel_setting_type setting)
{
	switch (setting)
	{
	case VISIB:
		ch_visib_val = !ch_visib_val;
		break;
	case TYPE:
		ch_type_val = !ch_type_val;
		break;
	case TRIG:
		ch_trig_val = !ch_trig_val;
		break;
	default:
		break;
	}
}

void Channel_settings::set_num_val(uint16_t val, Channel_setting_type setting)
{
	switch (setting)
	{
	case SCALE:
		ch_scale_val = val;
		break;
	case Y_POS:
		ch_y_pos_val = val;
		break;
	default:
		break;
	}
}

const char* Channel_settings::get_ch_bin_text(Channel_setting_type setting) const
{
	switch (setting)
	{
	case VISIB:
		return ch_visib_val ? "ON" : "OFF";
	case TYPE:
		return ch_type_val ? "AC" : "DC";
	case TRIG:
		return ch_trig_val ? "MANUAL" : "AUTO";
	default:
		return "ERR";
	}
}

uint16_t Channel_settings::get_ch_num_val(Channel_setting_type setting) const
{
	switch (setting)
	{
	case SCALE:
		return ch_scale_val;
	case Y_POS:
		return ch_y_pos_val;
	default:
		return 0;
	}
}