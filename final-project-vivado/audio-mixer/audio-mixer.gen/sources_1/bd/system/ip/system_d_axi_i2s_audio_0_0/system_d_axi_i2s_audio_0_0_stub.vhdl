-- Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2021.1 (lin64) Build 3247384 Thu Jun 10 19:36:07 MDT 2021
-- Date        : Sun Dec 12 18:22:27 2021
-- Host        : ece36 running 64-bit Ubuntu 20.04.2 LTS
-- Command     : write_vhdl -force -mode synth_stub
--               /home/user/final-project/final-project-vivado/audio-mixer/audio-mixer.gen/sources_1/bd/system/ip/system_d_axi_i2s_audio_0_0/system_d_axi_i2s_audio_0_0_stub.vhdl
-- Design      : system_d_axi_i2s_audio_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z010clg400-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity system_d_axi_i2s_audio_0_0 is
  Port ( 
    BCLK_O : out STD_LOGIC;
    LRCLK_O : out STD_LOGIC;
    MCLK_O : out STD_LOGIC;
    SDATA_I : in STD_LOGIC;
    SDATA_O : out STD_LOGIC;
    CLK_100MHZ_I : in STD_LOGIC;
    S_AXIS_MM2S_ACLK : in STD_LOGIC;
    S_AXIS_MM2S_ARESETN : in STD_LOGIC;
    S_AXIS_MM2S_TREADY : out STD_LOGIC;
    S_AXIS_MM2S_TDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    S_AXIS_MM2S_TKEEP : in STD_LOGIC_VECTOR ( 3 downto 0 );
    S_AXIS_MM2S_TLAST : in STD_LOGIC;
    S_AXIS_MM2S_TVALID : in STD_LOGIC;
    M_AXIS_S2MM_ACLK : in STD_LOGIC;
    M_AXIS_S2MM_ARESETN : in STD_LOGIC;
    M_AXIS_S2MM_TVALID : out STD_LOGIC;
    M_AXIS_S2MM_TDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    M_AXIS_S2MM_TKEEP : out STD_LOGIC_VECTOR ( 3 downto 0 );
    M_AXIS_S2MM_TLAST : out STD_LOGIC;
    M_AXIS_S2MM_TREADY : in STD_LOGIC;
    AXI_L_aclk : in STD_LOGIC;
    AXI_L_aresetn : in STD_LOGIC;
    AXI_L_awaddr : in STD_LOGIC_VECTOR ( 5 downto 0 );
    AXI_L_awprot : in STD_LOGIC_VECTOR ( 2 downto 0 );
    AXI_L_awvalid : in STD_LOGIC;
    AXI_L_awready : out STD_LOGIC;
    AXI_L_wdata : in STD_LOGIC_VECTOR ( 31 downto 0 );
    AXI_L_wstrb : in STD_LOGIC_VECTOR ( 3 downto 0 );
    AXI_L_wvalid : in STD_LOGIC;
    AXI_L_wready : out STD_LOGIC;
    AXI_L_bresp : out STD_LOGIC_VECTOR ( 1 downto 0 );
    AXI_L_bvalid : out STD_LOGIC;
    AXI_L_bready : in STD_LOGIC;
    AXI_L_araddr : in STD_LOGIC_VECTOR ( 5 downto 0 );
    AXI_L_arprot : in STD_LOGIC_VECTOR ( 2 downto 0 );
    AXI_L_arvalid : in STD_LOGIC;
    AXI_L_arready : out STD_LOGIC;
    AXI_L_rdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    AXI_L_rresp : out STD_LOGIC_VECTOR ( 1 downto 0 );
    AXI_L_rvalid : out STD_LOGIC;
    AXI_L_rready : in STD_LOGIC
  );

end system_d_axi_i2s_audio_0_0;

architecture stub of system_d_axi_i2s_audio_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "BCLK_O,LRCLK_O,MCLK_O,SDATA_I,SDATA_O,CLK_100MHZ_I,S_AXIS_MM2S_ACLK,S_AXIS_MM2S_ARESETN,S_AXIS_MM2S_TREADY,S_AXIS_MM2S_TDATA[31:0],S_AXIS_MM2S_TKEEP[3:0],S_AXIS_MM2S_TLAST,S_AXIS_MM2S_TVALID,M_AXIS_S2MM_ACLK,M_AXIS_S2MM_ARESETN,M_AXIS_S2MM_TVALID,M_AXIS_S2MM_TDATA[31:0],M_AXIS_S2MM_TKEEP[3:0],M_AXIS_S2MM_TLAST,M_AXIS_S2MM_TREADY,AXI_L_aclk,AXI_L_aresetn,AXI_L_awaddr[5:0],AXI_L_awprot[2:0],AXI_L_awvalid,AXI_L_awready,AXI_L_wdata[31:0],AXI_L_wstrb[3:0],AXI_L_wvalid,AXI_L_wready,AXI_L_bresp[1:0],AXI_L_bvalid,AXI_L_bready,AXI_L_araddr[5:0],AXI_L_arprot[2:0],AXI_L_arvalid,AXI_L_arready,AXI_L_rdata[31:0],AXI_L_rresp[1:0],AXI_L_rvalid,AXI_L_rready";
attribute x_core_info : string;
attribute x_core_info of stub : architecture is "d_axi_i2s_audio_v2_0,Vivado 2021.1";
begin
end;
