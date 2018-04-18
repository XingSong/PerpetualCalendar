//
//  LunarSolarConverter.h
//公历(阳历) 农历(阴历)转换，支持时间段从1900 - 2100
#ifndef __LunarSolarConverter__
#define __LunarSolarConverter__

typedef struct Lunar
{
    bool isleap;
    int lunarDay;
    int lunarMonth;
    int lunarYear;
} Lunar;

typedef struct Solar
{
    int solarDay;
    int solarMonth;
    int solarYear;
} Solar;
/**
*农历转公历
*/
Solar LunarToSolar(Lunar lunar);
/**
*公历转农历
*/
Lunar SolarToLunar(Solar solar);


#endif /* defined(__LunarSolarConverter__) */
