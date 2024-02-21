#pragma once
#include<string>
#include"Thing.hpp"

/*!
	\brief Класс для создания объекта "Игрок"
*/
class Player {
public:
	Player():name_("empty"),grouping_("empty"),health_(0),points_(0),reputation_(0),gender_(false), max_weight_(0), weight_(0){}
	Player(std::string name, std::string grouping, int reputation, int max_weight, bool gender) {
		this->gender_ = gender;
		this->grouping_ = grouping;
		this->name_ = name;
		this->points_ = 0;
		this->reputation_ = reputation;
		this->health_ = 100;
		this->max_weight_ = max_weight;
	}
	/// \ Гэттэр для получения массы надетого на игрока снаряжения
	float Weight()const{
		
	}
	/// \ Сэттэр для заполнения слота "Оружие" (Weapon)
	
private:
	std::string name_; // Имя игрока
	std::string grouping_; // Группировка, к которой принадлежит игрок
	int health_; // Здоровье
	int points_; // Ранг (очки) игрока
	int reputation_; // Репутация игрока
	int max_weight_; // Максимально переносимый игроком вес
	int weight_; // Масса снаряжения игрока
	bool gender_; // Пол (false - мужской, true - женский)
	Weapon* weapon_; // Указатель на оружие, которое находится в слоте "Оружие" (имитация слота "Оружие")
	Head* head_; // Указатель на головной убор, который находится в слоте "Головной убор" (имитация слота "Головной убор")
	Armor* armor_; // Указатель на броню, которая находится в слоте "Броня" (имитация слота "Броня")
	Shoes* shoes_; // Указатель на обоувь, которая находится в слоте "Обувь" (имитация слота "Обувь")	
};