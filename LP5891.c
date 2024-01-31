/*
 * File: LP5891.c
 * Author: Mohamed AbdElmgeed
 * Date: 2023-10-09
 * Description: This module contains functions for
 * -Initializing led matrix registers
 * -Creating Initialization frames
 * -Creating RGB frames
 * -Reading received frames from the matrix led
 */

#include <stdint.h>
#include "LP5891.h"


int counter_1=0;
int counter_2=0;
int counter_3=0;
//extern uint32_t baseAddr;
//extern uint32_t chNum;
extern qspiDma g_qspiDma;
/**
 * @brief Initialization of Matrix LED registers.
 */
void led_init(void)
{

	uint8_t new8FC0[12*12]={0};
	for(int i = 0 ; i<sizeof(new8FC0) ; i++)new8FC0[i]=0xff;
	uint8_t new8FC1[12*12]={0};
	for(int i = 0 ; i<sizeof(new8FC1) ; i++)new8FC1[i]=0xff;
	uint8_t new8FC2[12*12]={0};
	for(int i = 0 ; i<sizeof(new8FC2) ; i++)new8FC2[i]=0xff;
	uint8_t new8FC3[12*12]={0};
	for(int i = 0 ; i<sizeof(new8FC3) ; i++)new8FC3[i]=0xff;
	uint8_t new8FC4[12*12]={0};
	for(int i = 0 ; i<sizeof(new8FC4) ; i++)new8FC4[i]=0xff;
	uint8_t new8ChipIndex[10*12]={0};
	for(int i = 0 ; i<sizeof(new8ChipIndex) ; i++)new8ChipIndex[i]=0xff;

	uint16_t FC0[]={SB,W_FC0,_FC0_2,_FC0_1,_FC0_0};
	uint16_t FC1[]={SB,W_FC1,_FC1_2,_FC1_1,_FC1_0};
	uint16_t FC2[]={SB,W_FC2,_FC2_2,_FC2_1,_FC2_0};
	uint16_t FC3[]={SB,W_FC3,_FC3_2,_FC3_1,_FC3_0};
	uint16_t FC4[]={SB,W_FC4,_FC4_2,_FC4_1,_FC4_0};

	uint16_t chipIndex[]={SB,W_CHIP_INDEX,0};


	create_pixel_frame (FC0 , new8FC0 , 5);
	create_pixel_frame (FC1 ,  new8FC1 ,5);
	create_pixel_frame (FC2 , new8FC2 ,5);
	create_pixel_frame (FC3 ,  new8FC3 ,5);
	create_pixel_frame (FC4 ,  new8FC4 ,5);
	create_pixel_frame (chipIndex ,  new8ChipIndex ,2);


//	LPSPI_DRV_MasterTransfer(LPSPICOM1, new8FC0, NULL, 12);
//	LPSPI_DRV_MasterTransfer(LPSPICOM1, new8FC1, NULL, 12);
//	LPSPI_DRV_MasterTransfer(LPSPICOM1, new8FC2, NULL, 12);
//	LPSPI_DRV_MasterTransfer(LPSPICOM1, new8FC3, NULL, 12);
//	LPSPI_DRV_MasterTransfer(LPSPICOM1, new8FC4, NULL, 12);
//	LPSPI_DRV_MasterTransfer(LPSPICOM1, new8ChipIndex, NULL, 10);


//    mcspi_loopback(new8FC0,NULL,12);
//    mcspi_loopback(new8FC1,NULL,12);
//    mcspi_loopback(new8FC2,NULL,12);
//    mcspi_loopback(new8FC3,NULL,12);
//    mcspi_loopback(new8FC4,NULL,12);
//    mcspi_loopback(new8ChipIndex,NULL,10);


//	IfxQspi_SpiMaster_exchange(&g_qspi.spiMasterChannel, new8ChipIndex, NULL_PTR, sizeof(new8ChipIndex));
//    for(int i =0 ; i<100000 ; i++){}
//    IfxQspi_SpiMaster_exchange(&g_qspi.spiMasterChannel, new8FC0, NULL_PTR, sizeof(new8FC0));
//    for(int i =0 ; i<100000 ; i++){}
//    IfxQspi_SpiMaster_exchange(&g_qspi.spiMasterChannel, new8FC1, NULL_PTR, sizeof(new8FC1));
//    for(int i =0 ; i<100000 ; i++){}
//    IfxQspi_SpiMaster_exchange(&g_qspi.spiMasterChannel, new8FC2, NULL_PTR, sizeof(new8FC2));
//    for(int i =0 ; i<100000 ; i++){}
//    IfxQspi_SpiMaster_exchange(&g_qspi.spiMasterChannel, new8FC3, NULL_PTR, sizeof(new8FC3));
//    for(int i =0 ; i<100000 ; i++){}
//    IfxQspi_SpiMaster_exchange(&g_qspi.spiMasterChannel, new8FC4, NULL_PTR, sizeof(new8FC4));
//    for(int i =0 ; i<100000 ; i++){}

}
/**
 * @brief Creating Initialization frame by adding a bit after each 16 bits , this bit is equal to the not of the 16th bit.
 *
 * @param oldData  original frame before editting.
 * @param newData8 edited frame but in array of 8 bits.
 * @param size size of the editted frame.
 * @return void.
 */
void create_pixel_frame (uint16_t* oldData , uint8_t* newData8 ,uint8_t size)
{
    uint16_t reminder = 0 ;
    uint16_t add = 0 ;
    uint16_t newData[41];

    newData[0] = oldData[0];
    int i = 1 ;
    for (int j = 1; j < size+1 ; j++)
    {

        newData[j] = reminder | add | oldData[j]>>i-1 ;
        switch (i)
        {
        case 1:
            reminder=0;
            add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 15;
            add &= 0x8000 ;
            break;
        case 2:
            reminder=(( oldData[j] | 0xfffe ) << 15)&0x8000;
            add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 14;
            add &= 0x4000 ;
            break;
        case 3:
            reminder=(( oldData[j] | 0xfffc ) << 14)&0xc000;
            add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 13;
            add &= 0x2000 ;
            break;
         case 4:
            reminder=(( oldData[j] | 0xfff8 ) << 13)&0xe000;
            add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 12;
            add &= 0x1000 ;
            break;
        case 5:
            reminder=(( oldData[j] | 0xfff0 ) << 12)&0xf000;
            add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 11;
            add &= 0x0800 ;
            break;
        case 6:
                    reminder=(( oldData[j] | 0xffe0 ) << 11)&0xf800;
                    add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 10;
                    add &= 0x0400 ;
                    break;
        case 7:
                    reminder=(( oldData[j] | 0xffc0 ) << 10)&0xfc00;
                    add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 9;
                    add &= 0x0200 ;
                    break;
        case 8:
                    reminder=(( oldData[j] | 0xff80 ) << 9)&0xfe00;
                    add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 8;
                    add &= 0x0100 ;
                    break;
        case 9:
                    reminder=(( oldData[j] | 0xff00 ) << 8)&0xff00;
                    add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 7;
                    add &= 0x0080 ;
                    break;
        case 10:
                    reminder=(( oldData[j] | 0xfe00 ) << 7)&0xff80;
                    add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 6;
                    add &= 0x0040 ;
                    break;
        case 11:
                    reminder=(( oldData[j] | 0xfc00 ) << 6)&0xffc0;
                    add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 5;
                    add &= 0x0020 ;
                    break;
        case 12:
                    reminder=(( oldData[j] | 0xf800 ) << 5)&0xffe0;
                    add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 4;
                    add &= 0x0010 ;
                    break;
        case 13:
                   reminder=(( oldData[j] | 0xf000 ) << 4)&0xfff0;
                   add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 3;
                   add &= 0x0008 ;
                   break;
        case 14:
                   reminder=(( oldData[j] | 0xe000 ) << 3)&0xfff8;
                   add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 2;
                   add &= 0x0004 ;
                   break;
        case 15:
                           reminder=(( oldData[j] | 0xc000 ) << 2)&0xfffc;
                           add = ((oldData[j] | 0xfffe ) ^ 0x0001) << 1;
                           add &= 0x0002 ;
                           break;
        case 16:
                                   reminder=(( oldData[j] | 0x8000 ) << 1)&0xfffe;
                                   add = ((oldData[j] | 0xfffe ) ^ 0x0001) ;
                                   add &= 0x0001 ;
                                   break;

        default:
            reminder =0;
            break;
        }

       if(j == size)
       {
           if(oldData[j]&1==1)newData[j] |= 0x07ff;
           else newData[j] |= 0x0fff;
       }
       i++;
       if(i==17)
          {
              i=0;
              reminder = ((oldData[j] | 0xfffe ) ^ 0x0001) & 0x1;
              add = 0;
          }
    }

    int cnt=0;
    for(int i=0 ; i<(size+1);i++)
    {

    	newData8[cnt+i]=(newData[i]>>8) & 0x00ff;
    	cnt++;
    	newData8[cnt+i]=newData[i];
    }
}
/**
 * @brief Creating the RGB frame which include the header and RGB data for the all LEDs.
 *
 * @param RGB Array of the RGB data for each led.
 * @param frame The output editted frame.
 * @return void.
 */
void create_pixel_frame_RGB (uint16_t* RGB,uint8_t* frame,uint8_t device)
{
    static int flag = 0;
	uint16_t old[41];
//	uint16_t old[41]={0};
//	for(int i=0 ; i<41 ; i++)old[i]=0x7ffe;
	uint8_t new8[84]={0};
	for(int i=0 ; i<84 ; i++)new8[i]=0xffff;
	old[0]=0xfffe;
	old[1]=0xaa30;
	counter_1=0;
	counter_2=0;
	counter_3=0;
		for (int i=0 ; i<16*48 ; i++)
		{
//		    counter_1=0;
//		    for(int j = 0 ; j<12 ; j++)
//		    {
//		        old[counter_1++ +2]=img_data[counter_3++ +j*256];
//		        old[counter_1++ +2]=img_data[counter_3++ +j*256+1];
//		        old[counter_1++ +2]=img_data[counter_3++ +j*256+2];
//		    }
		    uint16_t value = 100;
		    uint16_t value2 = 100 ;
		    uint16_t value3 = 100 ;

//		    if(i>16*10&&i<16*16)
//		    {
//		     value = 0xaaaa;
//		     value2 = 0xaaaa ;
//		     value3 = 0xaaaa;
//		    }
//		    else
//		        {
//		        value = 0;
//		        value2 = 0 ;
//		        value3 = 0 ;
//		        }
		    if(flag&&device!=12){
		    if(device<5)
		        {
		        old[(2+3*device)]=value;
		        old[(2+3*device)+1]=value2;
		        old[(2+3*device)+2]=value3;
		        }
		    if(device>3&&device<11)
		        {
		        old[(2+3*device)+1]=value;
		        old[(2+3*device)+2]=value2;
		        old[(2+3*device)+3]=value3;
		        }
		   if(device==11 || device ==10)
		       {
		           old[(2+3*device)+2]=value;
		           old[(2+3*device)+3]=value2;
		           old[(2+3*device)+4]=value3;
		       }
		    }
		    else
		    {
//		        for(int i=0 ; i<41 ; i++)old[i]=0;
		    }

		    flag++;
		    create_pixel_frame(old,new8,40);
			for(int j=0 ; j<83 ; j++)
			{
				frame[counter_2]=new8[j];
				counter_2++;
			}
		}

}
void create_pixel_frame_G (uint16_t* data,uint8_t* frame)
{

//#pragma options align=packed
__attribute__((packed))


    struct frame_struct{
                        uint16_t startbytes; //Frame start 0xFFFE
                        uint16_t headbytes; //Head bytes for sending data is 0xAA30

                        uint8_t cb1:1 ;uint16_t db1 ;   //cb is sheck bit and db is data bytes
                        uint8_t cb2:1 ;uint16_t db2 ;
                        uint8_t cb3:1 ;uint16_t db3 ;
                        uint8_t cb4:1 ;uint16_t db4 ;
                        uint8_t cb5:1 ;uint16_t db5 ;
                        uint8_t cb6:1 ;uint16_t db6 ;
                        uint8_t cb7:1 ;uint16_t db7 ;
                        uint8_t cb8:1 ;uint16_t db8 ;
                        uint8_t cb9:1 ;uint16_t db9 ;
                        uint8_t cb10:1 ;uint16_t db10 ;
                        uint8_t cb11:1 ;uint16_t db11 ;
                        uint8_t cb12:1 ;uint16_t db12 ;
                        uint8_t cb13:1 ;uint16_t db13 ;
                        uint8_t cb14:1 ;uint16_t db14 ;
                        uint8_t cb15:1 ;uint16_t db15 ;
                        uint8_t cb16:1 ;uint16_t db16 ;
                        uint8_t cb17:1 ;uint16_t db17 ;
                        uint8_t cb18:1 ;uint16_t db18 ;
                        uint8_t cb19:1 ;uint16_t db19 ;
                        uint8_t cb20:1 ;uint16_t db20 ;
                        uint8_t cb21:1 ;uint16_t db21 ;
                        uint8_t cb22:1 ;uint16_t db22 ;
                        uint8_t cb23:1 ;uint16_t db23 ;
                        uint8_t cb24:1 ;uint16_t db24 ;
                        uint8_t cb25:1 ;uint16_t db25 ;
                        uint8_t cb26:1 ;uint16_t db26 ;
                        uint8_t cb27:1 ;uint16_t db27 ;
                        uint8_t cb28:1 ;uint16_t db28 ;
                        uint8_t cb29:1 ;uint16_t db29 ;
                        uint8_t cb30:1 ;uint16_t db30 ;
                        uint8_t cb31:1 ;uint16_t db31 ;
                        uint8_t cb32:1 ;uint16_t db32 ;
                        uint8_t cb33:1 ;uint16_t db33 ;
                        uint8_t cb34:1 ;uint16_t db34 ;
                        uint8_t cb35:1 ;uint16_t db35 ;
                        uint8_t cb36:1 ;uint16_t db36 ;
                        uint16_t endbytes;
                };
//#pragma options align=reset

    union frame{
            uint8_t frame_arr[84];
            struct frame_struct frame_struct;
    };
    union frame frame_to_send;
    for (int i=0 ; i<84 ; i++)
        {
            frame_to_send.frame_arr[i]=0xFF;
        }
    frame_to_send.frame_struct.startbytes=0xFFFE;
    frame_to_send.frame_struct.headbytes=0xAA30;
    frame_to_send.frame_struct.cb1=1;frame_to_send.frame_struct.db1=data[0];
    frame_to_send.frame_struct.cb2=(data[0]<<15)&0x8000?0:1;frame_to_send.frame_struct.db2=data[1];
    frame_to_send.frame_struct.cb3=(data[1]<<15)&0x8000?0:1;frame_to_send.frame_struct.db3=data[2];
    frame_to_send.frame_struct.cb4=(data[2]<<15)&0x8000?0:1;frame_to_send.frame_struct.db4=data[3];
    frame_to_send.frame_struct.cb5=(data[3]<<15)&0x8000?0:1;frame_to_send.frame_struct.db5=data[4];
    frame_to_send.frame_struct.cb6=(data[4]<<15)&0x8000?0:1;frame_to_send.frame_struct.db6=data[5];
    frame_to_send.frame_struct.cb7=(data[5]<<15)&0x8000?0:1;frame_to_send.frame_struct.db7=data[6];
    frame_to_send.frame_struct.cb8=(data[6]<<15)&0x8000?0:1;frame_to_send.frame_struct.db8=data[7];
    frame_to_send.frame_struct.cb9=(data[7]<<15)&0x8000?0:1;frame_to_send.frame_struct.db9=data[8];
    frame_to_send.frame_struct.cb10=(data[8]<<15)&0x8000?0:1;frame_to_send.frame_struct.db10=data[9];
    frame_to_send.frame_struct.cb11=(data[9]<<15)&0x8000?0:1;frame_to_send.frame_struct.db11=data[10];
    frame_to_send.frame_struct.cb12=(data[10]<<15)&0x8000?0:1;frame_to_send.frame_struct.db12=data[11];
    frame_to_send.frame_struct.cb13=(data[11]<<15)&0x8000?0:1;frame_to_send.frame_struct.db13=data[12];
    frame_to_send.frame_struct.cb14=(data[12]<<15)&0x8000?0:1;frame_to_send.frame_struct.db14=data[13];
    frame_to_send.frame_struct.cb15=(data[13]<<15)&0x8000?0:1;frame_to_send.frame_struct.db15=data[14];
    frame_to_send.frame_struct.cb16=(data[14]<<15)&0x8000?0:1;frame_to_send.frame_struct.db16=data[15];
    frame_to_send.frame_struct.cb17=(data[15]<<15)&0x8000?0:1;frame_to_send.frame_struct.db17=data[16];
    frame_to_send.frame_struct.cb18=(data[16]<<15)&0x8000?0:1;frame_to_send.frame_struct.db18=data[17];
    frame_to_send.frame_struct.cb19=(data[17]<<15)&0x8000?0:1;frame_to_send.frame_struct.db19=data[18];
    frame_to_send.frame_struct.cb20=(data[18]<<15)&0x8000?0:1;frame_to_send.frame_struct.db20=data[19];
    frame_to_send.frame_struct.cb21=(data[19]<<15)&0x8000?0:1;frame_to_send.frame_struct.db21=data[20];
    frame_to_send.frame_struct.cb22=(data[20]<<15)&0x8000?0:1;frame_to_send.frame_struct.db22=data[21];
    frame_to_send.frame_struct.cb23=(data[21]<<15)&0x8000?0:1;frame_to_send.frame_struct.db23=data[22];
    frame_to_send.frame_struct.cb24=(data[22]<<15)&0x8000?0:1;frame_to_send.frame_struct.db24=data[23];
    frame_to_send.frame_struct.cb25=(data[23]<<15)&0x8000?0:1;frame_to_send.frame_struct.db25=data[24];
    frame_to_send.frame_struct.cb26=(data[24]<<15)&0x8000?0:1;frame_to_send.frame_struct.db26=data[25];
    frame_to_send.frame_struct.cb27=(data[25]<<15)&0x8000?0:1;frame_to_send.frame_struct.db27=data[26];
    frame_to_send.frame_struct.cb28=(data[26]<<15)&0x8000?0:1;frame_to_send.frame_struct.db28=data[27];
    frame_to_send.frame_struct.cb29=(data[27]<<15)&0x8000?0:1;frame_to_send.frame_struct.db29=data[28];
    frame_to_send.frame_struct.cb30=(data[28]<<15)&0x8000?0:1;frame_to_send.frame_struct.db30=data[29];
    frame_to_send.frame_struct.cb31=(data[29]<<15)&0x8000?0:1;frame_to_send.frame_struct.db31=data[30];
    frame_to_send.frame_struct.cb32=(data[30]<<15)&0x8000?0:1;frame_to_send.frame_struct.db32=data[31];
    frame_to_send.frame_struct.cb33=(data[31]<<15)&0x8000?0:1;frame_to_send.frame_struct.db33=data[32];
    frame_to_send.frame_struct.cb34=(data[32]<<15)&0x8000?0:1;frame_to_send.frame_struct.db34=data[33];
    frame_to_send.frame_struct.cb35=(data[33]<<15)&0x8000?0:1;frame_to_send.frame_struct.db35=data[34];
    frame_to_send.frame_struct.cb36=(data[34]<<15)&0x8000?0:1;frame_to_send.frame_struct.db36=data[35];
    frame_to_send.frame_struct.endbytes=0xFFFF;

    for (int i=0 ; i<84 ; i++)
    {
        frame[i]=frame_to_send.frame_arr[i];
    }

}
/**
 * @brief Sending sync frame to the Matrix LEDs which is mandatory to be sent frequently to keep it up.
 */
void sync(void)
{
	uint8_t vsync[]={
	        0xfe,0xaa,0xf0,0xff,0xff
	};
//    mcspi_loopback(vsync,NULL,sizeof(vsync));
//    IfxQspi_SpiMaster_exchange(&g_qspi.spiMasterChannel, vsync, NULL_PTR, sizeof(vsync));
}
/**
 * @brief Reading the received data from Matrix LEDs.
 *
 * @param command  The register reading code mentioned in LP5891 datasheet.
 * @param rec Array to store the received data.
 * @return void.
 */
void read(uint8_t command,uint8_t * rec )
{
    uint16_t comd;
    uint16_t Data_1,Data_2,Data_3;
    uint8_t command_frame[]={0xfe,0xaa,command,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
//    mcspi_loopback(command_frame,rec,sizeof(command_frame));
//    IfxQspi_SpiMaster_exchange(&g_qspi.spiMasterChannel, command_frame, rec, sizeof(command_frame));
    for (int i=0 ; i<sizeof(command_frame) ; i++)
    {
        if(rec[i]==0xfe)
        {
            comd=rec[i];
            comd=comd<<8;
            comd |= rec[i+1]&0xff;
            Data_1=rec[i+2];
            Data_1=Data_1<<8;
            Data_1|=rec[i+3]&0xff;
            Data_2=rec[i+4];
            Data_2=Data_2<<8;
            Data_2|=rec[i+5]&0xff;
            Data_3=rec[i+6];
            Data_3=Data_3<<8;
            Data_3|=rec[i+7]&0xff;
            break;
        }
        if(rec[i]==0xea)
               {
                   comd = rec[i];
                   comd = comd<<12;
                   comd |= (rec[i+1]&0xff)<<4;
                   comd |= (rec[i+2]>>4);
                   Data_1=rec[i+2];
                   Data_1=Data_1<<8;
                   Data_1|=rec[i+3]&0xff;
                   Data_2=rec[i+4];
                   Data_2=Data_2<<8;
                   Data_2|=rec[i+5]&0xff;
                   Data_3=rec[i+6];
                   Data_3=Data_3<<8;
                   Data_3|=rec[i+7]&0xff;
                   break;
               }
    }

}
