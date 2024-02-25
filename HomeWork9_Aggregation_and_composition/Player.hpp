#pragma once
#include<string>
#include"Thing.hpp"

/*!
	\brief Класс для создания объекта "Игрок"
*/
class Player {
public:
	Player():name_("empty"),grouping_("empty"),health_(0),points_(0),reputation_(0),gender_(false), max_weight_(0), weight_(0), money_(1000) {}
	Player(std::string name, std::string grouping, int reputation, int max_weight, bool gender) {
		this->gender_ = gender;
		this->grouping_ = grouping;
		this->name_ = name;
		this->points_ = 0;
		this->reputation_ = reputation;
		this->health_ = 100;
		this->max_weight_ = max_weight;
		this->money_ = 1000;
	}
	~Player() {}
	/// \brief Метод, дающий игроку в руки оружие (Заполнение слота "Оружие")
	void SetWeapon(std::string name_weapon, double weight, double damage, int capasity) {
		hands.SetWeapon(name_weapon,weight,damage,capasity);
	}
	/// \brief Метод, удаляющий оружие из рук игрока (Слот "Руки игрока" заполнятеся просто руками игрока)
	void PopWeapon() {
		hands.PopWeapon();
	}
	/// \brief Метод, одевающий на игрока бороню (Заполнение слота "Броня")
	void SetArmor(std::string name, double resistent, double weigth, int weight_gain) {
		body.SetArmor(name, resistent, weigth, weight_gain);
	}
	/// \brief Метод, удаляющий с игрока бороню (Слот "Броня" заполняется просто телом игрока)
	void PopArmor() {
		body.PopArmor();
	}
	/// \brief Метод, одевающий на голову игрока головной убор (Заполнение слота "Головной убор")
	void SetHeaddress(std::string name, double weight, double resistance) {
		head.SetHeaddress(name, weight,resistance);
	}
	/// \brief Метод, удаляющий с игрока головной убор (Слот "Головной убор" заполняется просто головой игрока)
	void PopHeaddress() {
		head.PopHeaddress();
	}
	/// \brief Гэттэр/сэттэр кол-ва денег у игрока
	int Money()const { return money_; }
	void Money(int price) {
		money_ -= price;
	}
	/// \briefc Гэттэр для получения названия оружия
	std::string NameWeapon()const { return hands.Name(); }
	/// \briefc Гэттэр для получения названия головного убора
	std::string NameHead()const { return head.Name(); }
	/// \briefc Гэттэр для получения названия брони
	std::string NameArmor()const { return body.Name(); }
	/// \briefc Гэттэр для получения массы надетого на игрока снаряжения
	double Weight()const { return(hands.Weight() + head.Weight() + body.Weight()); }
	/// \brief Гэттэр сопротивления урону		
	double Resistance()const { return (head.Resistance() + body.Resistance()); }
	/// \brief Гэттэр переносимого веса
	int WeightGain()const { return (max_weight_ + body.WeightGain()); }
	/// \brief Гэттэр имени игрока
	std::string Name()const { return name_; }
	/// \brief Гэттэр группировки игрока
	std::string Group()const { return grouping_; }
private:
	std::string name_; // Имя игрока
	std::string grouping_; // Группировка, к которой принадлежит игрок
	int health_; // Здоровье
	int points_; // Ранг (очки) игрока
	int reputation_; // Репутация игрока
	int max_weight_; // Максимально переносимый игроком вес
	int weight_; // Масса снаряжения игрока
	bool gender_; // Пол (false - мужской, true - женский)
	int money_; // Кол-во денег у игрока
	
	/*!
		\brief Класс для создания объекта "Руки игрока"
		\details Объект класса добавляется на правах композиции по отношению к классу Player.
		Объект класса реализует слот "Руки игрока"
	*/
	class Hands {
	public:
		Hands() :name_("hands"), weight_(0), damage_(1), capacity_(35000){} // Конструктор по умолчанию (в слоте "Руки игрока" просто руки игрока)				
		~Hands() {}
		/// \brief Сэттэр параметров объекта "Руки игрока" (Руки игрока приобретают св-ва оружия, параметры которого пареданы в сэттэр)
		void SetWeapon(std::string name, double weight, double damage, int capasity) {
			this->capacity_ = capasity;
			this->damage_ = damage;
			this->name_ = name;
			this->weight_ = weight;
		}
		/// \brief Метод удаления оружия из слота "Руки игрока" (Руки игрока становяться просто руками игрока)
		void PopWeapon() {
			this->capacity_ = 35000;
			this->damage_ = 1;
			this->name_ = "hands";
			this->weight_ = 0;
		}
		/// \brief Гэттэр названия оружия		
		std::string Name()const { return name_; }
		/// \brief Гэттэр массы оружия		
		double Weight()const { return weight_; }
	private:	
		std::string name_; // Название оружия
		std::string type_ = "weapon"; // Категория предмета
		double weight_; // Вес оружия
		double damage_; // Наносимый здоровью урон		
		int capacity_; // Ёмкость магазина	
	};
	Hands hands; // Создаём руки игрока, в которые можно будет брать оружие
	
	/*!
		\brief Класс для создания объекта "Голова игрока"
		\details Объект класса добавляется на правах композиции по отношению к классу Player.
		Объект класса реализует слот "Головной убор"
	*/
	class Head {
	public:
		Head():name_("head"),weight_(0),resistance_damage_(0) {} // Конструктор по умолчанию (в слоте "Головной убор" просто головы игрока)	
		~Head() {}
		/// \brief Сэттэр параметров объекта "Голова" (Голова игрока приобретает св-ва головного убора, параметры которого пареданы в сэттэр)
		void SetHeaddress(std::string name, double weight, double resistance) {
			this->name_ = name;
			this->resistance_damage_ = resistance;
			this->weight_ = weight;
		}
		/// \brief Метод удаления головного убора из слота "Головной убор" (Голова игрока становяться просто головой игрока)
		void PopHeaddress() {
			this->name_ = "head";
			this->resistance_damage_ = 0;
			this->weight_ = 0;
		}
		/// \brief Гэттэр названия головного убора
		std::string Name()const { return name_; }
		/// \brief Гэттэр массы головного убора		
		double Weight()const { return weight_; }
		/// \brief Гэттэр сопротивления урону		
		double Resistance()const { return resistance_damage_; }
	private:
		std::string name_; // Название головного убора
		std::string type_ = "headdress"; // Категория предмета
		double weight_; // Вес головного убора
		double resistance_damage_; // Сопротивление урону, которое головной убор даёт игроку
	};
	Head head; // Создаём голову игрока

	/*!
		\brief Класс для создания объекта "Тело игрока"
		\details Объект класса добавляется на правах композиции по отношению к классу Player.
		Объект класса реализует слот "Броня"
	*/
	class Body {
	public:
		Body():name_("body"), resistance_damage_(0), weight_gain_(0), weight_(0) {} // Конструктор по умолчанию (в слоте "Броня" просто тело игрока)	
		~Body() {}
		/// \brief Сэттэр параметров объекта "Ntkj" (Тело игрока приобретает св-ва брони, параметры которого пареданы в сэттэр)
		void SetArmor(std::string name, double resistent, double weigth, int weight_gain) {
			this->resistance_damage_ = resistent;
			this->weight_gain_ = weight_gain;
			this->name_ = name;
			this->weight_ = weigth;
		}
		/// \brief Метод удаления брони из слота "Броня" (Броня игрока становяться просто телом игрока)
		void PopArmor() {
			this->name_ = "body";
			this->resistance_damage_ = 0;
			this->weight_ = 0;
			this->weight_gain_ = 0;
		}
		/// \brief Гэттэр названия брони
		std::string Name()const { return name_; }
		/// \brief Гэттэр массы брони		
		double Weight()const { return weight_; }
		/// \brief Гэттэр дополнительного переносимого веса		
		double WeightGain()const { return weight_gain_; }
		/// \brief Гэттэр сопротивления урону		
		double Resistance()const { return resistance_damage_; }
	private:
		std::string name_; // Название брони
		std::string type_ = "armor"; // Категория предмета
		double weight_; // Вес брони
		double resistance_damage_; // Сопротивление урону, которое броня даёт игроку
		int weight_gain_; // Дополнительная грузоподъёмность
	};
	Body body; // Создаём тело игрока, на которое можно будет надевать броню	
};