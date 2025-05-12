#include <gui/containers/Channel_settings.hpp>

Channel_settings::Channel_settings()
	: ch_visib_val(false),
	ch_type_val(false),
	ch_trig_val(false),
	ch_scale_val(0),
	ch_y_pos_val(0)
{}

void Channel_settings::toggle_bin_setting(int setting)
{
	switch (setting)
	{
	case 1:
		ch_visib_val = !ch_visib_val;
		break;
	case 2:
		ch_type_val = !ch_type_val;
		break;
	case 3:
		ch_trig_val = !ch_trig_val;
		break;
	}
}