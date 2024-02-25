# include <iostream>
#include"Player.hpp"
#include"Backpack.hpp"
#include"Thing.hpp"
#include"Range.hpp"

// Блок исходных глобальных данных

int quantity_weapon = 10; // Переменная для хренения кол-ва оружия
int quantity_headdress = 4; // Переменная для хренения кол-ва головных уборов
int quantity_armor = 4; // Переменная для хренения кол-ва брони

// Динамический массив объектов класса Weapon (Оружие, являющееся насдеником базового класса класса "Thing" - "Игровые предметы")
Weapon* darr_weapon = { new Weapon[quantity_weapon] {
	Weapon("Glok 21", 5.5, 1.33, 12, 50),
	Weapon("Colt 1911", 6.3, 1.75, 8, 75),
	Weapon("AK47", 42.1, 4.2, 30, 175),
	Weapon("AK12", 38.7, 3.9, 30, 225),
	Weapon("Enfield L85A2", 41.1, 5.2, 30, 205),
	Weapon("HK G36", 45.5, 3.6, 30, 310),
	Weapon("Remington 870", 4.8, 8.7, 8, 270),
	Weapon("Franchi SPAS-12", 4.6, 9.8, 8, 375),
	Weapon("Maschinengewerht 42", 12.5, 25.5, 100, 400),
	Weapon("M249 SAW", 11.7, 21.6, 150, 450),
} };

// Динамический массив объектов класса Headdress (Головные уборы, являющееся насдеником базового класса класса "Thing" - "Игровые предметы")
Headdress* darr_headdress = { new Headdress[quantity_headdress] { 
	Headdress("Military helmet", 10.25, 5.4, 200), 
	Headdress("Cap", 0, 0.1, 10), 
	Headdress("Gas mask", 3.2, 2.1, 140), 
	Headdress("Sunglasses", 0, 0.12, 15),
} };

// Динамический массив объектов класса Armor (Броня, являющаяся насдеником базового класса класса "Thing" - "Игровые предметы")
Armor* darr_armor = { new Armor[quantity_armor]{
	Armor("Fashionable suit", 0.55, 5.4, 0, 500),
	Armor("Armored Suit", 12.5, 10.0, 5, 375),
	Armor("Science suit", 8.5, 7.5, 10, 235),
	Armor("Military exoskeleton", 28.9, 15.5, 80, 500),
} };

// Блок прототипов внешних функций

/// \brief Прототип фукнции для вывода в консоль игровых предметов в магазине
void PrintThings();
/// \brief Прототип фукнции для вывода в консоль игровых предметов в рюкзаке	
void PrintBackpack(Backpack const&obj);
/// \brief Прототип функции для покупки игрового предмета 
bool Shopping(Player &player, Backpack &backpack);

int main() {
	Player P("Gunslinger", "Neutral", 0, 80, false); // Создаём игрока		
	// -------------------------- Шаг 1 - Закупка снаряжения ------------------------	
	Backpack B(0,0); // Создаём рюкзак		
	do {
		system("cls");
		PrintThings();
	} while (Shopping(P, B) && P.Money() > 0);
	system("cls");
	PrintThings();
	std::cout << std::endl << "\033[93mThe backpack is full!\033[0m" << std::endl << std::endl;
	PrintBackpack(B);
	// -------------------------- Шаг 2 - Заполенение слотов игрока ------------------------
	std::cout << std::endl << "\033[91mStep 2 - Filling player slots\033[0m" << std::endl;
	int my_choice;
	if (B.AdressWeapon()) {
		std::cout << "Press the number of the weapon you want to take -> ";
		std::cin >> my_choice;
		try {
			if (my_choice > B.QuantityWeapon() || my_choice < 1)
				throw std::exception("\033[91mInput error! There is no thing with this number!\033[0m");
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
			while (my_choice > B.QuantityWeapon() || my_choice < 1) {
				std::cout << "Enter the thing's number one more time -> ";
				std::cin >> my_choice;
			}
		}
		P.SetWeapon(B.AdressWeapon(my_choice-1)->Name(), B.AdressWeapon(my_choice - 1)->Weight(), B.AdressWeapon(my_choice - 1)->Damage(), B.AdressWeapon(my_choice - 1)->Capacity());
		B.PopWeapon(my_choice - 1);		
	}
	if (B.AdressHeaddress()) {
		std::cout << "Press the number of the headdress you want to take -> ";
		std::cin >> my_choice;
		try {
			if (my_choice > B.QuantityHeaddress() || my_choice < 1)
				throw std::exception("\033[91mInput error! There is no thing with this number!\033[0m");
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
			while (my_choice > B.QuantityHeaddress() || my_choice < 1) {
				std::cout << "Enter the thing's number one more time -> ";
				std::cin >> my_choice;
			}
		}
		P.SetHeaddress(B.AdressHeaddress(my_choice - 1)->Name(), B.AdressHeaddress(my_choice - 1)->Weight(), B.AdressHeaddress(my_choice - 1)->Resistance());
		B.PopHeaddress(my_choice - 1);
	}
	if (B.AdressArmor()) {
		std::cout << "Press the number of the armor you want to take -> ";
		std::cin >> my_choice;
		try {
			if (my_choice > B.QuantityArmor() || my_choice < 1)
				throw std::exception("\033[91mInput error! There is no thing with this number!\033[0m");
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
			while (my_choice > B.QuantityArmor() || my_choice < 1) {
				std::cout << "Enter the thing's number one more time -> ";
				std::cin >> my_choice;
			}
		}
		P.SetArmor(B.AdressArmor(my_choice - 1)->Name(), B.AdressArmor(my_choice - 1)->Resistance(), B.AdressArmor(my_choice - 1)->Weight(), B.AdressArmor(my_choice - 1)->Weight_gain());
		B.PopArmor(my_choice - 1);
	}
	std::cout << std::endl;
	// -------------------------- Шаг 3 - Итоговые характеристики игрока и его рюкзака ------------------------
	std::cout << std::endl << "\033[91mStep 3 - Conclusion\033[0m" << std::endl;
	PrintBackpack(B);
	std::cout << std::endl << "The player by name \033[92m" << P.Name() << "\033[0m from the group \033[92m" << P.Group() \
		<< "\033[0m consists of:\033[0m\nWeapon: \033[93m" << P.NameWeapon() << "\033[0m\nHeaddress: \033[93m" << P.NameHead()<< "\033[0m\nArmor: \033[93m"\
		<< P.NameArmor() << "\033[0m\nWeight of things on the player is \033[93m" << P.Weight() << "\033[0m\nThe player can carry \033[93m"	<< P.WeightGain() \
		<< "\033[0m kg and has damage resistance \033[93m" << P.Resistance() << "\033[0m"  << std::endl;
	
	// Чистим память от глобальных динамических массивов и переводи указатели на нейтральные статусы
	delete[]darr_weapon;
	darr_weapon = nullptr;
	delete[]darr_headdress;
	darr_headdress = nullptr;
	delete[]darr_armor;
	darr_armor = nullptr;

	return 0;
}

void PrintThings() {
	std::cout << "\033[91mStep 1 - Purchasing things\033[0m" << std::endl << "\033[93mYou can buy the following things:\033[0m";	
	int counter = 0;
	std::cout << std::endl << "\033[96mWeapon:\033[0m" << std::endl;
	Range<Weapon> R1(darr_weapon, quantity_weapon);
	for (auto& e : R1) {		
		++counter;
		std::cout << counter << ". " << e << std::endl;
	}
	R1.~Range();
	Range<Headdress> R2(darr_headdress, quantity_headdress);
	std::cout << "\033[96mHeaddress:\033[0m" << std::endl;
	for (auto& e : R2) {
		++counter;
		std::cout << counter << ". " << e << std::endl;
	}
	R2.~Range();
	std::cout << "\033[96mArmor:\033[0m" << std::endl;
	Range<Armor>R3(darr_armor, quantity_armor);
	for (auto& e : R3) {
		++counter;
		std::cout << counter << ". " << e << std::endl;
	}
}

void PrintBackpack(Backpack const& obj) {	
	std::cout << "The following things are in your backpack:" << std::endl;
	if (obj.AdressWeapon()) {
		std::cout << "\033[96mWeapon:\033[0m" << std::endl;
		Range<Weapon> R1(obj.AdressWeapon(), obj.QuantityWeapon());
		for (auto& e : R1) {
			++R1.counter_;
			std::cout << R1.counter_ << ". " << e << std::endl;
		}
		R1.~Range();
	}	
	if (obj.AdressHeaddress()) {
		std::cout << "\033[96mHeaddress:\033[0m" << std::endl;
		Range<Headdress> R2(obj.AdressHeaddress(), obj.QuantityHeaddress());
		for (auto& e : R2) {
			++R2.counter_;
			std::cout << R2.counter_ << ". " << e << std::endl;
		}
		R2.~Range();
	}
	if (obj.AdressArmor()) {
		std::cout << "\033[96mArmor:\033[0m" << std::endl;
		Range<Armor> R3(obj.AdressArmor(), obj.QuantityArmor());
		for (auto& e : R3) {
			++R3.counter_;
			std::cout << R3.counter_ << ". " << e << std::endl;
		}
		R3.~Range();
	}
	std::cout << std::endl << "Backpack weight \033[92m" << obj.Weight() << "\033[0m kg" << std::endl;
}


bool Shopping(Player& player, Backpack& backpack) {
	int my_choice; // Переменная для хранения выбора пользователя
	std::cout << std::endl << "You have \033[92m" << player.Money() << "\033[0m rubles" << std::endl\
		<< "If you want to buy something press its number (from '1' to '" << quantity_weapon + quantity_headdress + quantity_armor \
		<< "')\nIf you have purchased everything you need press '0'" << std::endl << "Your choice -> ";
	std::cin >> my_choice;
	if (my_choice == 0)
		return false;
	try {
		if (my_choice > quantity_weapon + quantity_headdress + quantity_armor || my_choice < 1)
			throw std::exception("\033[91mInput error! There is no thing with this number!\033[0m");
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		while (my_choice > quantity_weapon + quantity_headdress + quantity_armor || my_choice < 1) {
			std::cout << "Enter the thing's number one more time -> ";
			std::cin >> my_choice;
		}
	}	
	if (my_choice <= quantity_weapon) {		
		if (player.Money() < darr_weapon[my_choice - 1].Price()) {
			std::cout << "\033[91mNot enough money to buy\033[0m" << std::endl;
			system("pause");
			return true;
		}
		backpack.AdressWeapon(darr_weapon[my_choice - 1]);
		player.Money(darr_weapon[my_choice - 1].Price());
		if (quantity_weapon - 1) { // Если в дин.массиве что-то ещё есть
			Weapon* tmp = new Weapon[quantity_weapon - 1];
			for (int i = 0; i < quantity_weapon; ++i) {
				if (i < my_choice - 1)
					tmp[i] = darr_weapon[i];
				if (i == my_choice - 1) {
					darr_weapon[i].~Weapon();
					continue;
				}
				if (i > my_choice - 1)
					tmp[i - 1] = darr_weapon[i];
			}
			quantity_weapon--;
			delete[]darr_weapon;
			darr_weapon = tmp;
			return true;
		}
		quantity_weapon = 0;
		delete[]darr_weapon;
		darr_weapon = nullptr;
	}
	if (my_choice > quantity_weapon && my_choice <= (quantity_weapon + quantity_headdress)) {		
		if (player.Money() < darr_headdress[my_choice - quantity_weapon - 1].Price()) {
			std::cout << "\033[91mNot enough money to buy\033[0m" << std::endl;
			system("pause");
			return true;
		}
		backpack.AdressHeaddress(darr_headdress[my_choice - quantity_weapon - 1]);
		player.Money(darr_headdress[my_choice - quantity_weapon - 1].Price());
		if (quantity_headdress - 1) { // Если в дин.массиве что-то ещё есть
			Headdress* tmp = new Headdress[quantity_headdress - 1];
			for (int i = 0; i < quantity_headdress; ++i) {
				if (i < my_choice - quantity_weapon - 1)
					tmp[i] = darr_headdress[i];
				if (i == my_choice - quantity_weapon - 1)
					continue;
				if (i > my_choice - quantity_weapon - 1)
					tmp[i - 1] = darr_headdress[i];
			}
			quantity_headdress--;
			delete[]darr_headdress;
			darr_headdress = tmp;
			return true;
		}
		quantity_headdress = 0;
		delete[]darr_headdress;
		darr_headdress = nullptr;	
	}
	if (my_choice > (quantity_weapon + quantity_headdress)) {		
		if (player.Money() < darr_armor[my_choice - quantity_weapon - quantity_headdress - 1].Price()) {
			std::cout << "\033[91mNot enough money to buy\033[0m" << std::endl;
			system("pause");
			return true;
		}
		backpack.AdressArmor(darr_armor[my_choice - quantity_weapon - quantity_headdress - 1]);
		player.Money(darr_armor[my_choice - quantity_weapon - quantity_headdress - 1].Price());
		if (quantity_armor - 1) { // Если в дин.массиве что-то ещё есть
			Armor* tmp = new Armor[quantity_armor - 1];
			for (int i = 0; i < quantity_armor; ++i) {
				if (i < my_choice - quantity_weapon - quantity_headdress - 1)
					tmp[i] = darr_armor[i];
				if (i == my_choice - quantity_weapon - quantity_headdress - 1)
					continue;
				if (i > my_choice - quantity_weapon - quantity_headdress - 1)
					tmp[i - 1] = darr_armor[i];
			}
			quantity_armor--;
			delete[]darr_armor;
			darr_armor = tmp;
			return true;
		}
		quantity_armor = 0;
		delete[]darr_armor;
		darr_armor = nullptr;
	}	
}

