///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

#pragma once
#include "GSprite.hpp"

namespace AE
{
	//class GSprite;
	class GBuffer
	{
		using ushort = unsigned short;
		using s_uint = unsigned int;
	public:
		GBuffer();
		~GBuffer();

		// Add a sprite to buffer 
		void Add_Sprite(const GSprite& sprite);
		void Clear_Sprite();
		std::vector<GSprite>& Get_Sprites();
		// Sort Sprite Array Based on Zbuffer 
		///TO DO Z BUFFER SHOULD CREATE
		void Sort_Sprites_Array();
		// Set pixels buffer 
		void Fill_Pixels_Symboles();
		void Fill_Pixels_Color();
		// Get pixles buffer
		short* Get_Buffer_Symboles_Array();
		short* Get_Buffer_Color_Array();
		// Correct empty pixles and get all thing to gether and send to GRendere
		void Currect_Empty_Index_Buffer();
	private:
		void Init_Buffer();
		void Clear_Buffer();

	private:
		std::vector<GSprite> m_Sprites {};
		short* m_buffer_pixles_symboles { nullptr };
		short* m_buffer_pixles_colors { nullptr };
	};
}