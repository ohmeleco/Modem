#ifndef	__COM_CLASS_H
#define __COM_CLASS_H
//========================= include File
#include "MyHeader.h"

template <uint16_t RX_Buffer_size,uint16_t TX_Buffer_Size>
class COM_CLASS{
	public://=====Private Section
		COM_CLASS();
		COM_CLASS(char* Name);
		void  Write_COM_Name(char *Name){strcpy(NAME,Name);}
		char* Read_COM_Name(void) {return NAME;}
		uint16_t Get_RX_Buffer_Size(void){return RX.Buffer_size;}
		uint16_t Get_TX_Buffer_Size(void){return TX.Buffer_size;}
		//========= TX BUFFER =================
		bool Write_TX_Byte_CMODE	(uint8_t Data);
//		void Write_TX_Buffer(uint8_t *Buffer,uint16_t Size);
//		void Write_TX_Buffer(uint8_t *Buffer,uint16_t Size,uint16_t Offset);
//		uint8_t* Read_TX_Buffer	(uint16_t Index);
//		uint8_t  Read_TX_Byte_CMODE(void);
		//========= TX BUFFER =================
		
//		uint8_t* Read_RX_Buffer(uint16_t Index);
//		uint8_t  Read_RX_Byte_CMODE(void);
//		void 		 Write_RX_Byte_CMODE(uint8_t Data);
//		void		 Write_RX_Buffer(uint8_t *Buffer,uint16_t Size);
//		void 		 Write_RX_Buffer(uint8_t *Buffer,uint16_t Size,uint16_t Offset);
	private://=====Private Section
	struct{
	uint8_t Buffer[RX_Buffer_size];
	const uint16_t Buffer_size=RX_Buffer_size;
	uint16_t Pointer_Pos;
	const uint8_t  *buffer_pt=Buffer;
	}RX;
	struct{
		uint8_t Buffer[TX_Buffer_Size];
		const uint16_t Buffer_size=TX_Buffer_Size;
		uint16_t Pointer_Pos;
		const uint8_t  *buffer_pt=Buffer;
	}TX;
	char NAME[16];
};

template<uint16_t rx ,uint16_t tx> COM_CLASS<rx,tx>::COM_CLASS(void)
{
	strcpy(NAME,"BLANK");
}
template<uint16_t rx ,uint16_t tx> COM_CLASS<rx,tx>::COM_CLASS(char * Name)
{
	strcpy(NAME,Name);
}
#endif
