
/* 
 *  테스트 대상 프로그램은 아래의 모듈로 구성된다.
 *
 * Thermostat: 설정 온도를 입력 받아 감지된 온도와의 차에 따라 냉난방기를 제어하는 역할을 한다.
 * SetDesiredTemperature(): 목표 온도를 설정하는 API
 * wakeup(): 타이머에 의해 주기적으로 실행되는 API. 주요 제어 로직이 있다.
 * FanController: 송풍팬을 제어하는 모듈
 * setFanSpeed(): 인자로 전달한 속도(rpm)로 송풍팬을 가동시킨다.
 * SwitchController: on/off를 제어하는 추상인터페이스
 * HeaterController: 난방기를 제어하는 모듈. SwitchController의 turnOn/turnOff를 상속하여 구현됨
 * turnOn(): 난방기를 켜는 API
 * TurnOff(): 난방기를 끄는 API
 * CoolerController: 냉방기를 제어하는 모듈. SwitchController의 turnOn/turnOff를 상속하여 구현됨
 * turnOn(): 냉방기를 켜는 API
 * turnOff(): 냉방기를 끄는 API
 * SensorProbe: 현재 온도를 반환하는 모듈
 * getTemperature(): 현재 온도를 반환하는 API
 */

/************************************
  FanController.h  소스 코드 내용
 ************************************
 typedef unsigned short Rpm;

 class FanController
 {
 public:
 virtual void setFanSpeed(Rpm speed);
 };
 *************************************/

/************************************
  SwitchController.h  소스 코드 내용
 ************************************
 class SwitchController
 {
 public:
 virtual ~SwitchController() = default;
 virtual void turnOn() = 0;
 virtual void turnOff() = 0;
 };
 *************************************/

/************************************
  HeaterController.h  소스 코드 내용
 ************************************
#include "SwitchController.h"

class HeaterController : public SwitchController
{
public:
void turnOn();
void turnOff();
};
 *************************************/

/************************************
  CoolerController.h  소스 코드 내용
 ************************************
#include "SwitchController.h"

class CoolerController : public SwitchController
{
public:
void turnOn();
void turnOff();
};
 *************************************/

/************************************
  SensorProbe.h  소스 코드 내용
 ************************************
 class SensorProbe
 {
 public:
 virtual int getTemperature() const;
 };
 *************************************/

/************************************
  테스트 대상 Thermostat.cpp  소스 코드 내용
 ************************************

#include "Thermostat.h"

#include "SensorProbe.h"
#include "FanController.h"

#include <assert.h>
#include <iostream>
#define LOG(probeInfo) std::cout << probeInfo << std::endl;



Thermostat::Thermostat(SwitchController* cooler, SwitchController* heater, FanController* fan, SensorProbe* sensor)
: cooler_(cooler), heater_(heater), fan_(fan), sensor_(sensor)
{
fan_->setFanSpeed(0);
wasHeaterOrCooler = 0;
desiredTemperature_ = -1;  // unset
}

Thermostat::~Thermostat()
{
}

void Thermostat::SetDesiredTemperature(Celsius desired)
{
desiredTemperature_ = desired;
if (desiredTemperature_ < 15)
desiredTemperature_ = 15;
}



void Thermostat::wakeup()
{
const int  currentTemperature = sensor_->getTemperature();

if (currentTemperature == desiredTemperature_)
{
if (wasHeaterOrCooler == 0)
{
heater_->turnOff();
LOG("STOP HEATER");
}
else if (wasHeaterOrCooler == 1)
{
cooler_->turnOff();
LOG("STOP COOLER");
}
else
{
}
}
else
{
if (currentTemperature < desiredTemperature_)
{
cooler_->turnOff();

heater_->turnOn();
wasHeaterOrCooler = 0;

if (desiredTemperature_ - currentTemperature >= 10)
{
fan_->setFanSpeed(500);
LOG("HEATER 500");
}
else if (desiredTemperature_ - currentTemperature > 2)
fan_->setFanSpeed(200);
LOG("HEATER 200");
}
else
{
	fan_->setFanSpeed(0);
	LOG("HEATER 0");
}
}
else
{
	heater_->turnOff();

	cooler_->turnOn();
	wasHeaterOrCooler = 1;

	if (currentTemperature - desiredTemperature_ >= 10)
	{
		fan_->setFanSpeed(500);
		LOG("COOLER 500");
	}
	else if (currentTemperature - desiredTemperature_ > 2)
	{
		fan_->setFanSpeed(200);
		LOG("COOLER 200");
	}
	else
	{
		fan_->setFanSpeed(0);
		LOG("COOLER 0");
	}
}
}
}
*************************************/


#include "Thermostat.h"

#include "CoolerController.h"
#include "HeaterController.h"
#include "SensorProbe.h"
#include "FanController.h"

#include <cassert>

// TODO: 필요한 코드를 추가하여 테스트를 위한 test double을 작성하시오.

class SwitchControllerSpy : public SwitchController
{
	public:
		void turnOn() override
		{
			// FIXME
		}

		void turnOff() override
		{
			// FIXME
		}
};


class FanControllerSpy : public FanController
{
	public:
		void setFanSpeed(Rpm rpm) override
		{
			// FIXME
		}
};


class FakeSensorProbe : public SensorProbe
{
	public:
		int getTemperature() const override
		{
			return -1; // FIXME
		}
};


// 아래 ThermostatTest 클래스의 테스트 함수 run_1~5에 테스트 코드를 작성하시오.
// 필요한 경우 ThermostatTest 클래스에 코드를 추가로 작성하시오.
// 단, run_1~5 테스트 함수의 이름은 수정해서는 안된다.
class ThermostatTest
{
	protected:
		SwitchControllerSpy* coolerSpy;
		SwitchControllerSpy* heaterSpy;
		FanControllerSpy* fanSpy;
		FakeSensorProbe* fakeSensor;

	public:
		ThermostatTest()
		{
			coolerSpy = new SwitchControllerSpy;
			heaterSpy = new SwitchControllerSpy;
			fanSpy = new FanControllerSpy;
			fakeSensor = new FakeSensorProbe;
		}

		~ThermostatTest()
		{
			delete coolerSpy;
			delete heaterSpy;
			delete fanSpy;
			delete fakeSensor;
		}

		void run_1()
		{
			// TODO: 난방기가 켜지고 송풍팬을 500rpm으로 동작시키는 테스트 코드를 작성하시오.
			
		}

		void run_2()
		{
			// TODO: 난방기가 켜지고 송풍팬을 200rpm으로 동작시키는 테스트 코드를 작성하시오.
		}

		void run_3()
		{
			// TODO: 난방기가 켜지고 송풍팬을 0rpm으로 동작시키는 테스트 코드를 작성하시오.
		}

		void run_4()
		{
			// TODO: 난방기가 꺼지고 송풍팬을 0rpm으로 동작시키는 테스트 코드를 작성하시오.
		}

		void run_5()
		{
			// TODO: 냉방기가 켜지고 송풍팬을 500rpm으로 동작시키는 테스트 코드를 작성하시오.
		}
};

// NOTE 아래 코드는 수정 불가
int main()
{
	ThermostatTest().run_1();
	ThermostatTest().run_2();
	ThermostatTest().run_3();
	ThermostatTest().run_4();
	ThermostatTest().run_5();

	return 0;
}
