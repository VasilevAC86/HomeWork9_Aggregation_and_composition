#pragma once
#include<string>

/*!
	\brief Абстрактный класс для создания объекта "Игровой предмет"
*/
class Thing {
public:
	Thing() :name_("empty"), type_("empty"), weight_(0){}
	Thing(std::string name, std::string type, float weight) {
		this->name_ = name;
		this->type_ = type;
		this->weight_ = weight;
	}
	/// \brief Гэттэр для возвращения веса игрового предмета
	float Weight()const { return weight_; }
private:
	std::string name_; // Название предмета
	std::string type_; // Категория предмета (квестовый, экипировка, оружие, еда, аптечка)
	float weight_; // Вес предмета
};

/*!
	\brief Класс для создания объекта типа "Оружие"
	\details Класс является наследником базового абстрактного класса "Предмет" (Thing).
	По сравнению с базовым классом добавлены специализации - поля "урон" (damage_) и ёмкость магазина (capatity).		
*/
class Weapon :Thing {
public:
	Weapon(std::string name, std::string type, float damage, float weight, int capacity) :Thing(name, type, weight) {
		this->damage_ = damage;
		this->capacity_ = capacity;
	}
private:
	std::string slot_ = "weapon slot";
	float damage_; // Наносимый здоровью урон		
	int capacity_; // Ёмкость магазина	
};

/*!
	\brief Класс для создания объекта типа "Головной убор"
	\details Класс является наследником базового абстрактного класса "Предмет" (Thing).
	По сравнению с базовым классом добавлена специализация - поле "сопротивление урону" (reistance_damage_).	
*/
class Head : Thing {
public:
	Head(std::string name, std::string type, float resistance, float weight) :Thing(name, type, weight) {
		this->resistance_damage_ = resistance;
	}
private:
	std::string slot_ = "head protection";
	float resistance_damage_; // Сопротивление урону
};

/*!
	\brief Класс для создания объекта типа "Броня"
	\details Класс является наследником базового абстрактного класса "Предмет" (Thing).
	По сравнению с базовым классом добавлены специализации - поля "сопротивление урону" (reistance_damage_) и увеличение грузоподъёмности (weight_gain_).	
*/
class Armor : Thing {
public:
	Armor(std::string name, std::string type, float resistance, float weight, int weight_gain) :Thing(name, type, weight) {
		this->resistance_damage_ = resistance;
		this->weight_gain_ = weight_gain;
	}
private:
	std::string slot_ = "armor";
	float resistance_damage_; // Сопротивление урону
	int weight_gain_; // Дополнительная грузоподъёмность
};

/*!
	\brief Класс для создания объекта типа "Обувь"
	\details Класс является наследником базового абстрактного класса "Предмет" (Thing).
	По сравнению с базовым классом добавлена специализация - поле "сопротивление урону" (reistance_damage_).	
*/
class Shoes :Thing {
public:
	Shoes(std::string name, std::string type, float resistance, float weight) :Thing(name, type, weight) {
		this->resistance_damage_ = resistance;
	}
private:
	std::string slot = "shoes";
	float resistance_damage_; // Сопротивление урону	
};