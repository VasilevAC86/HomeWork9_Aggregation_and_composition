#pragma once
#include<string>

/*!
	\brief Абстрактный класс для создания объекта "Игровой предмет"
*/
class Thing {
public:
	Thing() :name_("empty"), type_("empty"), weight_(0), price_(0) {} // Конструктор по умолчанию 
	Thing(std::string name, std::string type, double weight, int price) {
		this->name_ = name;		
		this->weight_ = weight;
		this->price_ = price;
		this->type_ = type;		
	}
	/// \brief Гэттэр для возвращения имени предмета
	std::string Name()const { return name_; }	
	/// \brief Гэттэр для возвращения веса игрового предмета
	double Weight()const { return weight_; }
	/// \brief Гэттэр для возвращения цены игрового предмета
	int Price()const { return price_; }	
private:
	std::string name_; // Название предмета	
	std::string type_; // Тип предмета
	int price_; // Цена предмета
	double weight_; // Вес предмета		
};

/*!
	\brief Класс для создания объекта типа "Оружие"
	\details Класс является наследником базового абстрактного класса "Предмет" (Thing).
	По сравнению с базовым классом добавлены специализации - поля "урон" (damage_) и ёмкость магазина (capatity).		
*/
class Weapon :public Thing {
public:
	Weapon():damage_(0),capacity_(0) {} // Конструктор по умолчанию 
	Weapon(std::string name, double damage, double weight, int capacity, int price) :Thing(name, "weapon", weight, price) {
		this->damage_ = damage;
		this->capacity_ = capacity;		
	}
	~Weapon() { }	
	/// Перегрузка оператора << для вывода в консоль объекта типа Weapon
	friend std::ostream& operator<<(std::ostream& out, const Weapon& obj) {
		return(out << "\033[92m" << obj.Name() << "\033[0m, weight \033[92m" << obj.Weight() << "\033[0m kg, damage is \033[92m" << obj.damage_ << \
			"\033[0m, clip capacity is \033[92m" << obj.capacity_ << "\033[0m, price is \033[95m" << obj.Price() << "\033[0m rubles");
	}
	double Damage()const { return damage_; }
	int Capacity()const { return capacity_; }
private:	
	double damage_; // Наносимый здоровью урон		
	int capacity_; // Ёмкость магазина		
};

/*!
	\brief Класс для создания объекта типа "Головной убор"
	\details Класс является наследником базового абстрактного класса "Предмет" (Thing).
	По сравнению с базовым классом добавлена специализация - поле "сопротивление урону" (reistance_damage_).	
*/
class Headdress :public Thing {
public:
	Headdress() :resistance_damage_(0) {}
	Headdress(std::string name, double resistance, double weight, int price) :Thing(name, "headdress", weight, price) { this->resistance_damage_ = resistance; }
	~Headdress() { };	
	/// Перегрузка оператора << вывода в консоль объекта типа Headdress
	friend std::ostream& operator<<(std::ostream& out, const Headdress& obj) {
		return(out << "\033[92m" << obj.Name() << "\033[0m, weight \033[92m" << obj.Weight() << "\033[0m kg, resistance damage is \033[92m" \
			<< obj.resistance_damage_ << "\033[0m, price is \033[95m" << obj.Price() << "\033[0m rubles");
	}
	double Resistance()const { return resistance_damage_; }
private:	
	double resistance_damage_; // Сопротивление урону	
};

/*!
	\brief Класс для создания объекта типа "Броня"
	\details Класс является наследником базового абстрактного класса "Предмет" (Thing).
	По сравнению с базовым классом добавлены специализации - поля "сопротивление урону" (reistance_damage_) и увеличение грузоподъёмности (weight_gain_).	
*/
class Armor :public Thing {
public:
	Armor():resistance_damage_(0),weight_gain_(0){}
	Armor(std::string name, double resistance, double weight, int weight_gain, int price) :Thing(name, "armor", weight, price) {
		this->resistance_damage_ = resistance;
		this->weight_gain_ = weight_gain;
	}
	~Armor() { }	
	/// Перегрузка оператора << вывода в консоль объекта типа Armor
	friend std::ostream& operator<<(std::ostream& out, const Armor& obj) {
		return(out << "\033[92m" << obj.Name() << "\033[0m, weight \033[92m" << obj.Weight() << "\033[0m kg, resistance damage is \033[92m" \
			<< obj.resistance_damage_ << "\033[0m, carryable weight increased by \033[92m" << obj.weight_gain_ << "\033[0m kg, price is \033[95m" \
			<< obj.Price() << "\033[0m rubles");
	}
	double Resistance()const { return resistance_damage_; }
	int Weight_gain()const { return weight_gain_; }
private:	
	double resistance_damage_; // Сопротивление урону
	int weight_gain_; // Дополнительная грузоподъёмность	
};