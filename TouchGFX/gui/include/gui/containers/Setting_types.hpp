#ifndef SETTING_TYPES_HPP
#define SETTING_TYPES_HPP

enum Setting_type {
    CH_VISIB,
    CH_TYPE,
    CH_TRIG,
    CH_SCALE,
    CH_Y_POS,
    TIMEBASE,
    SIZE_OF_Setting_type
};

#define CH_SCALE_MAX 10
#define CH_SCALE_MIN 1
// #define CH_Y_POS_MIN = 0 // <- zdefiniowane w VEP
// #define CH_Y_POS_MIN = 0 // <- zdefiniowane w VEP
#define TIMEBASE_MAX 50000
#define TIMEBASE_MIN 10 // to zdefiniowac ponownie w zaleznosci od mozliwosci zegara + prescalera + cykli adc

#endif // SETTING_TYPES_HPP