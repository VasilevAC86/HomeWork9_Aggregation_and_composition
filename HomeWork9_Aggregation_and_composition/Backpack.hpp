#pragma once
#include"Thing.hpp"

/*!
	\brief Класс для создания объекта "Рюкзак"
	\details Реализован как динамический массив для хранения игровых предметов
*/
class Backpack {
public:
	Backpack() : size_(0),darr_(nullptr),weight_(0){}
	~Backpack() {
		if (darr_) {
			delete[] darr_;
			darr_ = nullptr;
		} 
	}
	Thing* begin()const { return darr_; }
	Thing* end()const { return (darr_ + size_); }
	int size()const { return size_; }
	/// \brief Дружеская функция для расчёта веса рукзака с "e" игровыми предметами
	friend float Weight(Backpack &obj) {
		for (auto& e : obj)
			obj.weight_ += obj.darr_->Weight();
	}
private:
	Thing* darr_; // Указатель на дин. массив игровых предметов
	int size_; // Размер динамического массива игровых предметов	
	float weight_; // Вес рюкзака
};