#pragma once

#include <stdint.h>

enum Channel_setting_type {
	VISIB,
	TYPE,
	TRIG
};

class Channel_settings
{
private:
	bool ch_visib_val;
	bool ch_type_val;
	bool ch_trig_val;
	uint16_t ch_scale_val;
	uint16_t ch_y_pos_val;

public:
	Channel_settings();

	void toggle_bin_setting(Channel_setting_type setting);
	
	const char* get_ch_visib_text() const {
		return ch_visib_val ? "ON" : "OFF"; }
	/*
	const char* get_ch_type_text() const {
		return ch_type_val ? "AC" : "DC"; }
	const char* get_ch_trig_text() const {
		return ch_trig_val ? "MANUAL" : "AUTO"; }

	const char* get_ch_text(touchgfx::WildcardTextButtonStyle < touchgfx::BoxWithBorderButtonStyle<touchgfx::ClickButtonTrigger> Btn);
	*/

	const char* get_ch_text(Channel_setting_type setting) const;

	/*void get_ch_visib_text(touchgfx::Unicode::UnicodeChar* buffer, const uint16_t bufferSize) const;
	void get_ch_visib_text(touchgfx::Unicode::UnicodeChar* buffer, const uint16_t bufferSize) const;
	void get_ch_visib_text(touchgfx::Unicode::UnicodeChar* buffer, const uint16_t bufferSize) const;
	*/

	bool get_ch_visib_val() const { return ch_visib_val; }
	bool get_ch_type_val() const { return ch_type_val; }
	bool get_ch_trig_val() const { return ch_trig_val; }
	uint16_t get_ch_scale_val() const { return ch_scale_val; }
	uint16_t get_ch_y_pos_val() const { return ch_y_pos_val; }
};