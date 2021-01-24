#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/modbus/modbus.h"

namespace esphome {
namespace nilan {

class NILAN : public PollingComponent, public modbus::ModbusDevice {
 public:
  void set_voltage_sensor(sensor::Sensor *voltage_sensor) { voltage_sensor_ = voltage_sensor; }
  void set_current_sensor(sensor::Sensor *current_sensor) { current_sensor_ = current_sensor; }
  void set_power_sensor(sensor::Sensor *power_sensor) { power_sensor_ = power_sensor; }
  void set_energy_sensor(sensor::Sensor *energy_sensor) { energy_sensor_ = energy_sensor; }
  void set_frequency_sensor(sensor::Sensor *frequency_sensor) { frequency_sensor_ = frequency_sensor; }
  void set_power_factor_sensor(sensor::Sensor *power_factor_sensor) { power_factor_sensor_ = power_factor_sensor; }
  void set_bus_ver_sensor(sensor::Sensor *bus_ver_sensor) { bus_ver_sensor_ = bus_ver_sensor; }
  void set_Input_UserFunc_sensor(sensor::Sensor *Input_UserFunc_sensor) { Input_UserFunc_sensor_ = Input_UserFunc_sensor; }
  void set_Input_AirFilter_sensor(sensor::Sensor *Input_AirFilter_sensor) { Input_AirFilter_sensor_ = Input_AirFilter_sensor; }
  void set_Input_Smoke_sensor(sensor::Sensor *Input_Smoke_sensor) { Input_Smoke_sensor_ = Input_Smoke_sensor; }
  void set_Input_Frost_Overht_sensor(sensor::Sensor *Input_Frost_Overht_sensor) { Input_Frost_Overht_sensor_ = Input_Frost_Overht_sensor; }
  void set_Input_UserFunc_2_sensor(sensor::Sensor *Input_UserFunc_2_sensor) { Input_UserFunc_2_sensor_ = Input_UserFunc_2_sensor; }
  void set_Input_DamperClosed_sensor(sensor::Sensor *Input_DamperClosed_sensor) { Input_DamperClosed_sensor_ = Input_DamperClosed_sensor; }
  void set_Input_DamperOpened_sensor(sensor::Sensor *Input_DamperOpened_sensor) { Input_DamperOpened_sensor_ = Input_DamperOpened_sensor; }
  void set_Input_T0_Controller_sensor(sensor::Sensor *Input_T0_Controller_sensor) { Input_T0_Controller_sensor_ = Input_T0_Controller_sensor; }
  void set_Input_T3_Exhaust_sensor(sensor::Sensor *Input_T3_Exhaust_sensor) { Input_T3_Exhaust_sensor_ = Input_T3_Exhaust_sensor; }
  void set_Input_T4_Outlet_sensor(sensor::Sensor *Input_T4_Outlet_sensor) { Input_T4_Outlet_sensor_ = Input_T4_Outlet_sensor; }
  void set_Input_T7_Inlet_sensor(sensor::Sensor *Input_T7_Inlet_sensor) { Input_T7_Inlet_sensor_ = Input_T7_Inlet_sensor; }
  void set_Input_T8_Outdoor_sensor(sensor::Sensor *Input_T8_Outdoor_sensor) { Input_T8_Outdoor_sensor_ = Input_T8_Outdoor_sensor; }
  void set_Input_T9_Heater_sensor(sensor::Sensor *Input_T9_Heater_sensor) { Input_T9_Heater_sensor_ = Input_T9_Heater_sensor; }
  void set_AirQual_RH_sensor(sensor::Sensor *AirQual_RH_sensor) { AirQual_RH_sensor_ = AirQual_RH_sensor; }
  void set_AirQual_CO2_sensor(sensor::Sensor *AirQual_CO2_sensor) { AirQual_CO2_sensor_ = AirQual_CO2_sensor; }
  void set_Alarm_Status_sensor(sensor::Sensor *Alarm_Status_sensor) { Alarm_Status_sensor_ = Alarm_Status_sensor; }
  void set_Alarm_List_1_ID_sensor(sensor::Sensor *Alarm_List_1_ID_sensor) { Alarm_List_1_ID_sensor_ = Alarm_List_1_ID_sensor; }
  void set_Alarm_List_1_Date_sensor(sensor::Sensor *Alarm_List_1_Date_sensor) { Alarm_List_1_Date_sensor_ = Alarm_List_1_Date_sensor; }
  void set_Alarm_List_1_Time_sensor(sensor::Sensor *Alarm_List_1_Time_sensor) {Alarm_List_1_Time_sensor_ = Alarm_List_1_Time_sensor; }
  void set_Control_RunAct_sensor(sensor::Sensor *Control_RunAct_sensor) { Control_RunAct_sensor_ = Control_RunAct_sensor; }
  void set_Control_ModeAct_sensor(sensor::Sensor *Control_ModeAct_sensor) { Control_ModeAct_sensor_ = Control_ModeAct_sensor; }
  void set_Control_StateDisplay_sensor(sensor::Sensor *Control_StateDisplay_sensor) { Control_StateDisplay_sensor_ = Control_StateDisplay_sensor; }
  void set_Control_SecInState_sensor(sensor::Sensor *Control_SecInState_sensor) { Control_SecInState_sensor_ = Control_SecInState_sensor; }
  void set_AirFlow_VentSet_sensor(sensor::Sensor *AirFlow_VentSet_sensor) { AirFlow_VentSet_sensor_ = AirFlow_VentSet_sensor; }
  void set_AirFlow_InletAct_sensor(sensor::Sensor *AirFlow_InletAct_sensor) { AirFlow_InletAct_sensor_ = AirFlow_InletAct_sensor; }
  void set_AirFlow_ExhaustAct_sensor(sensor::Sensor *AirFlow_ExhaustAct_sensor) { AirFlow_ExhaustAct_sensor_ = AirFlow_ExhaustAct_sensor; }
  void set_AirFlow_SinceFiltDay_sensor(sensor::Sensor *AirFlow_SinceFiltDay_sensor) { AirFlow_SinceFiltDay_sensor_ = AirFlow_SinceFiltDay_sensor; }
  void set_AirFlow_ToFiltDay_sensor(sensor::Sensor *AirFlow_ToFiltDay_sensor) { AirFlow_ToFiltDay_sensor_ = AirFlow_ToFiltDay_sensor; }
  void set_AirTemp_IsSummer_sensor(sensor::Sensor *AirTemp_IsSummer_sensor) { AirTemp_IsSummer_sensor_ = AirTemp_IsSummer_sensor; }
  void set_AirTemp_TempInletSet_sensor(sensor::Sensor *AirTemp_TempInletSet_sensor) { AirTemp_TempInletSet_sensor_ = AirTemp_TempInletSet_sensor; }
  void set_AirTemp_TempControl_sensor(sensor::Sensor *AirTemp_TempControl_sensor) { AirTemp_TempControl_sensor_ = AirTemp_TempControl_sensor; }
  void set_AirTemp_TempRoom_sensor(sensor::Sensor *AirTemp_TempRoom_sensor) { AirTemp_TempRoom_sensor_ = AirTemp_TempRoom_sensor; }
  void set_AirTemp_EffPct_sensor(sensor::Sensor *AirTemp_EffPct_sensor) { AirTemp_EffPct_sensor_ = AirTemp_EffPct_sensor; }
  void set_AirTemp_CapSet_sensor(sensor::Sensor *AirTemp_CapSet_sensor) { AirTemp_CapSet_sensor_ = AirTemp_CapSet_sensor; }
  void set_AirTemp_CapAct_sensor(sensor::Sensor *AirTemp_CapAct_sensor) { AirTemp_CapAct_sensor_ = AirTemp_CapAct_sensor; }
  void set_AirBypass_IsOpen_sensor(sensor::Sensor *AirBypass_IsOpen_sensor) { AirBypass_IsOpen_sensor_ = AirBypass_IsOpen_sensor; }
  void set_Output_AirHeatCap_sensor(sensor::Sensor *Output_AirHeatCap_sensor) { Output_AirHeatCap_sensor_ = Output_AirHeatCap_sensor; }
  void set_AirQual_CO2_Enable_sensor(sensor::Sensor *AirQual_CO2_Enable_sensor) { AirQual_CO2_Enable_sensor_ = AirQual_CO2_Enable_sensor; }
  void set_AirFlow_RoomReduce_sensor(sensor::Sensor *AirFlow_RoomReduce_sensor) { AirFlow_RoomReduce_sensor_ = AirFlow_RoomReduce_sensor; }
  void set_AirFlow_LastTestDay_sensor(sensor::Sensor *AirFlow_LastTestDay_sensor) { AirFlow_LastTestDay_sensor_ = AirFlow_LastTestDay_sensor; }
  void set_AirFlow_SinceFiltDay_sensor(sensor::Sensor *AirFlow_SinceFiltDay_sensor) { AirFlow_SinceFiltDay_sensor_ = AirFlow_SinceFiltDay_sensor; }
  void set_AirFLow_WinterReduce_sensor(sensor::Sensor *AirFLow_WinterReduce_sensor) { AirFLow_WinterReduce_sensor_ = AirFLow_WinterReduce_sensor; }
  void set_AirTemp_TempSet_sensor(sensor::Sensor *AirTemp_TempSet_sensor) { AirTemp_TempSet_sensor_ = AirTemp_TempSet_sensor; }
  void set_AirTemp_TempControl_sensor(sensor::Sensor *AirTemp_TempControl_sensor) { AirTemp_TempControl_sensor_ = AirTemp_TempControl_sensor; }




  void update() override;

  void on_modbus_data(const std::vector<uint8_t> &data) override;

  void dump_config() override;

 protected:
  sensor::Sensor *voltage_sensor_;
  sensor::Sensor *current_sensor_;
  sensor::Sensor *power_sensor_;
  sensor::Sensor *energy_sensor_;
  sensor::Sensor *frequency_sensor_;
  sensor::Sensor *power_factor_sensor_;
  sensor::Sensor *bus_ver_sensor_;
  sensor::Sensor *Input_UserFunc_sensor_;
  sensor::Sensor *Input_AirFilter_sensor_;
  sensor::Sensor *Input_Smoke_sensor_;
  sensor::Sensor *Input_Frost_Overht_sensor_;
  sensor::Sensor *Input_UserFunc_2_sensor_;
  sensor::Sensor *Input_DamperClosed_sensor_;
  sensor::Sensor *Input_DamperOpened_sensor_;
  sensor::Sensor *Input_T0_Controller_sensor_;
  sensor::Sensor *Input_T3_Exhaust_sensor_;
  sensor::Sensor *Input_T4_Outlet_sensor_;
  sensor::Sensor *Input_T7_Inlet_sensor_;
  sensor::Sensor *Input_T8_Outdoor_sensor_;
  sensor::Sensor *Input_T9_Heater_sensor_;
  sensor::Sensor *AirQual_RH_sensor_;
  sensor::Sensor *AirQual_CO2_sensor_;
  sensor::Sensor *Alarm_Status_sensor_;
  sensor::Sensor *Alarm_List_1_ID_sensor_;
  sensor::Sensor *Alarm_List_1_Date_sensor_;
  sensor::Sensor *Alarm_List_1_Time_sensor_;
  sensor::Sensor *Control_RunAct_sensor_;
  sensor::Sensor *Control_ModeAct_sensor_;
  sensor::Sensor *Control_StateDisplay_sensor_;
  sensor::Sensor *Control_SecInState_sensor_;
  sensor::Sensor *AirFlow_VentSet_sensor_;
  sensor::Sensor *AirFlow_InletAct_sensor_;
  sensor::Sensor *AirFlow_ExhaustAct_sensor_;
  sensor::Sensor *AirFlow_SinceFiltDay_sensor_;
  sensor::Sensor *AirFlow_ToFiltDay_sensor_;
  sensor::Sensor *AirTemp_IsSummer_sensor_;
  sensor::Sensor *AirTemp_TempInletSet_sensor_;
  sensor::Sensor *AirTemp_TempControl_sensor_;
  sensor::Sensor *AirTemp_TempRoom_sensor_;
  sensor::Sensor *AirTemp_EffPct_sensor_;
  sensor::Sensor *AirTemp_CapSet_sensor_;
  sensor::Sensor *AirTemp_CapAct_sensor_;
  sensor::Sensor *AirBypass_IsOpen_sensor_;
  sensor::Sensor *Output_AirHeatCap_sensor_;
  sensor::Sensor *AirQual_CO2_Enable_sensor_;
  sensor::Sensor *AirFlow_RoomReduce_sensor_;
  sensor::Sensor *AirFlow_LastTestDay_sensor_;
  sensor::Sensor *AirFlow_SinceFiltDay_sensor_;
  sensor::Sensor *AirFLow_WinterReduce_sensor_;
  sensor::Sensor *AirTemp_TempSet_sensor_;
  sensor::Sensor *AirTemp_TempControl_sensor_;
};

}  // namespace nilan
}  // namespace esphome
