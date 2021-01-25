#include "nilan.h"
#include "esphome/core/log.h"

namespace esphome {
namespace nilan {

static const char *TAG = "nilan";

static const uint8_t READ_INPUT_REGISTERS = 0x04;
static const uint8_t READ_HOLDING_REGISTERS = 0x03;
static const uint8_t nilan_REGISTER_COUNT = 10;  // 10x 16-bit registers

void NILAN::on_modbus_data(const std::vector<uint8_t> &data) {
  if (data.size() < 20) {
    ESP_LOGW(TAG, "Invalid size for NILAN!");
    return;
  }
 
  auto nilan_get_16bit = [&](size_t i) -> uint16_t {
    return (uint16_t(data[i + 0]) << 8) | (uint16_t(data[i + 1]) << 0);
  };
  auto nilan_get_32bit = [&](size_t i) -> uint32_t {
    return (uint32_t(nilan_get_16bit(i + 2)) << 16) | (uint32_t(nilan_get_16bit(i + 0)) << 0);
  };

  uint16_t raw_voltage = nilan_get_16bit(0);
  float voltage = raw_voltage / 10.0f;  // max 6553.5 V

  uint32_t raw_current = nilan_get_32bit(2);
  float current = raw_current / 1000.0f;  // max 4294967.295 A

  uint32_t raw_active_power = nilan_get_32bit(6);
  float active_power = raw_active_power / 10.0f;  // max 429496729.5 W

  float active_energy = static_cast<float>(nilan_get_32bit(10));

  uint16_t raw_frequency = nilan_get_16bit(14);
  float frequency = raw_frequency / 10.0f;

  uint16_t raw_power_factor = nilan_get_16bit(16);    //16 er addressen på modbus
  float power_factor = raw_power_factor / 100.0f;

  uint16_t raw_bus_ver = nilan_get_16bit(0);    //16 er addressen på modbus
  float bus_ver = raw_bus_ver / 100.0f;

  uint16_t raw_Input_UserFunc = nilan_get_16bit(100);    //16 er addressen på modbus
  float Input_UserFunc = raw_Input_UserFunc / 100.0f;

  uint16_t raw_Input_AirFilter = nilan_get_16bit(101);    //16 er addressen på modbus
  float Input_AirFilter = raw_Input_AirFilter / 100.0f;
  
  uint16_t raw_Input_Smoke = nilan_get_16bit(103);    //16 er addressen på modbus
  float Input_Smoke = raw_Input_Smoke / 100.0f;
  
  uint16_t raw_Input_Frost_Overht = nilan_get_16bit(105);    //16 er addressen på modbus
  float Input_Frost_Overht = raw_Input_Frost_Overht / 100.0f;
  
  uint16_t raw_Input_UserFunc_2 = nilan_get_16bit(113);    //16 er addressen på modbus
  float Input_UserFunc_2 = raw_Input_UserFunc_2 / 100.0f;
  
  uint16_t raw_Input_DamperClosed = nilan_get_16bit(114);    //16 er addressen på modbus
  float Input_DamperClosed = raw_Input_DamperClosed / 100.0f;
  
  uint16_t raw_Input_DamperOpened = nilan_get_16bit(115);    //16 er addressen på modbus
  float Input_DamperOpened = raw_Input_DamperOpened / 100.0f;
  
  uint16_t raw_Input_T0_Controller = nilan_get_16bit(200);    //16 er addressen på modbus
  float Input_T0_Controller = raw_Input_T0_Controller / 100.0f;
  
  uint16_t raw_Input_T3_Exhaust = nilan_get_16bit(203);    //16 er addressen på modbus
  float Input_T3_Exhaust = raw_Input_T3_Exhaust / 100.0f;
  
  uint16_t raw_Input_T4_Outlet  = nilan_get_16bit(204);    //16 er addressen på modbus
  float Input_T4_Outlet = raw_Input_T4_Outlet / 100.0f;
  
  uint16_t raw_Input_T7_Inlet = nilan_get_16bit(207);    //16 er addressen på modbus
  float Input_T7_Inlet = raw_Input_T7_Inlet / 100.0f;
  
  uint16_t raw_Input_T8_Outdoor = nilan_get_16bit(208);    //16 er addressen på modbus
  float Input_T8_Outdoor = raw_Input_T8_Outdoor / 100.0f;
  
  uint16_t raw_Input_T9_Heater = nilan_get_16bit(209);    //16 er addressen på modbus
  float Input_T9_Heater = raw_Input_T9_Heater / 100.0f;
  
  uint16_t raw_AirQual_RH = nilan_get_16bit(221);    //16 er addressen på modbus
  float AirQual_RH = raw_AirQual_RH / 100.0f;
  
  uint16_t raw_AirQual_CO2 = nilan_get_16bit(222);    //16 er addressen på modbus
  float AirQual_CO2 = raw_AirQual_CO2 / 100.0f;
  
  uint16_t raw_Alarm_Status = nilan_get_16bit(400);    //16 er addressen på modbus
  float Alarm_Status = raw_Alarm_Status / 100.0f;
  
  uint16_t raw_Alarm_List_1_ID = nilan_get_16bit(401);    //16 er addressen på modbus
  float Alarm_List_1_ID = raw_Alarm_List_1_ID / 100.0f;
  
  uint16_t raw_Alarm_List_1_Date = nilan_get_16bit(402);    //16 er addressen på modbus
  float Alarm_List_1_Date = raw_Alarm_List_1_Date / 100.0f;
  
  uint16_t raw_Alarm_List_1_Time = nilan_get_16bit(403);    //16 er addressen på modbus
  float Alarm_List_1_Time = raw_Alarm_List_1_Time / 100.0f;
  
  uint16_t raw_Control_RunAct = nilan_get_16bit(1000);    //16 er addressen på modbus
  float Control_RunAct = raw_Control_RunAct / 100.0f;
  
  uint16_t raw_Control_ModeAct = nilan_get_16bit(1001);    //16 er addressen på modbus
  float Control_ModeAct = raw_Control_ModeAct / 100.0f;
  
  uint16_t raw_Control_StateDisplay = nilan_get_16bit(1002);    //16 er addressen på modbus
  float Control_StateDisplay = raw_Control_StateDisplay / 100.0f;
  
  uint16_t raw_Control_SecInState = nilan_get_16bit(1003);    //16 er addressen på modbus
  float Control_SecInState = raw_Control_SecInState / 100.0f;
  
  uint16_t raw_AirFlow_VentSet = nilan_get_16bit(1100);    //16 er addressen på modbus
  float AirFlow_VentSet = raw_AirFlow_VentSet / 100.0f;
  
  uint16_t raw_AirFlow_InletAct = nilan_get_16bit(1101);    //16 er addressen på modbus
  float AirFlow_InletAct = raw_AirFlow_InletAct / 100.0f;
  
  uint16_t raw_AirFlow_ExhaustAct = nilan_get_16bit(1102);    //16 er addressen på modbus
  float AirFlow_ExhaustAct = raw_AirFlow_ExhaustAct / 100.0f;
  
  uint16_t raw_AirFlow_SinceFiltDay = nilan_get_16bit(1103);    //16 er addressen på modbus
  float AirFlow_SinceFiltDay = raw_AirFlow_SinceFiltDay / 100.0f;
  
  uint16_t raw_AirFlow_ToFiltDay = nilan_get_16bit(1104);    //16 er addressen på modbus
  float AirFlow_ToFiltDay = raw_AirFlow_ToFiltDay / 100.0f;
  
  uint16_t raw_AirTemp_IsSummer = nilan_get_16bit(1200);    //16 er addressen på modbus
  float AirTemp_IsSummer = raw_AirTemp_IsSummer / 100.0f;
  
  uint16_t raw_AirTemp_TempInletSet = nilan_get_16bit(1201);    //16 er addressen på modbus
  float AirTemp_TempInletSet = raw_AirTemp_TempInletSet / 100.0f;
  
  uint16_t raw_AirTemp_TempControl  = nilan_get_16bit(1202);    //16 er addressen på modbus
  float AirTemp_TempControl = raw_AirTemp_TempControl / 100.0f;
  
  uint16_t raw_AirTemp_TempRoom  = nilan_get_16bit(1203);    //16 er addressen på modbus
  float AirTemp_TempRoom = raw_AirTemp_TempRoom / 100.0f;
  
  uint16_t raw_AirTemp_EffPct = nilan_get_16bit(1204);    //16 er addressen på modbus
  float AirTemp_EffPct = raw_AirTemp_EffPct / 100.0f;
  
  uint16_t raw_AirTemp_CapSet = nilan_get_16bit(1205);    //16 er addressen på modbus
  float AirTemp_CapSet = raw_AirTemp_CapSet / 100.0f;
  
  uint16_t raw_AirTemp_CapAct  = nilan_get_16bit(1206);    //16 er addressen på modbus
  float AirTemp_CapAct = raw_AirTemp_CapAct / 100.0f;
  
  uint16_t raw_AirBypass_IsOpen = nilan_get_16bit(3000);    //16 er addressen på modbus
  float AirBypass_IsOpen = raw_AirBypass_IsOpen / 100.0f;
  
  uint16_t raw_Output_AirHeatCap  = nilan_get_16bit(3001);    //16 er addressen på modbus
  float Output_AirHeatCap = raw_Output_AirHeatCap / 100.0f;
  
  uint16_t raw_AirQual_CO2_Enable  = nilan_get_16bit(3003);    //16 er addressen på modbus
  float AirQual_CO2_Enable = raw_AirQual_CO2_Enable / 100.0f;
  
  uint16_t raw_AirFlow_RoomReduce = nilan_get_16bit(3004);    //16 er addressen på modbus
  float AirFlow_RoomReduce = raw_AirFlow_RoomReduce / 100.0f;
  
  uint16_t raw_AirFlow_LastTestDay  = nilan_get_16bit(3005);    //16 er addressen på modbus
  float AirFlow_LastTestDay = raw_AirFlow_LastTestDay / 100.0f;
  
  uint16_t raw_AirFlow_SinceFiltDay = nilan_get_16bit(3006);    //16 er addressen på modbus
  float AirFlow_SinceFiltDay = raw_AirFlow_SinceFiltDay / 100.0f;
  
  uint16_t raw_AirFLow_WinterReduce  = nilan_get_16bit(3007);    //16 er addressen på modbus
  float AirFLow_WinterReduce = raw_AirFLow_WinterReduce / 100.0f;
  
  uint16_t raw_AirTemp_TempSet = nilan_get_16bit(3008);    //16 er addressen på modbus
  float AirTemp_TempSet = raw_AirTemp_TempSet / 100.0f;
  
  uint16_t raw_AirTemp_TempControl  = nilan_get_16bit(3009);    //16 er addressen på modbus
  float AirTemp_TempControl = raw_AirTemp_TempControl / 100.0f;
  




  







  ESP_LOGD(TAG, "nilan AC: V=%.1f V, I=%.3f A, P=%.1f W, E=%.1f Wh, F=%.1f Hz, PF=%.2f", voltage, current, active_power,
           active_energy, frequency, power_factor);
  if (this->voltage_sensor_ != nullptr)
    this->voltage_sensor_->publish_state(voltage);
  if (this->current_sensor_ != nullptr)
    this->current_sensor_->publish_state(current);
  if (this->power_sensor_ != nullptr)
    this->power_sensor_->publish_state(active_power);
  if (this->energy_sensor_ != nullptr)
    this->energy_sensor_->publish_state(active_energy);
  if (this->frequency_sensor_ != nullptr)
    this->frequency_sensor_->publish_state(frequency);
  if (this->power_factor_sensor_ != nullptr)
    this->power_factor_sensor_->publish_state(power_factor);
  if (this->bus_ver_sensor_ != nullptr)
    this->bus_ver_sensor_->publish_state(bus_ver);
  if (this->Input_UserFunc_sensor_ != nullptr)
    this->Input_UserFunc_sensor_->publish_state(Input_UserFunc);
  if (this->Input_AirFilter_sensor_ != nullptr)
    this->Input_AirFilter_sensor_->publish_state(Input_AirFilter);
  if (this->Input_Smoke_sensor_ != nullptr)
    this->Input_Smoke_sensor_->publish_state(Input_Smoke);
  if (this->Input_Frost_Overht_sensor_ != nullptr)
    this->Input_Frost_Overht_sensor_->publish_state(Input_Frost_Overht);
  if (this->Input_UserFunc_2_sensor_ != nullptr)
    this->Input_UserFunc_2_sensor_->publish_state(Input_UserFunc_2);
  if (this->Input_DamperClosed_sensor_ != nullptr)
    this->Input_DamperClosed_sensor_->publish_state(Input_DamperClosed);
  if (this->Input_DamperOpened_sensor_ != nullptr)
    this->Input_DamperOpened_sensor_->publish_state(Input_DamperOpened);
  if (this->Input_T0_Controller_sensor_ != nullptr)
    this->Input_T0_Controller_sensor_->publish_state(Input_T0_Controller);
  if (this->Input_T3_Exhaust_sensor_ != nullptr)
    this->Input_T3_Exhaust_sensor_->publish_state(Input_T3_Exhaust);
  if (this->Input_T4_Outlet_sensor_ != nullptr)
    this->Input_T4_Outlet_sensor_->publish_state(Input_T4_Outlet);
  if (this->Input_T7_Inlet_sensor_ != nullptr)
    this->Input_T7_Inlet_sensor_->publish_state(Input_T7_Inlet);
  if (this->Input_T8_Outdoor_sensor_ != nullptr)
    this->Input_T8_Outdoor_sensor_->publish_state(Input_T8_Outdoor);
  if (this->Input_T9_Heater_sensor_ != nullptr)
    this->Input_T9_Heater_sensor_->publish_state(Input_T9_Heater);
  if (this->AirQual_RH_sensor_ != nullptr)
    this->AirQual_RH_sensor_->publish_state(AirQual_RH);
  if (this->AirQual_CO2_sensor_ != nullptr)
    this->AirQual_CO2_sensor_->publish_state(AirQual_CO2);
  if (this->Alarm_Status_sensor_ != nullptr)
    this->Alarm_Status_sensor_->publish_state(Alarm_Status);
  if (this->Alarm_List_1_ID_sensor_ != nullptr)
    this->Alarm_List_1_ID_sensor_->publish_state(Alarm_List_1_ID);
  if (this->Alarm_List_1_Date_sensor_ != nullptr)
    this->Alarm_List_1_Date_sensor_->publish_state(Alarm_List_1_Date);
  if (this->Alarm_List_1_Time_sensor_ != nullptr)
    this->Alarm_List_1_Time_sensor_->publish_state(Alarm_List_1_Time);
  if (this->Control_RunAct_sensor_ != nullptr)
    this->Control_RunAct_sensor_->publish_state(Control_RunAct);
  if (this->Control_ModeAct_sensor_ != nullptr)
    this->Control_ModeAct_sensor_->publish_state(Control_ModeAct);
  if (this->Control_StateDisplay_sensor_ != nullptr)
    this->Control_StateDisplay_sensor_->publish_state(Control_StateDisplay);
  if (this->Control_SecInState_sensor_ != nullptr)
    this->Control_SecInState_sensor_->publish_state(Control_SecInState);
  if (this->AirFlow_VentSet_sensor_ != nullptr)
    this->AirFlow_VentSet_sensor_->publish_state(AirFlow_VentSet);
  if (this->AirFlow_InletAct_sensor_ != nullptr)
    this->AirFlow_InletAct_sensor_->publish_state(AirFlow_InletAct);
  if (this->AirFlow_ExhaustAct_sensor_ != nullptr)
    this->AirFlow_ExhaustAct_sensor_->publish_state(AirFlow_ExhaustAct);
  if (this->AirFlow_SinceFiltDay_sensor_ != nullptr)
    this->AirFlow_SinceFiltDay_sensor_->publish_state(AirFlow_SinceFiltDay);
  if (this->AirFlow_ToFiltDay_sensor_ != nullptr)
    this->AirFlow_ToFiltDay_sensor_->publish_state(AirFlow_ToFiltDay);
  if (this->AirTemp_IsSummer_sensor_ != nullptr)
    this->AirTemp_IsSummer_sensor_->publish_state(AirTemp_IsSummer);
  if (this->AirTemp_TempInletSet_sensor_ != nullptr)
    this->AirTemp_TempInletSet_sensor_->publish_state(AirTemp_TempInletSet);
  if (this->AirTemp_TempControl_sensor_ != nullptr)
    this->AirTemp_TempControl_sensor_->publish_state(AirTemp_TempControl);
  if (this->AirTemp_TempRoom_sensor_ != nullptr)
    this->AirTemp_TempRoom_sensor_->publish_state(AirTemp_TempRoom);
  if (this->AirTemp_EffPct_sensor_ != nullptr)
    this->AirTemp_EffPct_sensor_->publish_state(AirTemp_EffPct);
  if (this->AirTemp_CapSet_sensor_ != nullptr)
    this->AirTemp_CapSet_sensor_->publish_state(AirTemp_CapSet);
  if (this->AirTemp_CapAct_sensor_ != nullptr)
    this->AirTemp_CapAct_sensor_->publish_state(AirTemp_CapAct);
  if (this->AirBypass_IsOpen_sensor_ != nullptr)
    this->AirBypass_IsOpen_sensor_->publish_state(AirBypass_IsOpen);
  if (this->Output_AirHeatCap_sensor_ != nullptr)
    this->Output_AirHeatCap_sensor_->publish_state(Output_AirHeatCap);
  if (this->AirQual_CO2_Enable_sensor_ != nullptr)
    this->AirQual_CO2_Enable_sensor_->publish_state(AirQual_CO2_Enable);
  if (this->AirFlow_RoomReduce_sensor_ != nullptr)
    this->AirFlow_RoomReduce_sensor_->publish_state(AirFlow_RoomReduce);
  if (this->AirFlow_LastTestDay_sensor_ != nullptr)
    this->AirFlow_LastTestDay_sensor_->publish_state(AirFlow_LastTestDay);
  if (this->AirFlow_SinceFiltDay_sensor_ != nullptr)
    this->AirFlow_SinceFiltDay_sensor_->publish_state(AirFlow_SinceFiltDay);
  if (this->AirFLow_WinterReduce_sensor_ != nullptr)
    this->AirFLow_WinterReduce_sensor_->publish_state(AirFLow_WinterReduce);
  if (this->AirTemp_TempSet_sensor_ != nullptr)
    this->AirTemp_TempSet_sensor_->publish_state(AirTemp_TempSet);
  if (this->AirTemp_TempControl_sensor_ != nullptr)
    this->AirTemp_TempControl_sensor_->publish_state(AirTemp_TempControl);
}

void NILAN::update() { this->send(READ_INPUT_REGISTERS, 0, nilan_REGISTER_COUNT);
                        this->send(READ_HOLDING_REGISTERS, 0, nilan_REGISTER_COUNT); }
void NILAN::dump_config() {
  ESP_LOGCONFIG(TAG, "NILAN:");
  ESP_LOGCONFIG(TAG, "  Address: 0x%02X", this->address_);
  // LOG_SENSOR("", "Voltage", this->voltage_sensor_);
  // LOG_SENSOR("", "Current", this->current_sensor_);
  // LOG_SENSOR("", "Power", this->power_sensor_);
  // LOG_SENSOR("", "Energy", this->energy_sensor_);
  // LOG_SENSOR("", "Frequency", this->frequency_sensor_);
  // LOG_SENSOR("", "Power Factor", this->power_factor_sensor_);
}

}  // namespace nilan
}  // namespace esphome
