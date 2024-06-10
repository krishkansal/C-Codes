#ifndef EVCAR_H
#define EVCAR_H
#include <iostream>
#include <string>
#include "PlatFormType.h"


class EvCar
{
private:
    std::string m_car_id;
    int m_battery_charging_time;
    PlatFormType m_platform;
    float m_chassis_length;
    int m_seat_count;
    int m_top_speed;
public:
    EvCar() = default;          //default
    EvCar(const EvCar&) = delete;  //copy constructor
    EvCar(EvCar&&) = delete;  //move constructor
    EvCar& operator = (const EvCar&) = delete; 
    EvCar& operator =(EvCar&&) = delete;
    ~EvCar() =default;  //destructor

    EvCar(std::string car_id, int battery_charging_time, PlatFormType plateform, float chassis_length, int seat_count, int top_speed);

    std::string carId() const { return m_car_id; }

    int batteryChargingTime() const { return m_battery_charging_time; }

    PlatFormType platform() const { return m_platform; }

    float chassisLength() const { return m_chassis_length; }

    int seatCount() const { return m_seat_count; }

    int topSpeed() const { return m_top_speed; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
    
};

#endif // EVCAR_H
