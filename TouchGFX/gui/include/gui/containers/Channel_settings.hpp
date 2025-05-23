#pragma once

#include <stdint.h>
#include <gui/containers/Setting_types.hpp>

class Channel_settings
{
private:
	bool ch_visib_val;
	bool ch_type_val;
	bool ch_trig_val;
	int16_t ch_scale_val; // tu jak starczy czasu zrobic uint16_t + int16_t
	int16_t ch_y_pos_val;

public:
	Channel_settings();

	void toggle_bin_setting(Setting_type setting);
	void set_num_val(Setting_type setting, int16_t val);

	const char* get_ch_bin_text(Setting_type setting) const;
	int16_t get_ch_num_val(Setting_type setting) const;

	/*
	bool get_ch_visib_val() const { return ch_visib_val; }
	bool get_ch_type_val() const { return ch_type_val; }
	bool get_ch_trig_val() const { return ch_trig_val; }
	uint16_t get_ch_scale_val() const { return ch_scale_val; }
	uint16_t get_ch_y_pos_val() const { return ch_y_pos_val; }

	void set_ch_scale_val(uint16_t val) { ch_scale_val = val; }
	void set_ch_y_pos_val(uint16_t val) { ch_y_pos_val = val; }
	*/
};