#pragma once
#include<string>
#include"Thing.hpp"

/*!
	\brief Класс для создания объекта "Рюкзак"
	\details Реализован как динамический массив для хранения игровых предметов
*/

class Backpack {
public:
	Backpack(): darr_weapon_(nullptr), size_weapon_(0), darr_headdress_(nullptr), size_headdress_(0), darr_armor_(nullptr), size_armor_(0), weight_(0) {}
	Backpack(int size, double weight) {
		this->size_weapon_ = size;
		this->size_armor_ = size;
		this->size_headdress_ = size;
		this->weight_ = weight;
		this->darr_armor_ = nullptr;
		this->darr_headdress_ = nullptr;
		this->darr_weapon_ = nullptr;
	}
	~Backpack() {
		if (darr_weapon_) {
			delete[] darr_weapon_;
			darr_weapon_ = nullptr;
		} 
		if (darr_headdress_) {
			delete[] darr_headdress_;
			darr_headdress_ = nullptr;
		}
		if (darr_armor_) {
			delete[] darr_armor_;
			darr_armor_ = nullptr;
		}
	}	
	/// \brief Сэттэр/гэттэр для установки адреса нового оружия в рюкзаке
	void AdressWeapon(Weapon& obj) {
		weight_ += obj.Weight();
		if (darr_weapon_==nullptr) {
			darr_weapon_ = new Weapon[1];
			size_weapon_ = 1;
			darr_weapon_[size_weapon_ - 1] = obj;			
			return;
		}
		Weapon* tmp = new Weapon[size_weapon_ + 1];
		for (int i = 0; i < size_weapon_; ++i) 
			tmp[i] = darr_weapon_[i];					
		tmp[size_weapon_] = obj;		
		++size_weapon_;
		delete[]darr_weapon_;
		darr_weapon_ = tmp;
	}
	Weapon* AdressWeapon()const { return darr_weapon_; }
	Weapon* AdressWeapon(int position) { return (darr_weapon_ + position); }
	/// \brief Метод удаления оружия в рюкзаке
	void PopWeapon(int position) {
		weight_ -= darr_weapon_[position].Weight();
		if (size_weapon_ == 1) {
			delete[]darr_weapon_;
			darr_weapon_ = nullptr;
			size_weapon_ = 0;
			return;
		}
		Weapon* tmp = new Weapon[size_weapon_ - 1];
		for (int i = 0; i < size_weapon_; ++i) {
			if (i < position) 
				tmp[i] = darr_weapon_[i];
			if (i == position)
				continue;
			if (i > position)
				tmp[i - 1] = darr_weapon_[i];
		}
		--size_weapon_;
		delete[]darr_weapon_;
		darr_weapon_ = tmp;
	}
	/// \brief Метод удаления головного убора в рюкзаке
	void PopHeaddress(int position) {
		weight_ -= darr_headdress_[position].Weight();
		if (size_headdress_ == 1) {
			delete[]darr_headdress_;
			darr_headdress_ = nullptr;
			size_headdress_ = 0;
			return;
		}
		Headdress* tmp = new Headdress[size_headdress_ - 1];
		for (int i = 0; i < size_headdress_; ++i) {
			if (i < position)
				tmp[i] = darr_headdress_[i];
			if (i == position)
				continue;
			if (i > position)
				tmp[i - 1] = darr_headdress_[i];
		}
		--size_headdress_;
		delete[]darr_headdress_;
		darr_headdress_ = tmp;		
	}
	/// \brief Метод удаления брони в рюкзаке
	void PopArmor(int position) {
		weight_ -= darr_armor_[position].Weight();
		if (size_armor_ == 1) {
			delete[]darr_armor_;
			darr_armor_ = nullptr;
			size_armor_ = 0;
			return;
		}
		Armor* tmp = new Armor[size_armor_ - 1];
		for (int i = 0; i < size_armor_; ++i) {
			if (i < position)
				tmp[i] = darr_armor_[i];
			if (i == position)
				continue;
			if (i > position)
				tmp[i - 1] = darr_armor_[i];
		}
		--size_armor_;
		delete[]darr_armor_;
		darr_armor_ = tmp;
	}
	/// \brief Сэттэр/гэттэр для установки адреса нового головного убора в рюкзаке
	void AdressHeaddress(Headdress& obj) {
		weight_ += obj.Weight();
		if (!darr_headdress_) {
			darr_headdress_ = new Headdress[1];
			size_headdress_ = 1;
			darr_headdress_[size_headdress_ - 1] = obj;
			return;
		}
		Headdress* tmp = new Headdress[size_headdress_ + 1];
		for (int i = 0; i < size_headdress_; ++i)
			tmp[i] = darr_headdress_[i];
		tmp[size_headdress_] = obj;
		++size_headdress_;
		delete[]darr_headdress_;
		darr_headdress_ = tmp;
	}	
	Headdress* AdressHeaddress()const { return darr_headdress_; }
	Headdress* AdressHeaddress(int position)const { return (darr_headdress_ + position); }
	/// \brief Сэттэр/гэттэр для установки адреса новой брони в рюкзаке
	void AdressArmor(Armor& obj) {
		weight_ = +obj.Weight();
		if (!darr_armor_) {
			darr_armor_ = new Armor[1];
			size_armor_ = 1;
			darr_armor_[size_armor_ - 1] = obj;
			return;
		}
		Armor* tmp = new Armor[size_armor_ + 1];
		for (int i = 0; i < size_armor_; ++i)
			tmp[i] = darr_armor_[i];
		tmp[size_armor_] = obj;
		++size_armor_;
		delete[]darr_armor_;
		darr_armor_ = tmp;
	}
	Armor* AdressArmor()const { return darr_armor_; }
	Armor* AdressArmor(int position)const { return (darr_armor_ + position); }
	int QuantityWeapon()const { return size_weapon_; }
	int QuantityHeaddress()const { return size_headdress_; }
	int QuantityArmor()const { return size_armor_; }	
	/// \brief Гэттэр массы рюкзака
	double Weight()const { return weight_; }
private:
	Weapon* darr_weapon_; // Указатель на дин. массив оружия
	int size_weapon_; // Размер динамического массива оружия
	Headdress* darr_headdress_;
	int size_headdress_;
	Armor* darr_armor_;
	int size_armor_;
	double weight_; // Вес рюкзака
};