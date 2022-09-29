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
		uint16_t Get_RX_Buffer_Pointer_Pos(void){return RX.Pointer_Pos;}
		uint16_t Get_TX_Buffer_Pointer_Pos(void){return TX.Pointer_Pos;}
		void Set_RX_Buffer_Pointer_Pos(uint16_t pt){ if(pt<RX.Buffer_size) RX.Pointer_Pos=pt;}
		void Set_TX_Buffer_Pointer_Pos(uint16_t pt){ if(pt<TX.Buffer_size) TX.Pointer_Pos=pt;}
		//========= TX BUFFER =================
		bool Write_TX_Byte_CMODE	(uint8_t Data);
		void Write_TX_Buffer(uint8_t *Buffer,uint16_t Size);
		void Write_TX_Buffer(uint8_t *Buffer,uint16_t Size,uint16_t Offset);
		uint8_t* Read_TX_Buffer	(uint16_t Index);
		uint8_t  Read_TX_Byte_CMODE(void);
		//========= TX BUFFER =================
		
		//========= RX BUFFER =================
		bool 		 Write_RX_Byte_CMODE(uint8_t Data);
		void		 Write_RX_Buffer(uint8_t *Buffer,uint16_t Size);
		void 		 Write_RX_Buffer(uint8_t *Buffer,uint16_t Size,uint16_t Offset);
		uint8_t* Read_RX_Buffer(uint16_t Index);
		uint8_t  Read_RX_Byte_CMODE(void);
		//========= RX BUFFER =================
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

//============================ Constructore ================================//
template<uint16_t rx ,uint16_t tx> COM_CLASS<rx,tx>::COM_CLASS(void)
{
	strcpy(NAME,"BLANK");
}
template<uint16_t rx ,uint16_t tx> COM_CLASS<rx,tx>::COM_CLASS(char * Name)
{
	strcpy(NAME,Name);
}
//============================ Constructore ================================//

//============================ TX BUFFER ===================================//
template <uint16_t rx ,uint16_t tx> bool COM_CLASS<rx,tx>::Write_TX_Byte_CMODE(uint8_t Data)
{
	if(TX.Pointer_Pos < TX.Buffer_size)
	{
		TX.Buffer[TX.Pointer_Pos]=Data;
		TX.Pointer_Pos++;
		return true;
	}
	return false;
}

template <uint16_t rx ,uint16_t tx> void COM_CLASS<rx,tx>::Write_TX_Buffer(uint8_t *Buffer,uint16_t Size)
{
	if(Get_TX_Buffer_Size() > Size)
	{
		memcpy(TX.Buffer,Buffer,Size);
		TX.Pointer_Pos=Size;
	}
}

template <uint16_t rx ,uint16_t tx> void COM_CLASS<rx,tx>::Write_TX_Buffer(uint8_t *Buffer,uint16_t Size,uint16_t Offset)
{
	if(Get_TX_Buffer_Size() > Offset+Size)
	{
		memcpy(&TX.Buffer[Offset],Buffer,Size);
		TX.Pointer_Pos=Offset+Size;
	}
}
template <uint16_t rx ,uint16_t tx> uint8_t* COM_CLASS<rx,tx>::Read_TX_Buffer(uint16_t Index)
{
	if(Get_TX_Buffer_Size()>Index)
	{
		TX.Pointer_Pos=Index;
		return &TX.Buffer[Index];
	}
	return NULL;
}

template <uint16_t rx ,uint16_t tx> uint8_t COM_CLASS<rx,tx>::Read_TX_Byte_CMODE(void)
{
	if(Get_TX_Buffer_Size()>Get_TX_Buffer_Pointer_Pos())
	{
		TX.Pointer_Pos++;
		return TX.Buffer[Get_TX_Buffer_Pointer_Pos()];
	}
}
//============================ TX BUFFER ===================================//

//============================ RX BUFFER ===================================//
 		
template <uint16_t rx ,uint16_t tx> bool COM_CLASS<rx,tx>::Write_RX_Byte_CMODE(uint8_t Data)
{
	if(RX.Pointer_Pos < RX.Buffer_size)
	{
		RX.Buffer[RX.Pointer_Pos]=Data;
		RX.Pointer_Pos++;
		return true;
	}
	return false;
}

template <uint16_t rx ,uint16_t tx> void COM_CLASS<rx,tx>::Write_RX_Buffer(uint8_t *Buffer,uint16_t Size)
{
	if(Get_RX_Buffer_Size() > Size)
	{
		memcpy(RX.Buffer,Buffer,Size);
		RX.Pointer_Pos=Size;
	}
}

template <uint16_t rx ,uint16_t tx> void COM_CLASS<rx,tx>::Write_RX_Buffer(uint8_t *Buffer,uint16_t Size,uint16_t Offset)
{
	if(Get_RX_Buffer_Size() > Offset+Size)
	{
		memcpy(&RX.Buffer[Offset],Buffer,Size);
		RX.Pointer_Pos=Offset+Size;
	}
}

template <uint16_t rx ,uint16_t tx> uint8_t* COM_CLASS<rx,tx>::Read_RX_Buffer(uint16_t Index)
{
	if(Get_RX_Buffer_Size()>Index)
	{
		RX.Pointer_Pos=Index;
		return &RX.Buffer[Index];
	}
	return NULL;
}
//============================ RX BUFFER ===================================//
#endif
