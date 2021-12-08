// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2015.1
// Copyright (C) 2015 Xilinx Inc. All rights reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "xnco.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XNco_CfgInitialize(XNco *InstancePtr, XNco_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

u32 XNco_Get_sine_sample_V(XNco *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNco_ReadReg(InstancePtr->Axilites_BaseAddress, XNCO_AXILITES_ADDR_SINE_SAMPLE_V_DATA);
    return Data;
}

u32 XNco_Get_sine_sample_V_vld(XNco *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNco_ReadReg(InstancePtr->Axilites_BaseAddress, XNCO_AXILITES_ADDR_SINE_SAMPLE_V_CTRL);
    return Data & 0x1;
}

void XNco_Set_step_size_V(XNco *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNco_WriteReg(InstancePtr->Axilites_BaseAddress, XNCO_AXILITES_ADDR_STEP_SIZE_V_DATA, Data);
}

u32 XNco_Get_step_size_V(XNco *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNco_ReadReg(InstancePtr->Axilites_BaseAddress, XNCO_AXILITES_ADDR_STEP_SIZE_V_DATA);
    return Data;
}

