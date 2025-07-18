#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

#define DATA_BUFFER_SIZE 10800 // jesli zmiana w main.c -> zaktualizowac
#define HOR_PX_NUM 540
#define BUFF2HPN_SIZE_COEFF DATA_BUFFER_SIZE/HOR_PX_NUM

extern uint32_t GUI_buffer[DATA_BUFFER_SIZE];
extern volatile uint8_t buffer_ready_flag;

class Screen1View : public Screen1ViewBase
{
private:
    uint32_t tick_counter;
    uint32_t processed_data[HOR_PX_NUM];

    void data_processing();
    void data_decimation();
    void data_printing();

public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void handleTickEvent();

protected:
};

#endif // SCREEN1VIEW_HPP
