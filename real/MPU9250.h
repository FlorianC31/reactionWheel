/* 
 * File:   MPU9250.h
 * Author: Laurent Alloza <laurent.alloza at isae.fr>
 *
 * Created on 31 mai 2016, 10:11
 */

#ifndef _MPU9250_H_
#define _MPU9250_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Magnetometer Registers */
#define MPU9150_RA_MAG_ADDRESS 0x0C
#define MPU9150_RA_MAG_XOUT_L  0x03
#define MPU9150_RA_MAG_XOUT_H  0x04
#define MPU9150_RA_MAG_YOUT_L  0x05
#define MPU9150_RA_MAG_YOUT_H  0x06
#define MPU9150_RA_MAG_ZOUT_L  0x07
#define MPU9150_RA_MAG_ZOUT_H  0x08

/* IMU Registers */
#define MPU9250_ADDRESS_AD0_LOW     0x68 // address pin low (GND), default for InvenSense evaluation board
#define MPU9250_ADDRESS_AD0_HIGH    0x69 // address pin high (VCC)
#define MPU9250_DEFAULT_ADDRESS     MPU9250_ADDRESS_AD0_LOW

#define MPU9250_RA_XG_OFFS_TC       0x00 //[7] PWR_MODE, [6:1] XG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU9250_RA_YG_OFFS_TC       0x01 //[7] PWR_MODE, [6:1] YG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU9250_RA_ZG_OFFS_TC       0x02 //[7] PWR_MODE, [6:1] ZG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU9250_RA_X_FINE_GAIN      0x03 //[7:0] X_FINE_GAIN
#define MPU9250_RA_Y_FINE_GAIN      0x04 //[7:0] Y_FINE_GAIN
#define MPU9250_RA_Z_FINE_GAIN      0x05 //[7:0] Z_FINE_GAIN
#define MPU9250_RA_XA_OFFS_H        0x06 //[15:0] XA_OFFS
#define MPU9250_RA_XA_OFFS_L_TC     0x07
#define MPU9250_RA_YA_OFFS_H        0x08 //[15:0] YA_OFFS
#define MPU9250_RA_YA_OFFS_L_TC     0x09
#define MPU9250_RA_ZA_OFFS_H        0x0A //[15:0] ZA_OFFS
#define MPU9250_RA_ZA_OFFS_L_TC     0x0B
#define MPU9250_RA_XG_OFFS_USRH     0x13 //[15:0] XG_OFFS_USR
#define MPU9250_RA_XG_OFFS_USRL     0x14
#define MPU9250_RA_YG_OFFS_USRH     0x15 //[15:0] YG_OFFS_USR
#define MPU9250_RA_YG_OFFS_USRL     0x16
#define MPU9250_RA_ZG_OFFS_USRH     0x17 //[15:0] ZG_OFFS_USR
#define MPU9250_RA_ZG_OFFS_USRL     0x18
#define MPU9250_RA_SMPLRT_DIV       0x19
#define MPU9250_RA_CONFIG           0x1A
#define MPU9250_RA_GYRO_CONFIG      0x1B
#define MPU9250_RA_ACCEL_CONFIG     0x1C
#define MPU9250_RA_FF_THR           0x1D
#define MPU9250_RA_FF_DUR           0x1E
#define MPU9250_RA_MOT_THR          0x1F
#define MPU9250_RA_MOT_DUR          0x20
#define MPU9250_RA_ZRMOT_THR        0x21
#define MPU9250_RA_ZRMOT_DUR        0x22
#define MPU9250_RA_FIFO_EN          0x23
#define MPU9250_RA_I2C_MST_CTRL     0x24
#define MPU9250_RA_I2C_SLV0_ADDR    0x25
#define MPU9250_RA_I2C_SLV0_REG     0x26
#define MPU9250_RA_I2C_SLV0_CTRL    0x27
#define MPU9250_RA_I2C_SLV1_ADDR    0x28
#define MPU9250_RA_I2C_SLV1_REG     0x29
#define MPU9250_RA_I2C_SLV1_CTRL    0x2A
#define MPU9250_RA_I2C_SLV2_ADDR    0x2B
#define MPU9250_RA_I2C_SLV2_REG     0x2C
#define MPU9250_RA_I2C_SLV2_CTRL    0x2D
#define MPU9250_RA_I2C_SLV3_ADDR    0x2E
#define MPU9250_RA_I2C_SLV3_REG     0x2F
#define MPU9250_RA_I2C_SLV3_CTRL    0x30
#define MPU9250_RA_I2C_SLV4_ADDR    0x31
#define MPU9250_RA_I2C_SLV4_REG     0x32
#define MPU9250_RA_I2C_SLV4_DO      0x33
#define MPU9250_RA_I2C_SLV4_CTRL    0x34
#define MPU9250_RA_I2C_SLV4_DI      0x35
#define MPU9250_RA_I2C_MST_STATUS   0x36
#define MPU9250_RA_INT_PIN_CFG      0x37
#define MPU9250_RA_INT_ENABLE       0x38
#define MPU9250_RA_DMP_INT_STATUS   0x39
#define MPU9250_RA_INT_STATUS       0x3A
#define MPU9250_RA_ACCEL_XOUT_H     0x3B
#define MPU9250_RA_ACCEL_XOUT_L     0x3C
#define MPU9250_RA_ACCEL_YOUT_H     0x3D
#define MPU9250_RA_ACCEL_YOUT_L     0x3E
#define MPU9250_RA_ACCEL_ZOUT_H     0x3F
#define MPU9250_RA_ACCEL_ZOUT_L     0x40
#define MPU9250_RA_TEMP_OUT_H       0x41
#define MPU9250_RA_TEMP_OUT_L       0x42
#define MPU9250_RA_GYRO_XOUT_H      0x43
#define MPU9250_RA_GYRO_XOUT_L      0x44
#define MPU9250_RA_GYRO_YOUT_H      0x45
#define MPU9250_RA_GYRO_YOUT_L      0x46
#define MPU9250_RA_GYRO_ZOUT_H      0x47
#define MPU9250_RA_GYRO_ZOUT_L      0x48
#define MPU9250_RA_EXT_SENS_DATA_00     0x49
#define MPU9250_RA_EXT_SENS_DATA_01     0x4A
#define MPU9250_RA_EXT_SENS_DATA_02     0x4B
#define MPU9250_RA_EXT_SENS_DATA_03     0x4C
#define MPU9250_RA_EXT_SENS_DATA_04     0x4D
#define MPU9250_RA_EXT_SENS_DATA_05     0x4E
#define MPU9250_RA_EXT_SENS_DATA_06     0x4F
#define MPU9250_RA_EXT_SENS_DATA_07     0x50
#define MPU9250_RA_EXT_SENS_DATA_08     0x51
#define MPU9250_RA_EXT_SENS_DATA_09     0x52
#define MPU9250_RA_EXT_SENS_DATA_10     0x53
#define MPU9250_RA_EXT_SENS_DATA_11     0x54
#define MPU9250_RA_EXT_SENS_DATA_12     0x55
#define MPU9250_RA_EXT_SENS_DATA_13     0x56
#define MPU9250_RA_EXT_SENS_DATA_14     0x57
#define MPU9250_RA_EXT_SENS_DATA_15     0x58
#define MPU9250_RA_EXT_SENS_DATA_16     0x59
#define MPU9250_RA_EXT_SENS_DATA_17     0x5A
#define MPU9250_RA_EXT_SENS_DATA_18     0x5B
#define MPU9250_RA_EXT_SENS_DATA_19     0x5C
#define MPU9250_RA_EXT_SENS_DATA_20     0x5D
#define MPU9250_RA_EXT_SENS_DATA_21     0x5E
#define MPU9250_RA_EXT_SENS_DATA_22     0x5F
#define MPU9250_RA_EXT_SENS_DATA_23     0x60
#define MPU9250_RA_MOT_DETECT_STATUS    0x61
#define MPU9250_RA_I2C_SLV0_DO          0x63
#define MPU9250_RA_I2C_SLV1_DO          0x64
#define MPU9250_RA_I2C_SLV2_DO          0x65
#define MPU9250_RA_I2C_SLV3_DO          0x66
#define MPU9250_RA_I2C_MST_DELAY_CTRL   0x67
#define MPU9250_RA_SIGNAL_PATH_RESET    0x68
#define MPU9250_RA_MOT_DETECT_CTRL      0x69
#define MPU9250_RA_USER_CTRL        0x6A
#define MPU9250_RA_PWR_MGMT_1       0x6B
#define MPU9250_RA_PWR_MGMT_2       0x6C
#define MPU9250_RA_BANK_SEL         0x6D
#define MPU9250_RA_MEM_START_ADDR   0x6E
#define MPU9250_RA_MEM_R_W          0x6F
#define MPU9250_RA_DMP_CFG_1        0x70
#define MPU9250_RA_DMP_CFG_2        0x71
#define MPU9250_RA_FIFO_COUNTH      0x72
#define MPU9250_RA_FIFO_COUNTL      0x73
#define MPU9250_RA_FIFO_R_W         0x74
#define MPU9250_RA_WHO_AM_I         0x75

struct MPU9250 {
    int bus;
    uint8_t address;
    double gyro_fullscale;
} ;

int  MPU9250_initialize(struct MPU9250 *dev, int bus, uint8_t address);
int  MPU9250_isConnected(struct MPU9250 *dev);
void MPU9250_terminate(struct MPU9250 *dev);

void   MPU9250_configure(struct MPU9250 *dev);
double MPU9250_getRotationX(struct MPU9250 *dev);
double MPU9250_getRotationY(struct MPU9250 *dev);
double MPU9250_getRotationZ(struct MPU9250 *dev);
float  MPU9250_getTemperature(struct MPU9250 *dev);

#ifdef __cplusplus
}
#endif

#endif /* _MPU9250_H_ */
